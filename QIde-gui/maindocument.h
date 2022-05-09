#ifndef MAINDOCUMENT_H
#define MAINDOCUMENT_H

#include <QtWidgets>
#include <QSyntaxHighlighter>


class MainDocument : public QTextEdit
{
    Q_OBJECT
public:
    explicit MainDocument(QWidget *parent = nullptr);

    QString getTitle();
    void setTitle(QString title);

    QString getPath();
    void setPath(QString path);

    bool maybeSave();


public slots:
    bool save();// if no file is already open we do a saveAs(), otherwise saveFile()
    bool saveAs();

public slots:
    void documentWasModified();
private:
    QString title;
    QString path;
    QSyntaxHighlighter *highlighter;
    bool saveFile(QString path);

signals:
    void documentModifState(bool modifState, MainDocument* document);
    void currentTitlechanged(QString title, MainDocument* document);
};

#endif // MAINDOCUMENT_H
