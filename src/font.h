#ifndef FONT_H
#define FONT_H

#include <QColor>
#include <QTextEdit>

#include <QPlainTextEdit>


class Font
{
public:
    Font(QTextEdit *textEdit);
    ~Font();

    void changeBackgroundColor(const QColor &color);
    void changeTextColor(const QColor &color);
    void changeFont(const QString &font);

    void changeFontVidelenie(const QColor &color);

    void setTabStop(int tabStop);
    void setFontSize(int size);


    //void setItalic(bool italic);
    //static void setB(bool b, QTextEdit *textEdit);
    //void setUnderLine(bool underline);

    int fontSizeNow;
    int tabStopSize;

    QColor backgroundColorNow;
    QColor fontColorNow;
    QColor fontVidelenieNow;

private:
    QTextEdit *_textEdit;

};

#endif // FONT_H
