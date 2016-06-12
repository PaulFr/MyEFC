#ifndef ZIPPEDBUFFERPOOL_H
#define ZIPPEDBUFFERPOOL_H

#include "zippedbuffer.h"
#include <list>
#include <QPair>

class ECF_LIBRARYSHARED_EXPORT ZippedBufferPool
{
public:
    ZippedBufferPool();
    void put(const ZippedBuffer &zb);
    QPair<bool, ZippedBuffer> tryGet();
    void done();
private:
    std::list<ZippedBuffer> buffers_;
    bool done_;
};

#endif // ZIPPEDBUFFERPOOL_H
