#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "secondwindow.h"

ThirdWindow::ThirdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);

    Read_from_file();

    h = B/200.0;
    xBegin = -B/2.0;
    xEnd = B/2.0;

    if(B>=A+H){
        L = (1.5*B-A-H)/2.0;
        ui->widget->xAxis->setRange(-0.75*B,0.75*B);
        ui->widget->yAxis->setRange(-L-A,L+H);
    }
    else{
        L = (1.5*A+H-B)/2.0;
        ui->widget->xAxis->setRange(-L-B/2.0,L+B/2.0);
        ui->widget->yAxis->setRange(-1.25*A,H+A/4.0);
    }

    //ui->widget->xAxis->setRange(-(3*B)/4.0,(3*B)/4.0);
    //ui->widget->yAxis->setRange(-(5*A)/4.0,H+A/4.0);
    ui->widget->xAxis->setLabel("мм");
    ui->widget->yAxis->setLabel("мм");

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
    case 7: DrawParabolic();
        break;
    case 8: DrawRoot();
        break;
    case 9: DrawElliptical();
        break;
    case 10: DrawCycloid();
        break;
    }

}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}

void ThirdWindow::DrawPerimeter()
{
    x1.push_back(xBegin);
    y1.push_back(0);
    x1.push_back(xBegin);
    y1.push_back(-A);
    x1.push_back(xEnd);
    y1.push_back(-A);
    x1.push_back(xEnd);
    y1.push_back(0);

    x.push_back(xBegin);
    y.push_back(0);
    x.push_back(xEnd);
    y.push_back(0);
/*
    x3.push_back(xBegin);
    y3.push_back(0);
    x3.push_back(xEnd);
    y3.push_back(0);*/
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

    h*=10;
    for(X=xBegin;X<=xEnd;X+=h){
        x3.push_back(X);
        y3.push_back(-sqrt(R*R-X*X));
    }

    x2.push_back(0);
    y2.push_back(0);

    DrawGraph();

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

    d=h*(B/(2.0*H));
    for(X=-R;X<=xBegin;X+=d){
        x3.push_back(X);
        y3.push_back(sqrt(R*R-X*X)-C);
    }

    for(X=xEnd;X<=R;X+=d){
        x3.push_back(X);
        y3.push_back(sqrt(R*R-X*X)-C);
    }

    d=h*10;
    for(X=-R;X<=R;X+=d){
        x3.push_back(X);
        y3.push_back(-sqrt(R*R-X*X)-C);
    }

    x2.push_back(0);
    y2.push_back(-C);

    DrawGraph();

   // DrawPerimeter();
}

void ThirdWindow::DraweLancet()
{
    DrawPerimeter();
    C = (H*H-(B*B)/4.0)/B;
    R = B/2.0 + C;
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(sqrt(R*R-(abs(X)+C)*(abs(X)+C)));
    }

    d=h*pow(2,(2*H/B));
    for(Y=-R;Y<=0;Y+=d){
        x3.push_back(sqrt(R*R-Y*Y)-C);
        y3.push_back(Y);
        x3.push_back(C-sqrt(R*R-Y*Y));
        y3.push_back(Y);
    }

    for(Y=H;Y<=R;Y+=d){
        x3.push_back(sqrt(R*R-Y*Y)-C);
        y3.push_back(Y);
        x3.push_back(C-sqrt(R*R-Y*Y));
        y3.push_back(Y);
    }

    x2.push_back(-C);
    y2.push_back(0);
    x2.push_back(C);
    y2.push_back(0);

    DrawGraph();

   // DrawPerimeter();
}

void ThirdWindow::DraweShamrock()
{
    DrawPerimeter();
    R = B/4.0;
    for(X=xBegin+h;X<xEnd;X+=h){
        x.push_back(X);
        if(X<=-R || X>=R){
            y.push_back(sqrt(R*R-pow(sqrt(abs(X)-R),4)));
        }
        else{
            y.push_back(sqrt(R*R-X*X)+R);
        }

    }

    h*=5;
    for(X=-R;X<=R;X+=h){
        x3.push_back(X);
        y3.push_back(R-sqrt(R*R-X*X));
        x3.push_back(X);
        y3.push_back(sqrt(R*R-(X+R)*(X+R)));
        x3.push_back(X);
        y3.push_back(sqrt(R*R-(X-R)*(X-R)));
    }

    for(X=xBegin;X<=xEnd;X+=h){
        x3.push_back(X);
        y3.push_back(-sqrt(R*R-(X+R)*(X+R)));
        x3.push_back(X);
        y3.push_back(-sqrt(R*R-(X-R)*(X-R)));
    }

    x2.push_back(-R);
    y2.push_back(0);
    x2.push_back(0);
    y2.push_back(R);
    x2.push_back(R);
    y2.push_back(0);

    DrawGraph();
}

void ThirdWindow::DraweInflexed()
{
    DrawPerimeter();
    R = (H*H+(B*B)/4.0)/(2.0*H);
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(R-sqrt(R*R-pow(sqrt(-(abs(X)-B/2.0)),4)));
    }

    h*=5;
    for(X=-2*R;X<=2*R;X+=h){
        x3.push_back(X);
        y3.push_back(R-sqrt(R*R-pow(sqrt((abs(X)-B/2.0)),4)));
        x3.push_back(X);
        y3.push_back(R-sqrt(R*R-pow(sqrt((abs(X)+B/2.0)),4)));
    }

    x2.push_back(xBegin);
    y2.push_back(R);
    x2.push_back(xEnd);
    y2.push_back(R);

    DrawGraph();

   // DrawPerimeter();
}

void ThirdWindow::DrawShouldered_flat()
{
    DrawPerimeter();
    R = B/4.0;
    for(X=xBegin+h;X<xEnd;X+=h){
        if(X<-R || X>R){
            x.push_back(X);
            y.push_back(sqrt(R*R-pow(sqrt(abs(X)-R),4)));
        }
        else{
            x.push_back(-R);
            y.push_back(R);
            x.push_back(-R);
            y.push_back(H);
            x.push_back(R);
            y.push_back(H);
            x.push_back(R);
            y.push_back(R);
            X=R+h;
        }
    }

    h*=5;
    for(X=-R;X<=R;X+=h){
        x3.push_back(X);
        y3.push_back(sqrt(R*R-(X+R)*(X+R)));
        x3.push_back(X);
        y3.push_back(sqrt(R*R-(X-R)*(X-R)));
    }

    for(X=xBegin;X<=xEnd;X+=h){
        x3.push_back(X);
        y3.push_back(-sqrt(R*R-(X+R)*(X+R)));
        x3.push_back(X);
        y3.push_back(-sqrt(R*R-(X-R)*(X-R)));
    }



    x2.push_back(-R);
    y2.push_back(0);
    x2.push_back(R);
    y2.push_back(0);

    DrawGraph();
}

void ThirdWindow::DrawParabolic()
{
    DrawPerimeter();
    C = (-4.0*H)/(B*B);
    for(X=xBegin;X<=xEnd;X+=h){
            x.push_back(X);
            y.push_back(C*X*X+H);
    }

    DrawGraph();
}

void ThirdWindow::DrawRoot()
{
    DrawPerimeter();
    C = H/sqrt(B);
    for(X=xBegin;X<=xEnd;X+=h){
            x.push_back(X);
            y.push_back(C*sqrt(X+B/2.0));
    }

    DrawGraph();
}

void ThirdWindow::DrawElliptical()
{
    DrawPerimeter();
    C = sqrt(((B*B)/4.0) - H*H);
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(H*sqrt(1-(4*X*X)/(B*B)));
    }

    x2.push_back(-C);
    y2.push_back(0);
    x2.push_back(C);
    y2.push_back(0);

    DrawGraph();
}

void ThirdWindow::DrawCycloid()
{
    DrawPerimeter();
    R=B/(2*3.14);
    for(X=-2*3.14;X<=0;X+=0.01){
        x.push_back(R*(X+3.14)-R*sin(X));
        y.push_back(R-R*cos(X));
    }

    DrawGraph();
}


void ThirdWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document...", qApp->applicationDirPath(), "*.pdf");
    if (!fileName.isEmpty())
    {
          ui->widget->savePdf(fileName);
    }
}

void ThirdWindow::DrawGraph()
{
    ui->widget->addGraph();
    QPen Pen1;
    Pen1.setWidthF(3);
    Pen1.setColor(Qt::blue);
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(0)->setPen(Pen1);

    ui->widget->addGraph();
    ui->widget->graph(1)->addData(x1,y1);
    ui->widget->graph(1)->setPen(Pen1);

    /*
    ui->widget->addGraph();
    ui->widget->graph(2)->setData(x2, y2);
    ui->widget->graph(2)->setPen(QColor(50, 50, 50, 255));
    ui->widget->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    */

    ui->widget->addGraph();
    ui->widget->graph(2)->setData(x2, y2);
    QCPScatterStyle myScatter; //описывает точки
    myScatter.setShape(QCPScatterStyle::ssPlus);//тип точки
    myScatter.setPen(QPen(Qt::red)); //внешний цвет точки
    myScatter.setSize(10);  //размер точки
    ui->widget->graph(2)->setScatterStyle(myScatter);
    ui->widget->graph(2)->setLineStyle(QCPGraph::lsNone); //убирает линию

    ui->widget->addGraph();
    ui->widget->graph(3)->addData(x3,y3);
    QCPScatterStyle myScatter2; //описывает точки
    myScatter2.setShape(QCPScatterStyle::ssDisc);//тип точки
    myScatter2.setPen(QPen(Qt::red)); //внешний цвет точки
    myScatter2.setSize(2);  //размер точки
    ui->widget->graph(3)->setScatterStyle(myScatter2);
    ui->widget->graph(3)->setLineStyle(QCPGraph::lsNone);
    ui->widget->replot();
}
