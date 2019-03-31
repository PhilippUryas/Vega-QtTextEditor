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
    FileWorker(QTextEdit *textEdit);
    ~FileWorker();
    void createFile(const QString &filepath);
    void saveFile(const QString &filepath);
    void openFile(const QString &filepath, QTextCodec *qtc);

    QString lastFile;
    //QString filename;

private:

    QTextEdit *_textEdit;
};

#endif // FILEWORKER_H
