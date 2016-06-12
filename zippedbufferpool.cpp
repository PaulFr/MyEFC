#include "zippedbufferpool.h"

ZippedBufferPool::ZippedBufferPool():done_(false)
{
}
void ZippedBufferPool::done()
{
    done_ = true;
}
void ZippedBufferPool::put(const ZippedBuffer &zb)
{
    buffers_.push_back(zb);
}
QPair<bool,ZippedBuffer> ZippedBufferPool::tryGet()
{
    if( buffers_.empty()) {
        return QPair<bool, ZippedBuffer>(false,ZippedBuffer());
    }
    auto buffer = buffers_.front();
    buffers_.pop_front();
    return QPair<bool,ZippedBuffer>(true,buffer);
}
