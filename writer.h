#ifndef WRITER_H
#define WRITER_H

#include <QThread>
#include <QFile>
#include <QMutex>
#include <QDataStream>
#include <QMutexLocker>

#include "zippedbufferpool.h"


class Writer : public QThread
{
public:
    Writer(const QString &ecfPath, ZippedBufferPool &zippedBufferPool);
    virtual void run();

private:
    const QString &ecfPath_;
    QFile file_;
    QMutex mutex_;
    ZippedBufferPool &zippedBufferPool_;
};

#endif // WRITER_H
