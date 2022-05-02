#include "compileoutput.h"
#include <QDebug>
#include <cstdio>
#include "QIde-core/driver.hh"
#include <iostream>
#include <fstream>
//extern "C"
//{
//#include "gen/java_parser.h"
//#include "gen/java_lexer.h"
//extern bool build_success;
//void reset_all();
//}
//constexpr int  MAX_ERR_SIZE = 1<<20,MAX_ERR_LINE=256;

CompileOutput::CompileOutput(QWidget *parent)
    : QTextEdit{parent}
{
    this->setReadOnly(true);
}

bool CompileOutput::runCompilation(QString path) {
    javacompiler::Driver driver;

    bool result = false;

    QStringList parts = path.split("/");
    std::string filename = parts.at(parts.size()-1).toStdString();

    std::string filepath = path.toStdString();

    std::fstream infile(filepath);

    if (!infile.good()) {
        std::cerr << "Could not open file: " << filepath << std::endl;
        return 0;
    }

    try {
        result = driver.parse_stream(infile, filename);
    }
    catch(...) {
        return 0;
    }

    return result;



//    if(!runParser(path))
//    {
//        setMarkdown(toMarkdown()+tr(R"(
//<span style="color:red">**Build failed**</span>)"));
//        return false;
//    }
//    /*
//     * Only to debug parser
//    */
//    else{
//        setMarkdown(tr(R"(<span style="color:green">**Build is successful**</span>)"));
//        return true;
//    }
//    QString program = "javac";
//    QStringList arguments;
//    arguments << path;

//    QProcess* process = new QProcess(this);
//    process->start(program, arguments);
//    qDebug() << program << " "<< arguments;
//    if (!process->waitForFinished()) // This is blocking and needs to be called within a thread
//    {
//        this->setText(tr("Blocking Error"));
//        return false;
//    }
//    QString output = process->readAllStandardError();
//    if (output.isEmpty()) { // no errors
//        output = "Program compiled successfully.";
//    }
//    this->setText(output);
//    return true;
}

/*
 * TODO: Configure Bison & Flex to generate C++ code
*/
bool CompileOutput::runParser(QString path)
{
//    setMarkdown("");
//    FILE *file=fopen(path.toStdString().c_str(),"r"),*tmpFile=tmpfile64();
//    static char errOut[MAX_ERR_SIZE],errLine[MAX_ERR_LINE];
//    char*errPtr=errOut;
//    errOut[0]=0;
//    if(file && tmpFile)
//    {
//        yyin=file;
//        yyout=tmpFile;
//        yyparse();
//        bool err=build_success;
//        reset_all();
//        qDebug() << "Finished Parsing";
//        rewind(yyout);
//        while(fgets(errLine,MAX_ERR_LINE,yyout))
//        {
//            strcat(errOut,errLine);
//            strcat(errOut,"\n");
//        }
//        setMarkdown(errOut);
//        yylex_destroy();
//        return err;
//    }
    return false;
}

