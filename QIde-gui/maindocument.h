#ifndef MAINDOCUMENT_H
#define MAINDOCUMENT_H

#include <QtWidgets>
#include <QSyntaxHighlighter>


class MainDocument : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit MainDocument(QWidget *parent = nullptr);

    QString getTitle();
    void setTitle(QString title);

    QString getPath();
    void setPath(QString path);

    bool maybeSave();

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

public slots:
    bool save();// if no file is already open we do a saveAs(), otherwise saveFile()
    bool saveAs();
    void resizeEvent(QResizeEvent *e) override;
public slots:
    void documentWasModified();


private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &rect, int dy);

private:
    QString title;
    QString path;
    QSyntaxHighlighter *highlighter;
    bool saveFile(QString path);
    QWidget *lineNumberArea;


signals:
    void documentModifState(bool modifState, MainDocument* document);
    void currentTitlechanged(QString title, MainDocument* document);
};

#endif // MAINDOCUMENT_H
