#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

#include "ecf_library_global.h"

#include <QString>
#include <QByteArray>

class QDataStream;

class ECF_LIBRARYSHARED_EXPORT ZippedBuffer
{
public:
    ZippedBuffer();
    ZippedBuffer(const QString &filename, const QByteArray &data);
    void write(QDataStream &stream) const;
    void read(QDataStream &stream);

    const QString &get_filename() const;
    const QByteArray &get_data() const;

private:
    QString filename_;
    QByteArray data_;
};

#endif // ZIPPEDBUFFER_H
