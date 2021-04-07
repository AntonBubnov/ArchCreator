#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    log2 = "image: url(:/new/Log2.png);";

    Log2 = ui->pushButton;
    Log2 ->setStyleSheet(log2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    window2 = new SecondWindow(this);
    window2->show();
}
