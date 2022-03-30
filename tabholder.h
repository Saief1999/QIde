#ifndef TABHOLDER_H
#define TABHOLDER_H

#include "maindocument.h"
#include <QtWidgets>

// -------------Main Widget-------------------
class TabHolder : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabHolder(QWidget *parent = nullptr, QFileIconProvider* provider = new QFileIconProvider());
    bool handleCloseAll();

public slots:
    // Empty file Tab
    void addNewTab();

    // Opens a file
    void openFileTab();

    // loads a file after choosing it
    void loadFile(QString path, QIcon icon);

    bool saveTab();

    bool saveTabAs();

    bool saveAllTabs();

    void changeTabTitle(QString title, MainDocument* document);

    void changeTabModifState(bool modifState, MainDocument* document);

    bool handleTabCloseRequest(int index);

private:
    QString findFreeDefaultName();
    QFileIconProvider* iconProvider;

signals:
    void documentExists(bool exists);
};

#endif // TABHOLDER_H
