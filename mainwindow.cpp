#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Window Styles
    this->resize(this->screen()->availableGeometry().size()/1.4);

    // Icon provider
    this->iconProvider = new QFileIconProvider();


    // Tab Holder
    this->tabHolder = new TabHolder(this, iconProvider);
    this->setCentralWidget(tabHolder);
    connect(this->tabHolder, &TabHolder::documentExists, this, &MainWindow::toggleDocumentOperations);
    this->tabHolder->addNewTab();


    // Bottom Bar
    this->bottomBar = new Bottombar(this);
    this->addDockWidget(Qt::BottomDockWidgetArea, this->bottomBar);

    // Menu Bar
    this->createMenuBar();
    this->setWindowTitle("QIde");

    // Sidebar
    this->sideBar = new Sidebar(this, iconProvider);
    this->addDockWidget(Qt::LeftDockWidgetArea, this->sideBar);
    connect(this->sideBar, &Sidebar::fileOpened, this->tabHolder, &TabHolder::loadFile);


    // Status Bar
    this->createStatusBar();
}

MainWindow::~MainWindow()
{
}


void MainWindow::createStatusBar() {
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::closeEvent(QCloseEvent *event){
    if (this->tabHolder->handleCloseAll()) {
        event->accept();
    } else {
        event->ignore();
    }
}
