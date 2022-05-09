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
    public:
        JavaHighlighter(QTextDocument *parent = nullptr);
        ~JavaHighlighter() override = default;

        static void initKeywords(QTextStream &stream);
        static void initKeywords(const QString &fileName);
        static void initKeywords(const char * fileName);
        static void initKeywords(std::istream &H);
        void highlightBlock(const QString &text) override;

    private:
        inline static QStringList keywords;

        struct HighlightingRule
        {
            QRegularExpression pattern;
            QTextCharFormat format;
            bool isClass= false;
        };
        QVector<HighlightingRule> highlightingRules;
        QVector<HighlightingRule> classRules;

        QRegularExpression commentStartExpression;
        QRegularExpression commentEndExpression;

        QTextCharFormat keywordFormat;
        QTextCharFormat classDefFormat;
        QTextCharFormat classFormat;
        QTextCharFormat singleLineCommentFormat;
        QTextCharFormat multiLineCommentFormat;
        QTextCharFormat quotationFormat;
        QTextCharFormat numberFormat;
        QTextCharFormat operatorFormat;
        std::set<QString> classNames;
    };

} // syntax

#endif //QIDE_JAVAHIGHLIGHTER_H
