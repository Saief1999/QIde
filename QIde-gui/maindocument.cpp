#include "maindocument.h"
#include "syntax/JavaHighlighter.h"

MainDocument::MainDocument(QWidget *parent)
    : QTextEdit{parent},title(""),path("")
{
    highlighter = new syntax::JavaHighlighter(this->document());
    connect(this->document(), &QTextDocument::modificationChanged, this, &MainDocument::documentWasModified);
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
