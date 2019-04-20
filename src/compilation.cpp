#include "compilation.h"

#include <cstring>
#include <QDebug>

Compilation::Compilation()
{

}

void Compilation::compileGpp(QString filename) {
    QString compiler = "g++ " + filename + " && " + "./a.out";
    system(compiler.toStdString().c_str());
    //qDebug() << compiler.toStdString().c_str();
}


