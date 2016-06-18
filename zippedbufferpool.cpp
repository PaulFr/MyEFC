#include "zippedbufferpool.h"

ZippedBufferPool::ZippedBufferPool():done_(false)
{
}
void ZippedBufferPool::done()
{
    QMutexLocker locker(&mutex_);
    done_ = true;
    waitCond_.wakeAll();
}
void ZippedBufferPool::put(const ZippedBuffer &zb)
{
    QMutexLocker locker(&mutex_);

    buffers_.push_back(zb);
}
QPair<bool,ZippedBuffer> ZippedBufferPool::tryGet()
{
    QMutexLocker locker(&mutex_);

    if( buffers_.empty()) {
        if(!done_) waitCond_.wait(&mutex_);
        return QPair<bool, ZippedBuffer>(false,ZippedBuffer());
    }
    auto buffer = buffers_.front();
    buffers_.pop_front();
    return QPair<bool,ZippedBuffer>(true,buffer);
}


