#ifndef ECFWINDOW_H
#define ECFWINDOW_H

#include <QMainWindow>
#include "epsifilecompressor.h"

namespace Ui {
class EcfWindow;
}

class EcfWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EcfWindow(EpsiFileCompressor &efc, QWidget *parent = 0);
    void compressOpen();
    void uncompressOpen();
    ~EcfWindow();

private:
    Ui::EcfWindow *ui;
    EpsiFileCompressor &ecf_;
};

#endif // ECFWINDOW_H
