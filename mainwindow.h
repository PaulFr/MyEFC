#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWidget>
#include <QDir>

#include "epsifilecompressor.h"

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;
class QProgressBar;



class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(EpsiFileCompressor &efc, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void init();
    void browse();
    void compress();

private:
    QStringList findFiles(const QStringList &files, const QString &text);
    QComboBox *createComboBox(const QString &text = QString());

    QComboBox *toComboBox;
    QComboBox *fromComboBox;

    QProgressBar *progressBar;

    QLabel *toLabel;
    QLabel *fromLabel;

    QPushButton *browseButton;
    QPushButton *compressButton;

    QTableWidget *filesTable;

    QDir currentDir;

    EpsiFileCompressor &efc_;
};

#endif // MAINWINDOW_H
