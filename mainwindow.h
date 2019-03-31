#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include "highlither.h"
#include "fileworker.h"
#include "font.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    //file
    void createFileSlot();
    void openFileSlot();
    void saveFileSlot();

    //font
    void changeBackgroundColorSlot();

    void changeFontColorSlot();
    void changeFontSize();
    void changeTabStopSizeSlot();

    void changeFontSlot();

    //compile
    void compileGppSlot();

    //checkbox
    void hightlightingSlot();

public:
    Ui::MainWindow *ui;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QString getFilePath();

    void setupHotkeys();
    void setupButtons();

    const QString _labelName;

    Font *_font;
    FileWorker *_fileWorker;

    Highlighter *_highlighter;

    //shortcuts
    QShortcut *_ctrlS; //saveFileSlot
    QShortcut *_ctrlO; //openFileSlot

};

#endif // MAINWINDOW_H
