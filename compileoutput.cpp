#include "compileoutput.h"
#include <QDebug>
CompileOutput::CompileOutput(QWidget *parent)
    : QTextEdit{parent}
{
    this->setReadOnly(true);
}

bool CompileOutput::runCompilation(QString path) {
    QString program = "javac";
    QStringList arguments;
    arguments << path;

    QProcess* process = new QProcess(this);
    process->start(program, arguments);
    qDebug() << program << " "<< arguments;
    if (!process->waitForFinished()) // This is blocking and needs to be called within a thread
             return false;
    QString output = process->readAllStandardError();
    if (output.isEmpty()) { // no errors
        output = "Program compiled successfully.";
    }
    this->setText(output);
    return true;
}

