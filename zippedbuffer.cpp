#include "zippedbuffer.h"

#include <QDataStream>
ZippedBuffer::ZippedBuffer()
{

}
ZippedBuffer::ZippedBuffer(const QString &filename, const QByteArray &data):
    filename_(filename), data_(data)
{
}
void ZippedBuffer::write(QDataStream &stream) const
{
    stream << filename_;
    stream << data_;
}
void ZippedBuffer::read(QDataStream &stream)
{
    stream >> filename_;
    stream >> data_;
}
const QString &ZippedBuffer::get_filename() const
{
    return filename_;
}

const QByteArray &ZippedBuffer::get_data() const
{
    return data_;
}
