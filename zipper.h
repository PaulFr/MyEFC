#ifndef ZIPPER_H
#define ZIPPER_H

#include <QThread>

#include "filepool.h"
#include "zippedbuffer.h"
#include "zippedbufferpool.h"



class Zipper : public QThread
{
public:
    Zipper(FilePool &filePool, ZippedBufferPool &zippedBufferPool);
    virtual void run();

private:
    FilePool &filePool_;
    ZippedBuffer &zippedBufferPool_;
};

#endif // ZIPPER_H
