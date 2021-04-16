#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Logo = "image: url(:/new/Логотип.png);";

    logo = ui->pushButton;
    logo ->setStyleSheet(Logo);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide(); // Закрівает окно
    window2 = new SecondWindow(this);
    window2->show();
}
