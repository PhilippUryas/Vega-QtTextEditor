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
    void createFileSlot();
    void openFileSlot();
    void saveFileSlot();

    void changeBackgroundColorSlot();

    void changeFontColorSlot();
    void changeFontSize();
    void changeTabStopSizeSlot();

public:
    Ui::MainWindow *ui;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupHighlighting();
    void setupHotkeys();
    void setupButtons();

    Font *_font;
    FileWorker *_fileWorker;

    Highlighter *_highlighter;

    //shortcuts
    QShortcut *_ctrlS; //saveFileSlot
    QShortcut *_ctrlO; //openFileSlot

};

#endif // MAINWINDOW_H
