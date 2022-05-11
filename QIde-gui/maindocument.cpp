#include "maindocument.h"
#include "syntax/JavaHighlighter.h"
#include "LineNumberArea.h"

MainDocument::MainDocument(QWidget *parent)
    : QPlainTextEdit{parent},title(""),path("")
{
    lineNumberArea=new LineNumberArea(this);
    highlighter = new syntax::JavaHighlighter(this->document());
    connect(this->document(), &QTextDocument::modificationChanged, this, &MainDocument::documentWasModified);
    connect(this, &MainDocument::blockCountChanged, this, &MainDocument::updateLineNumberAreaWidth);
    connect(this, &MainDocument::updateRequest, this, &MainDocument::updateLineNumberArea);
    connect(this, &MainDocument::cursorPositionChanged, this, &MainDocument::highlightCurrentLine);

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}

QString MainDocument::getTitle() {
    return this->title;
}

void MainDocument::setTitle(QString title) {
    this -> title = title;
}


QString MainDocument::getPath() {
    return this->path;
}

void MainDocument::setPath(QString path) {
    this->path = path;
    QStringList list = path.split("/");
    this->setTitle(list[list.size()-1]);
}

// --------------------------------- Slots -------------------------------

bool MainDocument::save() {
    if (this->path.isEmpty()) {
        return saveAs();
    }
    else {
        return saveFile(this->path);
    }
}

bool MainDocument::saveAs() {
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.selectFile(this->title);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    QString path = dialog.selectedFiles().first();
    return saveFile(path);
}

bool MainDocument::saveFile(QString path) {
    QString errorMessage;

    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    QSaveFile file(path);
    if (file.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&file);
        out << this->toPlainText();
        if (!file.commit()) {
            errorMessage = tr("Cannot write file %1:\n%2.")
                           .arg(QDir::toNativeSeparators(path), file.errorString());
        }
    } else {
        errorMessage = tr("Cannot open file %1 for writing:\n%2.")
                       .arg(QDir::toNativeSeparators(path), file.errorString());
    }
    QGuiApplication::restoreOverrideCursor();

    if (!errorMessage.isEmpty()) {
        QMessageBox::warning(this, tr("Application"), errorMessage);
        return false;
    }
    this->setPath(path); // this will modify the title also
    this->document()->setModified(false);// return the document to unmodified state

    emit currentTitlechanged(this->title, this);
    emit documentModifState(false, this);

    return true;
}

void MainDocument::documentWasModified() {
    emit documentModifState(this->document()->isModified(), this);
}

// ------------------------------------------------------------------------


// Ask the User to Save unsaved changes before proceeding
bool MainDocument::maybeSave() {
    if (!this->document()->isModified()) {
        return true;
    }

    const QMessageBox::StandardButton message = QMessageBox::warning(this, tr("Application"), tr("Do you want to save changes of ")+QString("<b>%1</b> ?").arg(this->title), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (message) {
        case QMessageBox::Save : return this->save();
        case QMessageBox::Cancel : return false;
        default: break;
    }
    return true;
}

void MainDocument::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);
    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}


int MainDocument::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space;
}

void MainDocument::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void MainDocument::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

void MainDocument::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(128,128,128,32);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

void MainDocument::lineNumberAreaPaintEvent(QPaintEvent *event) {
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + qRound(blockBoundingRect(block).height());
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + qRound(blockBoundingRect(block).height());
        ++blockNumber;
    }

}
