#include "epsifilecompressor.h"
#include <QProgressBar>
#include <QFileInfo>
#include <QDir>

EpsiFileCompressor::EpsiFileCompressor(int nbThreads):nbThreads_(nbThreads)
{

}

EpsiFileCompressor::EpsiFileCompressor()
{
    nbThreads_ = 1;
}


void EpsiFileCompressor::compressFolder(const QString &folderPath, const QString &targetFile, QProgressBar *progress){

    FilePool filePool(folderPath);
    ZippedBufferPool zippedBufferPool;
    Writer *writer = new Writer(targetFile, zippedBufferPool);

    int nbFiles = filePool.count();
    progress->setValue(0);
    QList<Zipper*> zippers;
    Zipper *zipper;
    for(int i=0; i < nbThreads_; i++){
        zipper = new Zipper(filePool, zippedBufferPool);
        zippers.append(zipper);
        zipper->start();
    }
    for (Zipper* zipper : zippers) {
        progress->setValue((1-(filePool.count()/nbFiles))*100);
         zipper->wait();
         delete zipper;
    }

    writer->start();
    writer->wait();
    delete writer;
    progress->setValue(100);

}

bool EpsiFileCompressor::uncompressFile(const QString &filePath){
    QByteArray zippedData;
    QFile ecf(filePath);

    QStringList sDir = filePath.split('.');
    sDir.pop_back();
    QString dirPath = sDir.join('.');

    QDir dir(dirPath);
    if(!ecf.open(QIODevice::ReadOnly))
        return false;

    zippedData = ecf.readAll();
    QDataStream fileStream(zippedData);

    while(!fileStream.atEnd()){
        ZippedBuffer buffer;
        fileStream >> buffer;

        QFileInfo fileInfo(dirPath + dir.relativeFilePath(buffer.get_filename()));

        if (!QDir(fileInfo.path()).exists()){
            QDir().mkpath(fileInfo.path());
        }


        QFile uncompressedFile(fileInfo.filePath());
        uncompressedFile.open(QIODevice::WriteOnly);
        uncompressedFile.write(qUncompress(buffer.get_data()));

        uncompressedFile.close();
        return true;
    }

}
