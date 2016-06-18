#include "uncompresswindow.h"
#include "ui_uncompresswindow.h"
#include <QtWidgets>
#include "epsifilecompressor.h"

UncompressWindow::UncompressWindow(EpsiFileCompressor &efc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UncompressWindow),
    efc_(efc)
{
    ui->setupUi(this);
    connect(ui->browse, &QAbstractButton::clicked, this, &UncompressWindow::browse);
    connect(ui->uncompress, &QAbstractButton::clicked, this, &UncompressWindow::uncompress);
}

void UncompressWindow::browse()
{
    QString directory = QFileDialog::getOpenFileName(this,
                          tr("Fichier ECF"), QDir::currentPath(), tr("ECF Files (*.ecf)"));

    if (!directory.isEmpty()) {
        if (ui->ecfFile->findText(directory) == -1)
            ui->ecfFile->addItem(directory);
        ui->ecfFile->setCurrentIndex(ui->ecfFile->findText(directory));
    }
}

void UncompressWindow::uncompress(){
    efc_.uncompressFile(ui->ecfFile->currentText());
}

UncompressWindow::~UncompressWindow()
{
    delete ui;
}
