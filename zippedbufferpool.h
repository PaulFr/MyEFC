#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H

#include "zippedbuffer.h"
#include <list>
#include <QPair>
#include <Qmutex>
#include <QWaitCondition>

class ZippedBufferPool
{
public:
    ZippedBufferPool();
    void put(const ZippedBuffer &zb);
    QPair<bool, ZippedBuffer> tryGet();
    void done();
private:
    std::list<ZippedBuffer> buffers_;
    bool done_;
    QMutex mutex_;
    QWaitCondition waitCond_;
};

#endif // ZIPPEDBUFFERPOOL_H
