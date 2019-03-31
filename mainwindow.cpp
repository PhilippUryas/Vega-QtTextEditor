#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileworker.h"
#include "font.h"
#include "highlither.h"
#include "compilation.h"

#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QTextCodec>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("TextEditor");

    _fileWorker = new FileWorker(ui->textEdit);

    _font = new Font(ui->textEdit);

    setupHotkeys();
    setupButtons();
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

    connect(ui->checkBoxHighlighting, &QCheckBox::toggled, this, &MainWindow::hightlightingSlot);

    /* file */
    connect(ui->actionCreate_file, &QAction::triggered, this, &MainWindow::createFileSlot);
    connect(ui->actionOpen_file, &QAction::triggered, this, &MainWindow::openFileSlot);
    connect(ui->actionSave_file, &QAction::triggered, this, &MainWindow::saveFileSlot);

    /* font */
    connect(ui->actionChange_font, &QAction::triggered, this, &MainWindow::changeFontSlot);
    connect(ui->actionChange_font_color, &QAction::triggered,  this, &MainWindow::changeFontColorSlot);
    connect(ui->actionChange_font_size, &QAction::triggered, this, &MainWindow::changeFontSize);
    connect(ui->actionSet_tab_stop, &QAction::triggered, this, &MainWindow::changeTabStopSizeSlot);

    connect(ui->actionChange_background_color, &QAction::triggered,  this, &MainWindow::changeBackgroundColorSlot);

    /* compile */

    connect(ui->actionCompile_gpp, &QAction::triggered, this, &MainWindow::compileGppSlot);

}

void MainWindow::hightlightingSlot() {
    if(ui->checkBoxHighlighting->checkState()) {
        _highlighter = new Highlighter(ui->textEdit->document());
    }
    else {
        delete _highlighter;
    }

}

void MainWindow::createFileSlot() {
    QString filepath = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "/home/test",
                                                    tr(""));
    if(filepath != "") {
        _fileWorker->createFile(filepath);
        this->setWindowTitle(filepath);
    }
}

void MainWindow::openFileSlot() {

    QStringList codecNames;
    codecNames << tr("UTF-8") << tr("UTF-16") << tr("UTF-32")
               << tr("KOI8-R") << tr("KOI8-U");

    bool ok;

    const QString codec = QInputDialog::getItem(this, tr("Set codec"),
                                          tr("Codec:"), codecNames,
                                          0, false, &ok);

    if(ok) {

        QTextCodec *textCodec = QTextCodec::codecForName(codec.toStdString().c_str());

        QString filepath = QFileDialog::getOpenFileName(this,
                                                    tr("Open Text File"),
                                                    "/home",
                                                    tr(""));
        if(filepath != "") {
            _fileWorker->openFile(filepath, textCodec);
            this->setWindowTitle(filepath);
        }
    }
}

void MainWindow::saveFileSlot() {
    QString filepath = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "/home/test",
                                                    tr(""));
    if(filepath != "") {
        _fileWorker->saveFile(filepath);
        this->setWindowTitle(filepath);
    }
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

void MainWindow::changeFontSlot() {
    QStringList fonts;
    fonts << tr("Ubuntu") << tr("Times New Roman");

    bool ok;

    const QString font = QInputDialog::getItem(this, tr("Set font"),
                                          tr("Font:"), fonts,
                                          0, false, &ok);
    if(ok) {
        _font->changeFont(font);
    }
}

void MainWindow::compileGppSlot() {
    //Compilation compil;
    if(!_fileWorker->lastFile.isEmpty()) {
        Compilation::compileGpp(_fileWorker->lastFile);
    }
    else {
        saveFileSlot();
        Compilation::compileGpp(_fileWorker->lastFile);
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
