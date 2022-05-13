//
// Created by ramizouari on 11/05/22.
//

#ifndef QIDE_LINENUMBERAREA_H
#define QIDE_LINENUMBERAREA_H
#include <QWidget>
#include "maindocument.h"

class LineNumberArea :public QWidget
{
public:
    explicit LineNumberArea(MainDocument *editor,int offset=1) ;

    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int offset;
    MainDocument *codeEditor;
};


#endif //QIDE_LINENUMBERAREA_H
