#include "epsifilecompressor.h"
#include <QProgressBar>

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
