#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "secondwindow.h"

ThirdWindow::ThirdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);
    H=0;
    A=0;
    B=0;

    //H = second.value(1);
   // A = second.value(2);
    //B = second.value(3);

    ui->widget->xAxis->setRange(-B/2-1,B/2+1);
    ui->widget->yAxis->setRange(-A-1,H+1);
    ui->widget->addGraph();
}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}

