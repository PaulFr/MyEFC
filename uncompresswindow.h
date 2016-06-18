#ifndef UNCOMPRESSWINDOW_H
#define UNCOMPRESSWINDOW_H

#include <QWidget>
#include "epsifilecompressor.h"

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;
class QProgressBar;

namespace Ui {
class UncompressWindow;
}

class UncompressWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UncompressWindow(EpsiFileCompressor &efc, QWidget *parent = 0);
    ~UncompressWindow();

private:
    Ui::UncompressWindow *ui;
    EpsiFileCompressor &efc_;
    void browse();
    void uncompress();
};

#endif // UNCOMPRESSWINDOW_H
