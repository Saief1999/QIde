#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "maindocument.h"
#include "sidebar.h"
#include "bottombar.h"
#include "tabholder.h"
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QFileIconProvider* iconProvider; // will be used to get icons

public slots:
    void toggleDocumentOperations(bool exists);

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void createMenuBar();
    void createStatusBar();

    Sidebar* sideBar;
    Bottombar* bottomBar;
    TabHolder* tabHolder;
    QList<QAction*> saveMenuActions;
    QList<QAction*> buildMenuActions;

};
#endif // MAINWINDOW_H
