#ifndef ZIPPER_H
#define ZIPPER_H

#include <QThread>
#include <QFile>
#include <QIODevice>
#include <QDataStream>

#include "filepool.h"
#include "zippedbuffer.h"
#include "zippedbufferpool.h"



class Zipper : public QThread
{
public:
    Zipper(FilePool &filePool, ZippedBufferPool &zippedBufferPool);
    virtual void run();

private:
    bool compressFile(const QString &path, ZippedBuffer &buffer);
    FilePool &filePool_;
    ZippedBufferPool &zippedBufferPool_;
};

#endif // ZIPPER_H
