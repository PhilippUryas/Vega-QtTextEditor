#ifndef FONT_H
#define FONT_H

#include <QColor>
#include <QTextEdit>

class Font
{
public:
    Font(QTextEdit *textEdit);
    ~Font();

    void changeBackgroundColor(const QColor color);
    void changeTextColor(const QColor color);

    void setTabStop(int tabStop);
    void setFontSize(int size);

    void setItalic(bool italic);
    //static void setB(bool b, QTextEdit *textEdit);
    void setUnderLine(bool underline);

    //QColor textColor;
    //QColor backgroundColor;
    int fontSizeNow;
    int tabStopSize;

    QColor backgroundColorNow;
    QColor fontColorNow;

private:
    QTextEdit *_textEdit;

};

#endif // FONT_H
