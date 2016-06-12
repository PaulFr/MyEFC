#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QWidget>
#include <QDir>

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;



class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void browse();
    void find();

private:
    QStringList findFiles(const QStringList &files, const QString &text);
    QComboBox *createComboBox(const QString &text = QString());

    QComboBox *toComboBox;
    QComboBox *fromComboBox;

    QLabel *toLabel;
    QLabel *fromLabel;

    QPushButton *browseButton;
    QPushButton *compressButton;

    QTableWidget *filesTable;

    QDir currentDir;
};

#endif // MAINWINDOW_H
