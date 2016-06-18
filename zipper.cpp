#include "zipper.h"
#include <QDataStream>
#include <iostream>

Zipper::Zipper(FilePool &filePool, ZippedBufferPool &zippedBufferPool):
    filePool_(filePool), zippedBufferPool_(zippedBufferPool)
{

}

void Zipper::run() {
    QString path = filePool_.tryGetFile();
    ZippedBuffer buffer;

    while(!path.isEmpty()){

        if(compressFile(path, buffer))
            zippedBufferPool_.put(buffer);

        path = filePool_.tryGetFile();
    }

    zippedBufferPool_.done();
}

bool Zipper::compressFile(const QString &path, ZippedBuffer &zippedBuffer){
    QFile file(path);
    QByteArray zippedDataBytes;
    QByteArray rawDataBytes;
    QDataStream stream(&rawDataBytes, QIODevice::ReadWrite);

    if(!file.open(QFile::ReadOnly)) return false;

    std::cout << "Compress " << path.toStdString() << std::endl;

    zippedDataBytes = qCompress(file.readAll());
    stream << path << zippedDataBytes;
    QDataStream outputStream(rawDataBytes);

    outputStream >> zippedBuffer;
    file.close();
    return true;
}
