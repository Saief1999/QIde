#include "tabholder.h"

TabHolder::TabHolder(QWidget *parent, QFileIconProvider* provider)
    : QTabWidget{parent}, iconProvider(provider)
{
    this->setTabsClosable(true);
    this->setDocumentMode(true);
    connect(this, &TabHolder::tabCloseRequested, [this](int index) {
        this->handleTabCloseRequest(index);
    });

}

void TabHolder::addNewTab() {
    // configuring the document
    MainDocument* document = new MainDocument();
    document->setTitle(this->findFreeDefaultName());

    // wiring
    int index = this->addTab(document,QIcon::fromTheme("text-plain"),document->getTitle());
    connect(document, &MainDocument::documentModifState, this, &TabHolder::changeTabModifState);
    connect(document, &MainDocument::currentTitlechanged, this, &TabHolder::changeTabTitle);
    this->setCurrentIndex(index);

    if (this->count() == 1) emit documentExists(true);
}

// I have no idea if this is the right way, but it seems to be working...
// Finds an available default name Starting by "Untitled-1" while checking the other tabs for availability each time
QString TabHolder::findFreeDefaultName() {
    QString defaultName = tr("Untitled")+"-";
    QMap<int, QString> map;

    for (int index=0 ; index<this->count(); index++) {
        QString name = ((MainDocument*)this->widget(index))->getTitle();
        int initialSize = name.size();
        name.remove(QRegularExpression("^"+defaultName));
//        if (name.endsWith("*")) name.truncate(name.size()-1);
        if (name.size() == initialSize - defaultName.size()) { // if we found exactly one occurence of "Untitled-" at the start of the string
            bool ok;
            int number = name.toInt(&ok);
            if (ok) map.insert(number, ((MainDocument*)this->widget(index))->getTitle()); // if our second segment is a number we insert it to our Map
        }
    }
    int number = 1;
    while (true) {
        if (!map.contains(number))  break;
        number ++;
    }
    return QString("%1%2").arg(defaultName).arg(number);
}

void TabHolder::openFileTab() {

    // getting the file
    QString path=QFileDialog::getOpenFileName(this);
    if (!path.isEmpty()) {
        QFileInfo fileInfo(path);
        QIcon icon = this->iconProvider->icon(fileInfo);
        this->loadFile(path, icon);
        if (this->count() == 1) emit documentExists(true);
    }

}

void TabHolder::loadFile(QString path, QIcon icon) {

    // We check whether the file is already open
    for (int index = 0 ; index<this->count() ; index++) {
        if (((MainDocument*)this->widget(index))->getPath() == path) {
            this->setCurrentIndex(index);
            return;
        }
    }


    QFile file(path);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(path), file.errorString()));
        return;
    }
    QTextStream in(&file);

    // configuring the document
    MainDocument* document = new MainDocument();
    document->setPlainText(in.readAll());
    document->setPath(path); // this will modify the title also

    // wiring
    int index = this->addTab(document, icon, document->getTitle());
    connect(document, &MainDocument::documentModifState, this, &TabHolder::changeTabModifState);
    connect(document, &MainDocument::currentTitlechanged, this, &TabHolder::changeTabTitle);
    this->setCurrentIndex(index);
}

bool TabHolder::saveTab() {
    return ((MainDocument*)this->currentWidget())->save();
}

bool TabHolder::saveTabAs() {
    return ((MainDocument*)this->currentWidget())->saveAs();
}

bool TabHolder::saveAllTabs() {
    for (int index=0; index<this->count(); index++) {
        if (!((MainDocument*)this->widget(index))->save())
            return false;
    }
    return true;
}

void TabHolder::changeTabTitle(QString title, MainDocument* document) {
    this->setTabText(this->indexOf(document), title);
}

void TabHolder::changeTabModifState(bool modifState, MainDocument *document) {
    int index = this->indexOf(document);
    QString text = this->tabText(index);

    if (modifState) {
        if (!text.endsWith("*")) {
            this->setTabText(index, text+"*");
        }
    }
    else {
        if (text.endsWith("*")) {
            text.truncate(text.size()-1);
            this->setTabText(index, text);
        }
    }
}

bool TabHolder::handleTabCloseRequest(int index) {
    MainDocument* document = (MainDocument*)this->widget(index);
    if (document->maybeSave()) {
        this->removeTab(index);
        if (this->count() == 0) emit documentExists(false);
        return true;
    }
    return false;
}

bool TabHolder::handleCloseAll() {
    int count = this->count();
    int index = 0 ;
    while (index <this->count()) {
        if (!this->handleTabCloseRequest(index)) { // close event stopped
            return false;
        }
        if (this->count() < count) { // tab removed -> count will decrement
            count = this->count() ;
        }
        else {
            index ++ ;
        }
    }

    return true;
}
