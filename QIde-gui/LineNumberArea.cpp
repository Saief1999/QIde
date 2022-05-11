//
// Created by ramizouari on 11/05/22.
//

#include "LineNumberArea.h"

LineNumberArea::LineNumberArea(MainDocument *editor) : QWidget(editor), codeEditor(editor)
{}

QSize LineNumberArea::sizeHint() const {
    return QSize(codeEditor->lineNumberAreaWidth(), 0);
}

void LineNumberArea::paintEvent(QPaintEvent *event)     {
    codeEditor->lineNumberAreaPaintEvent(event);
}
