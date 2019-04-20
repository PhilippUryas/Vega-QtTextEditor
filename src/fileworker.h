#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QString>
#include <QFile>
#include <QTextEdit>
#include <QTextCodec>
#include <QFileInfo>

class FileWorker
{
public:
    FileWorker();
    ~FileWorker();
    void createFile(const QString &filepath);
    void saveFile(const QString &filepath, const QString &text);
    QString openFile(const QString &filepath, QTextCodec *qtc);

    QString lastFile;
    //QString filename;

};

#endif // FILEWORKER_H
