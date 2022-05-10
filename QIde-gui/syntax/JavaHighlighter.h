//
// Created by ramizouari on 08/05/22.
//

#ifndef QIDE_JAVAHIGHLIGHTER_H
#define QIDE_JAVAHIGHLIGHTER_H
#include <QRegularExpression>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <set>

namespace syntax {

    class JavaHighlighter:public QSyntaxHighlighter {
    Q_OBJECT

    enum class Priority
    {
        CLASSNAME=600,
        KEYWORD=700,
        NUMBER=800,
        OPERATOR=800,
        QUOTATION=900,
        COMMENT=1000
    };
    public:
        JavaHighlighter(QTextDocument *parent = nullptr);
        ~JavaHighlighter() override = default;

        template<class File>
        static void initKeywords(File& F)
        {
            init(F,keywords);
        }

        template<class File>
        static void initDefaultClasses(File&F)
        {
            return init(F,defaultClasses);
        }

        template<class File>
        static void initDefaultInterfaces(File&F)
        {
            return init(F,defaultInterfaces);
        }

        void highlightBlock(const QString &text) override;

    private:
        static void init(std::istream &H,QStringList &L);
        static void init(const QString &fileName,QStringList &L);
        static void init(const char * fileName,QStringList &L);
        static void init(QTextStream &stream,QStringList &L);

        inline static QStringList keywords,defaultClasses,defaultInterfaces;

        struct HighlightingRule
        {
            QRegularExpression pattern;
            QTextCharFormat format;
            bool isClassDef= false;
        };
        QVector<HighlightingRule> classRules;

        QRegularExpression commentStartExpression;
        QRegularExpression commentEndExpression;

        QTextCharFormat keywordFormat;
        QTextCharFormat classFormat;
        QTextCharFormat interfaceFormat;
        QTextCharFormat singleLineCommentFormat;
        QTextCharFormat multiLineCommentFormat;
        QTextCharFormat quotationFormat;
        QTextCharFormat numberFormat;
        QTextCharFormat operatorFormat;
        std::multimap<int,HighlightingRule> classNames;
        std::multimap<Priority,HighlightingRule>highlightingRules;
    };

} // syntax

#endif //QIDE_JAVAHIGHLIGHTER_H
