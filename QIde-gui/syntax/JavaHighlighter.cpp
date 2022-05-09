//
// Created by ramizouari on 08/05/22.
//

#include <QSyntaxHighlighter>
#include "JavaHighlighter.h"
#include <istream>
#include <fstream>

namespace syntax
{
    JavaHighlighter::JavaHighlighter(QTextDocument *parent)
            : QSyntaxHighlighter(parent) {
        HighlightingRule rule;

        operatorFormat.setForeground(Qt::darkRed);
        rule.pattern = QRegularExpression(QStringLiteral("(\\+|-|\\*|/|%|&|\\||\\^|~|<<|>>|>>>|<|>|<=|>=|==|!=|&&|\\|\\||\\?|:)"));
        rule.format = operatorFormat;
        highlightingRules.append(rule);


        numberFormat.setForeground(Qt::GlobalColor::blue);
        rule.pattern = QRegularExpression(QStringLiteral("\\b(0|[1-9][0-9]*|0[xX][0-9A-Fa-f]+|0[0-7]+|0[bB][01]+)\\b"));
        rule.format = numberFormat;
        highlightingRules.append(rule);

        keywordFormat.setForeground(Qt::darkBlue);
        keywordFormat.setFontWeight(QFont::Bold);

        for (const QString &pattern: keywords) {
            rule.pattern = QRegularExpression("\\b"+pattern+"\\b");
            rule.format = keywordFormat;
            highlightingRules.append(rule);
        }
        classDefFormat.setFontWeight(QFont::Bold);
        classDefFormat.setForeground(Qt::darkMagenta);
        rule.pattern = QRegularExpression(QStringLiteral(R"(\bclass\s(([a-zA-Z_][0-9a-zA-Z_]*\.)*[a-zA-Z_][0-9a-zA-Z_]*)\b)"));
        rule.format = classDefFormat;
        rule.isClass=true;
        highlightingRules.append(rule);

        quotationFormat.setForeground(Qt::darkGreen);
        rule.pattern = QRegularExpression(QStringLiteral("\".*\"|\'.\'"));
        rule.format = quotationFormat;
        highlightingRules.append(rule);


        singleLineCommentFormat.setForeground(Qt::GlobalColor::gray);
        rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
        rule.format = singleLineCommentFormat;
        highlightingRules.append(rule);

        multiLineCommentFormat.setForeground(Qt::GlobalColor::gray);

        commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
        commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));

//        functionFormat.setFontItalic(true);
//        functionFormat.setForeground(Qt::blue);
//        rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
//        rule.format = functionFormat;
//        highlightingRules.append(rule);
    }

    void JavaHighlighter::initKeywords(std::istream &H) {
        QString line;
        std::string keyword;
        while(H >> keyword)
            keywords << QString::fromStdString(keyword);
    }

    void JavaHighlighter::initKeywords(const char *fileName) {
        std::ifstream H(fileName);
        initKeywords(H);

    }

    void JavaHighlighter::initKeywords(QTextStream &stream) {
        while(!stream.atEnd())
        {
            QString str;
            stream >> str;
            keywords << str;
        }
    }

    void JavaHighlighter::initKeywords(const QString &fileName) {
            initKeywords(fileName.toStdString().c_str());
    }

    void JavaHighlighter::highlightBlock(const QString &text) {
        classNames.clear();
        classRules.clear();
        for (const HighlightingRule &rule: highlightingRules) {
            QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
            while (matchIterator.hasNext()) {
                QRegularExpressionMatch match = matchIterator.next();
                if(rule.isClass)
                {
                    setFormat(match.capturedStart(1), match.capturedLength(1), classDefFormat);
                    HighlightingRule newRule;
                    newRule.format= classDefFormat;
                    newRule.pattern = QRegularExpression("\\b"+match.captured(1) +"\\b");
                    classNames.insert(match.captured(1));
                    classRules.append(newRule);
                }
                else setFormat(match.capturedStart(), match.capturedLength(), rule.format);
            }
        }
        for(const HighlightingRule &rule: classRules)
        {
            QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
            while (matchIterator.hasNext()) {
                QRegularExpressionMatch match = matchIterator.next();
                if(classNames.count(match.captured(1)))
                    setFormat(match.capturedStart(), match.capturedLength(), rule.format);
            }
        }

    }
} // syntax