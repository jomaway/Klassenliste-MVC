#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "studentlistmodel.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
    StudentListModel *studentListModel;
};
#endif // MAINWINDOW_H
