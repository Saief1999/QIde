#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QtWidgets>

class Sidebar : public QDockWidget
{
    Q_OBJECT
public:
    explicit Sidebar(QWidget *parent = nullptr, QFileIconProvider* iconProvider = new QFileIconProvider());
    QTreeView* getTree();

public slots:
    void openFolder();
    void openFileRequest(QModelIndex index);

private:
    void initExplorer(QFileIconProvider* iconProvider);
    QTreeView* tree;
    void changeCurrentDir(QString path);
signals:
    void fileOpened(QString path, QIcon icon);

};

#endif // SIDEBAR_H
