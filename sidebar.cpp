#include "sidebar.h"

Sidebar::Sidebar(QWidget *parent, QFileIconProvider* iconProvider)
    : QDockWidget{tr("Explorer"), parent}
{
    this->initExplorer(iconProvider);
    this->setFeatures(QDockWidget::NoDockWidgetFeatures);
    this->setFloating(false);
    this->setAllowedAreas(Qt::LeftDockWidgetArea);
    connect(this->tree, &QTreeView::activated, this, &Sidebar::openFileRequest);

}

void Sidebar::initExplorer(QFileIconProvider* iconProvider) {

    QTreeView* tree = new QTreeView(this);
    QFileSystemModel* model = new QFileSystemModel(tree);
    model->setIconProvider(iconProvider);
    tree->setModel(model);

    // Setting the root path
    QString rootPath = QDir::currentPath();
    model->setRootPath(rootPath);
    tree->setRootIndex(model->index(rootPath));

    // removing unecessary columns from View
    for (int col=1;col<model->columnCount();col++ ) {
        tree->hideColumn(col);
    }

    // Styling
    tree->setMaximumWidth(this->parentWidget()->width() / 2);
    tree->setHeaderHidden(true); // hide header

    // Wiring to parent
    this->setWidget(tree);
    this->tree = tree ;
}

QTreeView* Sidebar::getTree() {
    return this->tree;
}

// --------------Slots--------------------------------
void Sidebar::openFolder() {
    QString path=QFileDialog::getExistingDirectory(this);
    this->changeCurrentDir(path);
}

void Sidebar::openFileRequest( QModelIndex index) {
    QFileSystemModel* model = (QFileSystemModel*)this->tree->model();
    if (!model->isDir(index)) { // if it's not a directory, open it
        emit this->fileOpened(model->filePath(index), model->fileIcon(index));
    }
}

// ---------------------------------------------------
void Sidebar::changeCurrentDir(QString path) {
    QFileSystemModel* model = (QFileSystemModel*)this->tree->model();
    model->setRootPath(path);
    this->tree->setRootIndex(model->index(path));
}
