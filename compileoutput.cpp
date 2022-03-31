#include "compileoutput.h"
#include <QDebug>
#include <cstdio>
#include "gen/java_lexer.c"
#include "gen/java_parser.c"
extern FILE* yyin;
extern FILE* yyout;

constexpr int  MAX_ERR_SIZE = 1<<20;

CompileOutput::CompileOutput(QWidget *parent)
    : QTextEdit{parent}
{
    this->setReadOnly(true);
}

bool CompileOutput::runCompilation(QString path) {
    if(!runParser(path))
    {
        setMarkdown(toPlainText()+tr(R"(
<span style="color:red">**Build failed**</span>)"));
        return false;
    }
    /*
     * Only to debug parser
    */
    else{
        setMarkdown(tr(R"(<span style="color:green">**Build is successful**</span>)"));
        return true;
    }
    QString program = "javac";
    QStringList arguments;
    arguments << path;

    QProcess* process = new QProcess(this);
    process->start(program, arguments);
    qDebug() << program << " "<< arguments;
    if (!process->waitForFinished()) // This is blocking and needs to be called within a thread
    {
        this->setText(tr("Blocking Error"));
        return false;
    }
    QString output = process->readAllStandardError();
    if (output.isEmpty()) { // no errors
        output = "Program compiled successfully.";
    }
    this->setText(output);
    return true;
}

/*
 * TODO: Configure Bison & Flex to generate C++ code
*/
bool CompileOutput::runParser(QString path)
{
    FILE *file=fopen(path.toStdString().c_str(),"r"),*tmpFile=tmpfile64();
    char errOut[MAX_ERR_SIZE];
    if(file && tmpFile)
    {
        yyin=file;
        yyout=tmpFile;
        yyparse();
        bool err=build_success;
        reset_all();
        qDebug() << "Finished Parsing";
        rewind(yyout);
        fgets(errOut,MAX_ERR_SIZE,yyout);
        setText(errOut);
        yylex_destroy();
        return err;
    }
    return false;
}

