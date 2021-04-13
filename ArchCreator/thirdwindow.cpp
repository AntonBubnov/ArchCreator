#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "secondwindow.h"

ThirdWindow::ThirdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);

    Read_from_file();

    h = 0.001;
    xBegin = -B/2.0;
    xEnd = B/2.0;

    ui->widget->xAxis->setRange(-(3*B)/4.0,(3*B)/4.0);
    ui->widget->yAxis->setRange(-(5*A)/4.0,H+A/4.0);
    ui->widget->addGraph();

    switch (N) {
    case 1: DrawSemicircular();
        break;
    case 2: DraweSegment();
        break;
    case 3: DraweLancet();
        break;
    case 4: DraweShamrock();
        break;
    case 5: DraweInflexed();
        break;
    case 6: DrawShouldered_flat();
        break;
    }

}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}

void ThirdWindow::DrawPerimeter()
{    /*
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
    */
    x.push_back(xBegin);
    y.push_back(-A);
    x.push_back(xBegin);
    y.push_back(0);

    x.push_back(xEnd);
    y.push_back(0);
    x.push_back(xEnd);
    y.push_back(-A);

    x1.push_back(xBegin);
    y1.push_back(-A);
    x1.push_back(xEnd);
    y1.push_back(-A);
}

void ThirdWindow::Read_from_file()
{
    QFile file(".//data.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::information(this,"Error","Path not correct!");
        return;
    }

    QTextStream stream(&file);

    stream >> N >> H >> B >> A;

    file.close();
}

void ThirdWindow::DrawSemicircular()
{
    DrawPerimeter();
    R=B/2.0;
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(sqrt(R*R-X*X));
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(1)->addData(x1,y1);
    ui->widget->replot();

    //DrawPerimeter();
}

void ThirdWindow::DraweSegment()
{
    DrawPerimeter();
    C = ((B*B)/4.0-H*H)/(2.0*H);
    R = H+C;
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(sqrt(R*R-X*X)-C);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(1)->addData(x1,y1);
    ui->widget->replot();

   // DrawPerimeter();
}

void ThirdWindow::DraweLancet()
{
    DrawPerimeter();
    C = (H*H-(B*B)/4)/B;
    R = B/2.0 + C;
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(sqrt(R*R-(abs(X)+C)*(abs(X)+C)));
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(1)->addData(x1,y1);
    ui->widget->replot();

   // DrawPerimeter();
}

void ThirdWindow::DraweShamrock()
{
    DrawPerimeter();
    R = B/4.0;
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        if(X<=-R || X>=R){
            y.push_back(sqrt(R*R-pow(sqrt(abs(X)-R),4)));
        }
        else{
            y.push_back(sqrt(R*R-X*X)+R);
        }

    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(1)->addData(x1,y1);
    ui->widget->replot();

   // DrawPerimeter();
}

void ThirdWindow::DraweInflexed()
{
    DrawPerimeter();
    R = (H*H+(B*B)/4.0)/(2.0*H);
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(R-sqrt(R*R-pow(sqrt(-(abs(X)-B/2.0)),4)));
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(1)->addData(x1,y1);
    ui->widget->replot();

   // DrawPerimeter();
}

void ThirdWindow::DrawShouldered_flat()
{
    DrawPerimeter();
    R = B/4.0;
    for(X=xBegin;X<=xEnd;X+=h){
        if(X<=-R || X>=R){
            x.push_back(X);
            y.push_back(sqrt(R*R-pow(sqrt(abs(X)-R),4)));
        }
        else{
            x.push_back(-R);
            y.push_back(H);
            x.push_back(R);
            y.push_back(H);
            X=R;
        }
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(1)->addData(x1,y1);
    ui->widget->replot();

    //DrawPerimeter();
}


void ThirdWindow::on_pushButton_clicked()
{

}
