#include "compilation.h"

#include <cstring>
#include <QDebug>

Compilation::Compilation()
{

}

void Compilation::compileGpp(QString filename) {
 #ifndef _WIN32
    QString compiler = "g++ " + filename + " && " + "a.exe";
 #else
    QString compiler = "g++ " + filename + " && " + "./a.out";
 #endif
    system(compiler.toStdString().c_str());
    //qDebug() << compiler.toStdString().c_str();
}


