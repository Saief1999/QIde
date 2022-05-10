#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "syntax/JavaHighlighter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    syntax::JavaHighlighter::initKeywords("keywords");
    syntax::JavaHighlighter::initDefaultClasses("defaultClasses");
    syntax::JavaHighlighter::initDefaultInterfaces("defaultInterfaces");
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QIde_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
/*
    // START DARK THEME(Needs Tweaking) ------------------------------------------
    //     Force the style to be the same on all OSs:
        a.setStyle("Fusion");

    // Now use a palette to switch to dark colors:                
        QPalette palette;
        palette.setColor(QPalette::Window, QColor(53, 53, 53));
        palette.setColor(QPalette::WindowText, Qt::white);
        palette.setColor(QPalette::Base, QColor(25, 25, 25));
        palette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
        palette.setColor(QPalette::ToolTipBase, Qt::black);
        palette.setColor(QPalette::ToolTipText, Qt::white);
        palette.setColor(QPalette::Text, Qt::white);
        palette.setColor(QPalette::Button, QColor(53, 53, 53));
        palette.setColor(QPalette::ButtonText, Qt::white);
        palette.setColor(QPalette::BrightText, Qt::red);
        palette.setColor(QPalette::Link, QColor(42, 130, 218));
        palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        palette.setColor(QPalette::HighlightedText, Qt::black);

        palette.setBrush(QPalette::Disabled, QPalette::WindowText, QColor(83,84,85));
        palette.setBrush(QPalette::Disabled, QPalette::Text, QColor(83,84,85));
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, QColor(83,84,85));
        palette.setBrush(QPalette::Disabled, QPalette::Base, QColor(83,84,85));
        palette.setBrush(QPalette::Disabled, QPalette::Button, QColor(83,84,85));
        palette.setBrush(QPalette::Disabled, QPalette::Mid, QColor(83,84,85));
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, Qt::black);



        a.setPalette(palette);
    // END DARK THEME ---------------------------------------------------------------*/

    MainWindow w;
    w.show();
    return a.exec();
}
