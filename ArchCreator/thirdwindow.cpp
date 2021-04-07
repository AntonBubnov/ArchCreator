#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "secondwindow.h"

ThirdWindow::ThirdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);

    Read_from_file();

    h = 0.01;
    xBegin = -B/2;
    xEnd = B/2;

    ui->widget->xAxis->setRange(-B/2-1,B/2+1);
    ui->widget->yAxis->setRange(-A-1,H+1);
    ui->widget->addGraph();
    DrawPerimeter();
}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}

void ThirdWindow::DrawPerimeter()
{
    xBegin = -B/2;
    xEnd = B/2;

    for(X=xBegin;X<=xEnd;X+=h){
        x3.push_back(X);
        y3.push_back(-A);
    }

    for(Y=-A;Y<=0;Y+=h){
        x1.push_back(xBegin);
        x2.push_back(xEnd);
        y1.push_back(Y);
    }

    ui->widget->addGraph();
    ui->widget->graph(1)->addData(x1,y1);
    ui->widget->addGraph();
    ui->widget->graph(2)->addData(x3,y3);
    ui->widget->addGraph();
    ui->widget->graph(3)->addData(x2,y1);
    ui->widget->replot();
}

void ThirdWindow::Read_from_file()
{
    QFile file(".//data.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::information(this,"Error","Path not correct!");
        return;
    }

    QTextStream stream(&file);

    stream >> H >> B >> A;

    file.close();
}

