#ifndef COMPILEOUTPUT_H
#define COMPILEOUTPUT_H

#include <QtWidgets>

class CompileOutput : public QTextEdit
{
    Q_OBJECT
public:
    explicit CompileOutput(QWidget *parent = nullptr);

public slots:
    bool runCompilation(QString path); // compile a file at a certain path

signals:
};

#endif // COMPILEOUTPUT_H
