#ifndef COMPILATION_H
#define COMPILATION_H

#include <QString>

class Compilation
{
public:
    Compilation();

    static void compileGpp(QString filename);
};

#endif // COMPILATION_H
