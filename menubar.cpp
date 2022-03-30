#include "mainwindow.h"

void MainWindow::createMenuBar() {

    // ---------------------- File Menu ---------------------------
    QMenu* fileMenu = this->menuBar()->addMenu(tr("File"));

    const QIcon newIcon = QIcon::fromTheme("document-new");
    QAction* newAction = new QAction(newIcon, tr("New"), this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new file"));
    fileMenu->addAction(newAction); // ensures this pointer is deleted when its parent is deleted [ See Qt Parent child relationship ]
    connect(newAction, &QAction::triggered, this->tabHolder, &TabHolder::addNewTab);


    const QIcon openFileIcon = QIcon::fromTheme("document-open");
    QAction* openFileAction = new QAction(openFileIcon, tr("Open File..."), this);
    openFileAction->setShortcut(QKeySequence::Open);
    openFileAction->setStatusTip(tr("Open an existing file"));
    fileMenu->addAction(openFileAction);
    connect(openFileAction, &QAction::triggered,this->tabHolder, &TabHolder::openFileTab);

    const QIcon openFolderIcon = QIcon::fromTheme("document-open");//to change
    QAction* openFolderAction = new QAction(openFolderIcon, tr("Open Folder..."), this);
    openFolderAction->setStatusTip(tr("Open an existing folder"));
    fileMenu->addAction(openFolderAction);
    connect(openFolderAction, &QAction::triggered,[this] {
        this->sideBar->openFolder();
        this->tabHolder->clear();
    });

    const QIcon saveIcon = QIcon::fromTheme("document-save");
    QAction* saveAction = new QAction(saveIcon, tr("Save"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the document to disk"));
    fileMenu->addAction(saveAction);
    connect(saveAction, &QAction::triggered, this->tabHolder, &TabHolder::saveTab);
    this->saveMenuActions.append(saveAction);

    const QIcon saveAsIcon = QIcon::fromTheme("document-save-as");
    QAction* saveAsAction = new QAction(saveAsIcon, tr("Save As..."), this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save the document under a new name"));
    fileMenu->addAction(saveAsAction);
    connect(saveAsAction, &QAction::triggered, this->tabHolder, &TabHolder::saveTabAs);
    this->saveMenuActions.append(saveAsAction);

    const QIcon saveAllIcon = QIcon::fromTheme("document-save-all");
    QAction* saveAllAction = new QAction(saveAllIcon, tr("Save All"));
    saveAllAction->setShortcut(QKeySequence("Ctrl+Shift+S"));
    saveAllAction->setStatusTip(tr("Save all documents to disk"));
    fileMenu->addAction(saveAllAction);
    connect(saveAllAction, &QAction::triggered,this->tabHolder, &TabHolder::saveAllTabs);
    fileMenu->addSeparator();
    this->saveMenuActions.append(saveAllAction);

    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction* exitAction = new QAction(exitIcon, tr("Exit"));
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application"));
    fileMenu->addAction(exitAction);
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);


    // TODO : Fix Edit actions to enable them only when they are available
    // ---------------------- Edit Menu ---------------------------

    QMenu* editMenu = this->menuBar()->addMenu(tr("Edit"));

    const QIcon undoIcon = QIcon::fromTheme("edit-undo");
    QAction* undoAction = new QAction(undoIcon, "Undo", this);
    undoAction->setShortcut(QKeySequence::Undo);
    undoAction->setStatusTip(tr("Undo latest changes"));
    undoAction->setEnabled(false);
    connect(undoAction, &QAction::triggered, [this] {
        ((MainDocument*)this->tabHolder->currentWidget())->undo();
    });
//    connect(this->mainDocument, &MainDocument::undoAvailable, undoAction, &QAction::setEnabled);
    editMenu->addAction(undoAction);

    const QIcon redoIcon = QIcon::fromTheme("edit-redo");
    QAction* redoAction = new QAction(redoIcon, "Redo", this);
    redoAction->setShortcut(QKeySequence::Redo);
    redoAction->setStatusTip(tr("Redo previous changes"));
    redoAction->setEnabled(false);
    connect(redoAction, &QAction::triggered,[this] {
        ((MainDocument*)this->tabHolder->currentWidget())->redo();
    });
//    connect(this->mainDocument, &MainDocument::redoAvailable, redoAction, &QAction::setEnabled);
    editMenu->addAction(redoAction);

    editMenu->addSeparator();

    const QIcon cutIcon = QIcon::fromTheme("edit-cut");
    QAction* cutAction = new QAction(cutIcon, "Cut", this);
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut to clipboard"));
    cutAction->setEnabled(false);
    connect(cutAction, &QAction::triggered, [this] {
        ((MainDocument*)this->tabHolder->currentWidget())->cut();
    });
//    connect(this->mainDocument, &MainDocument::copyAvailable, cutAction, &QAction::setEnabled);
    editMenu->addAction(cutAction);


    const QIcon copyIcon = QIcon::fromTheme("edit-copy");
    QAction* copyAction = new QAction(copyIcon, tr("Copy"), this);
    copyAction->setShortcuts(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy to clipboard"));
    copyAction->setEnabled(false);
    connect(copyAction, &QAction::triggered, [this] {
        ((MainDocument*)this->tabHolder->currentWidget())->copy();
    });
//    connect(this->mainDocument, &MainDocument::copyAvailable, copyAction, &QAction::setEnabled);
    editMenu->addAction(copyAction);


    const QIcon pasteIcon = QIcon::fromTheme("edit-paste");
    QAction* pasteAction = new QAction(pasteIcon, tr("Paste"), this);
    pasteAction->setShortcuts(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the clipboard's contents into the current selection"));
    connect(pasteAction, &QAction::triggered, [this] {
        ((MainDocument*)this->tabHolder->currentWidget())->paste();
    });
    editMenu->addAction(pasteAction);

    editMenu->addSeparator();

    const QIcon selectAllIcon = QIcon::fromTheme("edit-select-all");
    QAction* selectAllAction = new QAction(selectAllIcon, tr("Select All"), this);
    selectAllAction->setShortcuts(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select the whole document"));
    connect(selectAllAction, &QAction::triggered, [this] {
        ((MainDocument*)this->tabHolder->currentWidget())->selectAll();
    });
    editMenu->addAction(selectAllAction);


    // ---------------------- Build Menu ---------------------------
    QMenu* buildMenu = menuBar()->addMenu(tr("Build"));

    QAction *compileAction = new QAction(tr("Compile"), this);
    compileAction->setShortcut(QKeySequence("Ctrl+B"));
    compileAction->setStatusTip(tr("Compile this document"));
    buildMenu->addAction(compileAction);
    connect(compileAction, &QAction::triggered, [this] {
        MainDocument* currentDocument = (MainDocument*)this->tabHolder->currentWidget();
        if (currentDocument->getPath().isEmpty()) {
            QMessageBox::warning(this, tr("Application"), "Cannot compile file: file not saved in disk yet");
        }
        else {
            this->bottomBar->compileRequest(currentDocument->getPath());
        }
    });

    this->buildMenuActions.append(compileAction);


    // ---------------------- Help Menu ---------------------------
    QMenu* helpMenu = menuBar()->addMenu(tr("Help"));

    QAction* aboutAction = new QAction(tr("About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, &QAction::triggered, [this]() {
        QMessageBox::about(this, tr("About Application"),
                 tr("<b>QIde</b> is an integrated development environment built using Qt."));
    });
    helpMenu->addAction(aboutAction);

    QAction* contactAction = new QAction(tr("Contact"), this);
    contactAction->setStatusTip(tr("Show contact information of developers"));
    helpMenu->addAction(contactAction);
    connect(contactAction, &QAction::triggered, [this]() {
        QMessageBox::information(this, tr("Contact..."),
                 tr("<b>QIde</b> developers can be reached out via these emails:")
                    +"<br><br>saief_zaneti@yahoo.com"
                    +"<br><br>zouarirami@idontknow.com"
                    );
    });
}

void MainWindow::toggleDocumentOperations(bool exists) {
    for (auto action:this->saveMenuActions) {
       action->setEnabled(exists);
    }
    for (auto action:this->buildMenuActions) {
        action->setEnabled(exists);
    }
}
