#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    studentListModel = new StudentListModel();
    ui->listView->setModel(studentListModel);
    ui->cBoxDelete->setModel(studentListModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{
    auto name = this->ui->leditAdd->text().trimmed();
    if (name.isEmpty()) {
        this->ui->statusbar->showMessage("You need to insert a name first!");
        return;
    }
    studentListModel->addStudent(name);
    this->ui->leditAdd->clear();
}

void MainWindow::on_btnDelete_clicked()
{
    auto index = this->ui->cBoxDelete->currentIndex();
    studentListModel->removeStudent(index);
}
