#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{

        browseButton = new QPushButton(tr("&Parcourir..."), this);
        connect(browseButton, &QAbstractButton::clicked, this, &MainWindow::browse);
        compressButton = new QPushButton(tr("&Compresser"), this);
        connect(compressButton, &QAbstractButton::clicked, this, &MainWindow::find);

        toComboBox = createComboBox();
        fromComboBox = createComboBox();

        toLabel = new QLabel(tr("vers :"));
        fromLabel = new QLabel(tr("Dossier à compresser :"));

        QGridLayout *mainLayout = new QGridLayout;
           mainLayout->addWidget(fromLabel, 0, 0);
           mainLayout->addWidget(fromComboBox, 0, 1);
           mainLayout->addWidget(browseButton, 0, 2);
           mainLayout->addWidget(toLabel, 1, 0);
           mainLayout->addWidget(toComboBox, 1, 1, 1, 2);

           mainLayout->addWidget(compressButton, 3, 2);
           setLayout(mainLayout);

           setWindowTitle(tr("My EPSI File Compressor"));
           resize(500, 105);
}

void MainWindow::browse()
{
    QString directory = QFileDialog::getExistingDirectory(this,
                               tr("Dossier cible"), QDir::currentPath());

    if (!directory.isEmpty()) {
        if (fromComboBox->findText(directory) == -1)
            fromComboBox->addItem(directory);
        fromComboBox->setCurrentIndex(fromComboBox->findText(directory));
        QString toFileName = directory.split('/').takeLast()+".ecf";
        if(toComboBox->findText(toFileName) == -1)
            toComboBox->addItem(toFileName);
        toComboBox->setCurrentIndex(toComboBox->findText(toFileName));
    }
}

void MainWindow::find()
{

}




QComboBox *MainWindow::createComboBox(const QString &text)
{
    QComboBox *comboBox = new QComboBox;
    comboBox->setEditable(true);
    comboBox->addItem(text);
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    return comboBox;
}



MainWindow::~MainWindow()
{

}
