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
            : QSyntaxHighlighter(parent)
    {
        HighlightingRule rule;

        numberFormat.setForeground(Qt::GlobalColor::blue);
        rule.pattern = QRegularExpression(QStringLiteral("\\b(0|[1-9][0-9]*|0[xX][0-9A-Fa-f]+|0[0-7]+|0[bB][01]+)\\b"));
        rule.format = numberFormat;
        highlightingRules.emplace(Priority::NUMBER,rule);

        keywordFormat.setForeground(Qt::darkBlue);
        keywordFormat.setFontWeight(QFont::Bold);

        for (const QString &pattern: keywords) {
            rule.pattern = QRegularExpression("\\b"+pattern+"\\b");
            rule.format = keywordFormat;
            highlightingRules.emplace(Priority::KEYWORD,rule);
        }

        classFormat.setFontWeight(QFont::Bold);
        classFormat.setForeground(Qt::darkMagenta);

        rule.pattern = QRegularExpression(QStringLiteral(R"(\bclass\s(([a-zA-Z_][0-9a-zA-Z_]*\.)*[a-zA-Z_][0-9a-zA-Z_]*)\b)"));
        rule.format = classFormat;
        rule.isClassDef=true;
        highlightingRules.emplace(Priority::CLASSNAME,rule);

        interfaceFormat=classFormat;
        interfaceFormat.setFontItalic(true);
        rule.pattern = QRegularExpression(QStringLiteral(R"(\binterface\s(([a-zA-Z_][0-9a-zA-Z_]*\.)*[a-zA-Z_][0-9a-zA-Z_]*)\b)"));
        rule.format = interfaceFormat;
        highlightingRules.emplace(Priority::CLASSNAME,rule);
        rule.isClassDef=false;


        for(const QString &pattern:defaultClasses)
        {
            HighlightingRule rule;
            rule.format=classFormat;
            rule.pattern=QRegularExpression("\\b"+pattern+"\\b");
            highlightingRules.emplace(Priority::CLASSNAME,rule);
        }

        for(const QString &pattern:defaultInterfaces)
        {
            HighlightingRule rule;
            rule.format=interfaceFormat;
            rule.pattern=QRegularExpression("\\b"+pattern+"\\b");
            highlightingRules.emplace(Priority::CLASSNAME,rule);
        }


        quotationFormat.setForeground(Qt::darkGreen);
        rule.pattern = QRegularExpression(QStringLiteral("\".*\"|\'.\'"));
        rule.format = quotationFormat;
        highlightingRules.emplace(Priority::QUOTATION,rule);


        operatorFormat.setForeground(Qt::darkRed);
        rule.pattern = QRegularExpression(QStringLiteral("\\+|-|\\*|/|%|&|\\||\\^|~|<<|>>|>>>|<|>|<=|>=|==|!=|&&|\\|\\||\\?|:"));
        rule.format = operatorFormat;
        highlightingRules.emplace(Priority::OPERATOR,rule);


        multiLineCommentFormat.setForeground(Qt::GlobalColor::gray);

        commentStartExpression = QRegularExpression(QStringLiteral("/\\*"));
        commentEndExpression = QRegularExpression(QStringLiteral("\\*/"));

        singleLineCommentFormat.setForeground(Qt::GlobalColor::gray);
        rule.pattern = QRegularExpression(QStringLiteral("//[^\n]*"));
        rule.format = singleLineCommentFormat;
        highlightingRules.emplace(Priority::COMMENT,rule);

//        functionFormat.setFontItalic(true);
//        functionFormat.setForeground(Qt::blue);
//        rule.pattern = QRegularExpression(QStringLiteral("\\b[A-Za-z0-9_]+(?=\\()"));
//        rule.format = functionFormat;
//        highlightingRules.append(rule);
    }

    void JavaHighlighter::init(const char *fileName,QStringList &L) {
        std::ifstream H(fileName);
        init(H,L);

    }

    void JavaHighlighter::init(QTextStream &stream,QStringList &L) {
        while(!stream.atEnd())
        {
            QString str;
            stream >> str;
            keywords << str;
        }
    }

    void JavaHighlighter::init(const QString &fileName,QStringList &L) {
            init(fileName.toStdString().c_str(),L);
    }

    void JavaHighlighter::highlightBlock(const QString &text) {
        classNames.erase(currentBlock().blockNumber());

        auto classNameUpperBound=highlightingRules.upper_bound(Priority::CLASSNAME);
        for (auto it=highlightingRules.begin();it!=highlightingRules.end();++it)
        {
            /*Process saved classes/interfaces*/
            if(it==classNameUpperBound) for(const auto& [_,rule] : classNames)
            {
                QRegularExpressionMatchIterator matchIterator =rule.pattern.globalMatch(text);
                while (matchIterator.hasNext()) {
                    QRegularExpressionMatch match = matchIterator.next();
                    setFormat(match.capturedStart(), match.capturedLength(), rule.format);
                }
            }
            /*Process other highlight conditions*/
            const auto &[_,rule] =*it;
            QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
            while (matchIterator.hasNext()) {
                QRegularExpressionMatch match = matchIterator.next();
                if(rule.isClassDef)
                {
                    setFormat(match.capturedStart(1), match.capturedLength(1), classFormat);
                    HighlightingRule newRule;
                    newRule.format= rule.format;
                    newRule.pattern = QRegularExpression("\\b"+match.captured(1) +"\\b");
                    classNames.emplace(currentBlock().blockNumber(),newRule);
                }
                else setFormat(match.capturedStart(), match.capturedLength(), rule.format);

            }
        }


    }


    void JavaHighlighter::init(std::istream &H,QStringList &L) {
        std::string keyword;
        while(H >> keyword)
            L << QString::fromStdString(keyword);
    }
} // syntax