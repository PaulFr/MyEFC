#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

#include <QString>
#include <QByteArray>

class QDataStream;

class ZippedBuffer
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

QDataStream &operator <<(QDataStream &out, const ZippedBuffer &zippedBuffer);
QDataStream &operator >>(QDataStream &in, ZippedBuffer &zippedBuffer);

#endif // ZIPPEDBUFFER_H
