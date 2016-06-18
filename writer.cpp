#include "writer.h"
#include <iostream>

Writer::Writer(const QString &ecfPath, ZippedBufferPool &zippedBufferPool):
    QThread(nullptr),
    ecfPath_(ecfPath),
    file_(ecfPath),
    zippedBufferPool_(zippedBufferPool)

{
    file_.open(QFile::WriteOnly);
}

void Writer::run(){
    QMutexLocker locker(&mutex_);
    QDataStream compressedFile(&file_);

    QPair<bool, ZippedBuffer> pair = zippedBufferPool_.tryGet();
        while (pair.first) {
            std::cout << "Write" << std::endl;
            compressedFile << pair.second;

            pair = zippedBufferPool_.tryGet();
        }

    file_.close();
    locker.unlock();
}
