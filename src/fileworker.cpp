#include "fileworker.h"
#include "mainwindow.h"

#include <QDebug>

FileWorker::FileWorker() {
}

FileWorker::~FileWorker() {
}

void FileWorker::saveFile(const QString &filepath, const QString &text) {

    QFile file(filepath);
    file.open(QIODevice::WriteOnly);

    QTextStream fileStream(&file);

    fileStream << text;
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

QString FileWorker::openFile(const QString &filepath, QTextCodec *qtc) {
    //SaveFile
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);

    QTextStream fileStream(&file);
    fileStream.setCodec(qtc);
    QString text = fileStream.readAll();

    file.close();

    lastFile = filepath;
    return text;
    //qDebug() << lastFile;
}
