#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include "compileoutput.h"
#include <QtWidgets>

class Bottombar : public QDockWidget
{
    Q_OBJECT
public:
    explicit Bottombar(QWidget *parent = nullptr);

public slots:
    void compileRequest(QString path);
private:
   CompileOutput* compileOutput;
signals:

};

#endif // BOTTOMBAR_H
