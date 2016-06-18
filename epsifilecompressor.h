#ifndef EPSIFILECOMPRESSOR_H
#define EPSIFILECOMPRESSOR_H

#include    "filepool.h"
#include    "zippedbufferpool.h"
#include    "zipper.h"
#include    "writer.h"
#include <QProgressBar>

class EpsiFileCompressor
{
public:
    EpsiFileCompressor();
    EpsiFileCompressor(int nbThreads);
    void compressFolder(const QString &folderPath, const QString &targetFile, QProgressBar *progress);
    bool uncompressFile(const QString &filePath);

private:
    int nbThreads_;
};

#endif // EPSIFILECOMPRESSOR_H
