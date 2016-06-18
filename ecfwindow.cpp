#include "ecfwindow.h"
#include "mainwindow.h"
#include "ui_ecfwindow.h"
#include "uncompresswindow.h"

EcfWindow::EcfWindow(EpsiFileCompressor &ecf, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EcfWindow),
    ecf_(ecf)
{
    ui->setupUi(this);
    this->setWindowTitle("My EPSI File Compressor");
    connect(ui->compress, &QAbstractButton::clicked, this, &EcfWindow::compressOpen);
    connect(ui->uncompress, &QAbstractButton::clicked, this, &EcfWindow::uncompressOpen);
}

void EcfWindow::compressOpen()
{
    MainWindow *compressWin = new MainWindow(ecf_);
    compressWin->setWindowTitle("MyEFC - Compresser un dossier");
    compressWin->show();
}

void EcfWindow::uncompressOpen()
{
    UncompressWindow *uncompressWin = new UncompressWindow(ecf_);
    uncompressWin->setWindowTitle("MyEFC - Décompresser");
    uncompressWin->show();
}

EcfWindow::~EcfWindow()
{
    delete ui;
}
