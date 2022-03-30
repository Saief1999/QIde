#include "bottombar.h"

Bottombar::Bottombar(QWidget *parent)
    : QDockWidget{tr("Output"),parent}
{
    this->setFeatures(QDockWidget::DockWidgetClosable);
    this->setFloating(false);
    this->setAllowedAreas(Qt::BottomDockWidgetArea);
    this->setVisible(false);

    this->compileOutput = new CompileOutput(this);
    this->setWidget(compileOutput);
}

void Bottombar::compileRequest(QString path) {
    this->setVisible(true);
    this->compileOutput->runCompilation(path);
}
