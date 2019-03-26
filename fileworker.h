#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QString>
#include <QFile>
#include <QTextEdit>

class FileWorker
{
public:
    FileWorker(QTextEdit *textEdit);
    ~FileWorker();
    void createFile(const QString &filepath);
    void saveFile(const QString &filepath);
    void openFile(const QString &filepath);

    QString lastFile;

private:
    QTextEdit *_textEdit;
};

#endif // FILEWORKER_H
