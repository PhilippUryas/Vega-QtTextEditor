#include "font.h"

#include <QPalette>

Font::Font(QTextEdit *textEdit) {

    _textEdit = textEdit;
    fontSizeNow = 12;
    tabStopSize = 4;
    backgroundColorNow = Qt::white;
    fontColorNow = Qt::black;

}

Font::~Font() {
    delete _textEdit;
}

void Font::changeTextColor(const QColor color){
    _textEdit->setTextColor(color);

    fontColorNow = color;
}

void Font::changeBackgroundColor(const QColor color) {
    QPalette p = _textEdit->palette();
    p.setColor(QPalette::Base, color);

    _textEdit->setPalette(p);

    backgroundColorNow = color;

}

void Font::setTabStop(int tabStop) {
    _textEdit->setTabStopDistance(tabStop*10);

    tabStopSize = tabStop;
}

void Font::setFontSize(int size) {
    _textEdit->setFontPointSize(size);
    fontSizeNow = size;
}


