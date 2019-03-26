#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileworker.h"
#include "font.h"
#include "highlither.h"

#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _fileWorker = new FileWorker(ui->textEdit);

    _font = new Font(ui->textEdit);

    setupHighlighting();
    setupHotkeys();
    setupButtons();
}

void MainWindow::setupHighlighting() {

     _highlighter = new Highlighter(ui->textEdit->document());
}

void MainWindow::setupHotkeys() {
    _ctrlS = new QShortcut(this);
    _ctrlS->setKey(Qt::CTRL + Qt::Key_S);

    _ctrlO = new QShortcut(this);
    _ctrlO->setKey(Qt::CTRL + Qt::Key_O);

    connect(_ctrlS, &QShortcut::activated, this, &MainWindow::saveFileSlot);
    connect(_ctrlO, &QShortcut::activated, this, &MainWindow::openFileSlot);
}

void MainWindow::setupButtons() {
    /* file */
    connect(ui->actionCreate_file, &QAction::triggered, this, &MainWindow::createFileSlot);
    connect(ui->actionOpen_file, &QAction::triggered, this, &MainWindow::openFileSlot);
    connect(ui->actionSave_file, &QAction::triggered, this, &MainWindow::saveFileSlot);

    /* font */
    connect(ui->actionChange_font_color, &QAction::triggered,  this, &MainWindow::changeFontColorSlot);
    connect(ui->actionChange_font_size, &QAction::triggered, this, &MainWindow::changeFontSize);
    connect(ui->actionSet_tab_stop, &QAction::triggered, this, &MainWindow::changeTabStopSizeSlot);

    connect(ui->actionChange_background_color, &QAction::triggered,  this, &MainWindow::changeBackgroundColorSlot);

}


void MainWindow::createFileSlot() {
    _fileWorker->createFile(QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        "/home/test",
                                                        tr("")));
}

void MainWindow::openFileSlot() {
    _fileWorker->openFile(QFileDialog::getOpenFileName(this,
                                                      tr("Open Text File"),
                                                      "/home",
                                                      tr("")));
}

void MainWindow::saveFileSlot() {
    _fileWorker->saveFile(QFileDialog::getSaveFileName(this, tr("Save File"),
                                                      "/home/test",
                                                      tr("")));
}

void MainWindow::changeBackgroundColorSlot() {
    _font->changeBackgroundColor(QColorDialog::getColor(_font->backgroundColorNow, this));

}

void MainWindow::changeFontColorSlot() {
    _font->changeTextColor(QColorDialog::getColor(_font->fontColorNow, this));
}

void MainWindow::changeFontSize() {
    bool ok;
    int size = QInputDialog::getInt(this, tr("Font size"),
                                    tr("Font size: "), _font->fontSizeNow, 0, 100, 1, &ok);
    if(ok) {
        _font->setFontSize(size);
    }

}

void MainWindow::changeTabStopSizeSlot() {
    bool ok;
    int size = QInputDialog::getInt(this, tr("Font size"),
                                    tr("Font size: "), _font->tabStopSize, 0, 10, 1, &ok);
    if(ok) {
        _font->setTabStop(size);
    }
}



MainWindow::~MainWindow()
{
    delete _fileWorker;

    delete _font;

    delete _highlighter;

    delete _ctrlO;
    delete _ctrlS;

    delete ui;
}
