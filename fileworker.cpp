#include "fileworker.h"
#include "mainwindow.h"

#include <QDebug>

FileWorker::FileWorker(QTextEdit *textEdit) {

    _textEdit = textEdit;
}

FileWorker::~FileWorker() {
    delete _textEdit;
}

void FileWorker::saveFile(const QString &filepath) {

    QFile file(filepath);
    file.open(QIODevice::WriteOnly);

    QTextStream fileStream(&file);

    fileStream << _textEdit->toPlainText();
    file.flush();
    file.close();

    lastFile = filepath;
    qDebug() << lastFile;
}

void FileWorker::createFile(const QString &filepath) {

    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    file.close();

    qDebug() << "File created " << filepath;

    lastFile = filepath;
    qDebug() << lastFile;
}

void FileWorker::openFile(const QString &filepath, QTextCodec *qtc) {
    //SaveFile
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);

    QTextStream fileStream(&file);
    fileStream.setCodec(qtc);
    QString text = fileStream.readAll();

    file.close();

    _textEdit->setPlainText(text);

    lastFile = filepath;
    qDebug() << lastFile;
}
