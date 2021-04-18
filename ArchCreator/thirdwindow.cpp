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

    ui->widget->xAxis2->setVisible(true);
    ui->widget->yAxis2->setVisible(true);
    ui->widget->xAxis2->setTickLabels(false);
    ui->widget->yAxis2->setTickLabels(false);

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

    ui->widget->axisRect()->setupFullAxesBox();

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

    setWindowTitle(Name);


    QCPItemLine *arrow_A = new QCPItemLine(ui->widget);
    arrow_A->start->setCoords(-0.625*B, -A);
    arrow_A->end->setCoords(-0.625*B, 0);
    arrow_A->setHead(QCPLineEnding::esSpikeArrow);
    arrow_A->setTail(QCPLineEnding::esSpikeArrow);

    QString str_A=QString("%1").arg(A);
    QCPItemText *Text_A = new QCPItemText(ui->widget);
    Text_A->position->setCoords(-0.7*B, -A/2.0);
    Text_A->setRotation(-90);
    Text_A->setText(str_A);
    Text_A->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_B = new QCPItemLine(ui->widget);
    arrow_B->start->setCoords(-0.5*B, -A-0.125*B);
    arrow_B->end->setCoords(0.5*B, -A-0.125*B);
    arrow_B->setHead(QCPLineEnding::esSpikeArrow);
    arrow_B->setTail(QCPLineEnding::esSpikeArrow);

    QString str_B=QString("%1").arg(B);
    QCPItemText *Text_B = new QCPItemText(ui->widget);
    Text_B->position->setCoords(0, -A-0.2*B);//esrdgfh
    Text_B->setText(str_B);
    Text_B->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_H = new QCPItemLine(ui->widget);
    arrow_H->start->setCoords(-0.625*B, 0);
    arrow_H->end->setCoords(-0.625*B, H);
    arrow_H->setHead(QCPLineEnding::esSpikeArrow);
    arrow_H->setTail(QCPLineEnding::esSpikeArrow);

    QString str_H=QString("%1").arg(H);
    QCPItemText *Text_H = new QCPItemText(ui->widget);
    Text_H->position->setCoords(-0.7*B, H/2.0);
    Text_H->setRotation(-90);
    Text_H->setText(str_H);
    Text_H->setFont(QFont(font().family(), 10));

    ui->widget->replot();
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
    Name = "Круговая арка";
    DrawPerimeter();
    R=B/2.0;
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(sqrt(R*R-X*X));
    }

    for(X=xBegin;X<=xEnd;X+=h){
        x3.push_back(X);
        y3.push_back(-sqrt(R*R-X*X));
    }

    x2.push_back(0);
    y2.push_back(0);

    DrawGraph();

    QString str_R=QString("%1").arg(R);

    QCPItemLine *arrow_R1 = new QCPItemLine(ui->widget);
    arrow_R1->start->setCoords(0, 0);
    arrow_R1->end->setCoords(0, R);
    arrow_R1->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R1 = new QCPItemText(ui->widget);
    Text_R1->position->setCoords(-0.075*B, H/2.0);
    Text_R1->setRotation(-90);
    Text_R1->setText(str_R);
    Text_R1->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R2 = new QCPItemLine(ui->widget);
    arrow_R2->start->setCoords(0, 0);
    arrow_R2->end->setCoords(R, 0);
    arrow_R2->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R2 = new QCPItemText(ui->widget);
    Text_R2->position->setCoords(0.25*B,-0.075*B);
    Text_R2->setText(str_R);
    Text_R2->setFont(QFont(font().family(), 10));
}

void ThirdWindow::DraweSegment()
{
    Name = "Сегментная арка";
    DrawPerimeter();
    C = ((B*B)/4.0-H*H)/(2.0*H);
    R = H+C;
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(sqrt(R*R-X*X)-C);
    }

    for(X=-R;X<=R;X+=h){
        x3.push_back(X);
        y3.push_back(-sqrt(R*R-X*X)-C);
    }

    for(X=-R;X<=xBegin;X+=h){
        x4.push_back(X);
        y4.push_back(sqrt(R*R-X*X)-C);
    }

    for(X=xEnd;X<=R;X+=h){
        x5.push_back(X);
        y5.push_back(sqrt(R*R-X*X)-C);
    }


    x2.push_back(0);
    y2.push_back(-C);

    DrawGraph();

    dx=(0.075*2*B*C)/sqrt(B*B+4*C*C);
    dy=dx*B/(2*C);

    QString str_R=QString("%1").arg(R, 0, 'f', 0);

    QCPItemLine *arrow_R1 = new QCPItemLine(ui->widget);
    arrow_R1->start->setCoords(0, -C);
    arrow_R1->end->setCoords(B/2.0, 0);
    arrow_R1->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R1 = new QCPItemText(ui->widget);
    Text_R1->position->setCoords(0.25*B+dx, -0.5*C-dy);
    Text_R1->setRotation(-atan(C/(B/2.0))*180/M_PI);
    Text_R1->setText(str_R);
    Text_R1->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R2 = new QCPItemLine(ui->widget);
    arrow_R2->start->setCoords(0, -C);
    arrow_R2->end->setCoords(-B/2.0, 0);
    arrow_R2->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R2 = new QCPItemText(ui->widget);
    Text_R2->position->setCoords(-0.25*B-dx,-0.5*C-dy);
    Text_R2->setRotation(atan(C/(B/2.0))*180/M_PI);
    Text_R2->setText(str_R);
    Text_R2->setFont(QFont(font().family(), 10));
}

void ThirdWindow::DraweLancet()
{
    Name = "Стрельчатая арка";
    DrawPerimeter();
    C = (H*H-(B*B)/4.0)/B;
    R = B/2.0 + C;
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(sqrt(R*R-(abs(X)+C)*(abs(X)+C)));
    }

    for(Y=-H;Y<=0;Y+=h){
        x3.push_back(sqrt(R*R-Y*Y)-C);
        y3.push_back(Y);
        x3.push_back(C-sqrt(R*R-Y*Y));
        y3.push_back(Y);
    }

    for(Y=H;Y<=R;Y+=h){
        x4.push_back(sqrt(R*R-Y*Y)-C);
        y4.push_back(Y);
        x4.push_back(C-sqrt(R*R-Y*Y));
        y4.push_back(Y);
    }

    for(Y=-R;Y<=-H;Y+=h){
        x5.push_back(sqrt(R*R-Y*Y)-C);
        y5.push_back(Y);
        x5.push_back(C-sqrt(R*R-Y*Y));
        y5.push_back(Y);
    }

    x2.push_back(-C);
    y2.push_back(0);
    x2.push_back(C);
    y2.push_back(0);

    DrawGraph();

    dx=(0.075*B*C)/sqrt(H*H+C*C);
    dy=dx*H/C;

    QString str_R=QString("%1").arg(R, 0, 'f', 0);

    QCPItemLine *arrow_R1 = new QCPItemLine(ui->widget);
    arrow_R1->start->setCoords(-C, 0);
    arrow_R1->end->setCoords(B/2.0, 0);
    arrow_R1->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R1 = new QCPItemText(ui->widget);
    Text_R1->position->setCoords((-C+(B/2.0))/2.0, -0.075*B);
    Text_R1->setText(str_R);
    Text_R1->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R2 = new QCPItemLine(ui->widget);
    arrow_R2->start->setCoords(-C, 0);
    arrow_R2->end->setCoords(0, H);
    arrow_R2->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R2 = new QCPItemText(ui->widget);
    Text_R2->position->setCoords(-0.5*C-dx,0.5*H+dy);
    Text_R2->setRotation(-atan(H/C)*180/M_PI);
    Text_R2->setText(str_R);
    Text_R2->setFont(QFont(font().family(), 10));
}

void ThirdWindow::DraweShamrock()
{
    Name = "Арка в форме трилисника";
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

    for(X=-R;X<=R;X+=h){
        x3.push_back(X);
        y3.push_back(R-sqrt(R*R-X*X));
        x4.push_back(X);
        y4.push_back(sqrt(R*R-(abs(X)-R)*(abs(X)-R)));
    }

    for(X=xBegin;X<=xEnd;X+=h){
        x5.push_back(X);
        y5.push_back(-sqrt(R*R-(abs(X)-R)*(abs(X)-R)));
    }

    x2.push_back(-R);
    y2.push_back(0);
    x2.push_back(0);
    y2.push_back(R);
    x2.push_back(R);
    y2.push_back(0);

    DrawGraph();

    QString str_R=QString("%1").arg(R, 0, 'f', 0);

    QCPItemLine *arrow_R1 = new QCPItemLine(ui->widget);
    arrow_R1->start->setCoords(-R, 0);
    arrow_R1->end->setCoords(-B/2.0, 0);
    arrow_R1->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R1 = new QCPItemText(ui->widget);
    Text_R1->position->setCoords((-R-(B/2.0))/2.0, -0.075*B);
    Text_R1->setText(str_R);
    Text_R1->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R2 = new QCPItemLine(ui->widget);
    arrow_R2->start->setCoords(-R, 0);
    arrow_R2->end->setCoords(-R, R);
    arrow_R2->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R2 = new QCPItemText(ui->widget);
    Text_R2->position->setCoords(-R-0.075*B,0.5*R);
    Text_R2->setRotation(-90);
    Text_R2->setText(str_R);
    Text_R2->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R3 = new QCPItemLine(ui->widget);
    arrow_R3->start->setCoords(R, 0);
    arrow_R3->end->setCoords(B/2.0, 0);
    arrow_R3->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R3 = new QCPItemText(ui->widget);
    Text_R3->position->setCoords((R+(B/2.0))/2.0, -0.075*B);
    Text_R3->setText(str_R);
    Text_R3->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R4 = new QCPItemLine(ui->widget);
    arrow_R4->start->setCoords(R, 0);
    arrow_R4->end->setCoords(R, R);
    arrow_R4->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R4 = new QCPItemText(ui->widget);
    Text_R4->position->setCoords(R+0.075*B,0.5*R);
    Text_R4->setRotation(90);
    Text_R4->setText(str_R);
    Text_R4->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R5 = new QCPItemLine(ui->widget);
    arrow_R5->start->setCoords(0, R);
    arrow_R5->end->setCoords(-R, R);
    arrow_R5->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R5 = new QCPItemText(ui->widget);
    Text_R5->position->setCoords(-R/2.0, R-0.075*B);
    Text_R5->setText(str_R);
    Text_R5->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R6 = new QCPItemLine(ui->widget);
    arrow_R6->start->setCoords(0, R);
    arrow_R6->end->setCoords(R, R);
    arrow_R6->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R6 = new QCPItemText(ui->widget);
    Text_R6->position->setCoords(R/2.0, R-0.075*B);
    Text_R6->setText(str_R);
    Text_R6->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R7 = new QCPItemLine(ui->widget);
    arrow_R7->start->setCoords(0, R);
    arrow_R7->end->setCoords(0, H);
    arrow_R7->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R7 = new QCPItemText(ui->widget);
    Text_R7->position->setCoords(-0.075*B, 0.375*B);
    Text_R7->setRotation(-90);
    Text_R7->setText(str_R);
    Text_R7->setFont(QFont(font().family(), 10));
}

void ThirdWindow::DraweInflexed()
{
    Name = "Арка в форме занавеса";
    DrawPerimeter();
    R = (H*H+(B*B)/4.0)/(2.0*H);
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(R-sqrt(R*R-pow(sqrt(-(abs(X)-B/2.0)),4)));
    }

    for(X=-2*R;X<=2*R;X+=h){
        x3.push_back(X);
        y3.push_back(R-sqrt(R*R-pow(sqrt((abs(X)-B/2.0)),4)));
        x4.push_back(X);
        y4.push_back(R-sqrt(R*R-pow(sqrt((abs(X)+B/2.0)),4)));
    }

    x2.push_back(xBegin);
    y2.push_back(R);
    x2.push_back(xEnd);
    y2.push_back(R);

    DrawGraph();
}

void ThirdWindow::DrawShouldered_flat()
{
    Name = "Арка в форме плеча";
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

    for(X=-R;X<=R;X+=h){
        x4.push_back(X);
        y4.push_back(sqrt(R*R-(abs(X)-R)*(abs(X)-R)));
    }

    for(X=xBegin;X<=xEnd;X+=h){
        x5.push_back(X);
        y5.push_back(-sqrt(R*R-(abs(X)-R)*(abs(X)-R)));
    }



    x2.push_back(-R);
    y2.push_back(0);
    x2.push_back(R);
    y2.push_back(0);

    DrawGraph();

    QString str_R=QString("%1").arg(R, 0, 'f', 0);
    QString str_H1=QString("%1").arg(H-R, 0, 'f', 0);
    QString str_B1=QString("%1").arg(B/2.0, 0, 'f', 0);

    QCPItemLine *arrow_R1 = new QCPItemLine(ui->widget);
    arrow_R1->start->setCoords(-R, 0);
    arrow_R1->end->setCoords(-B/2.0, 0);
    arrow_R1->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R1 = new QCPItemText(ui->widget);
    Text_R1->position->setCoords((-R-(B/2.0))/2.0, -0.075*B);
    Text_R1->setText(str_R);
    Text_R1->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R2 = new QCPItemLine(ui->widget);
    arrow_R2->start->setCoords(-R, 0);
    arrow_R2->end->setCoords(-R, R);
    arrow_R2->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R2 = new QCPItemText(ui->widget);
    Text_R2->position->setCoords(-R-0.075*B,0.5*R);
    Text_R2->setRotation(-90);
    Text_R2->setText(str_R);
    Text_R2->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R3 = new QCPItemLine(ui->widget);
    arrow_R3->start->setCoords(R, 0);
    arrow_R3->end->setCoords(B/2.0, 0);
    arrow_R3->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R3 = new QCPItemText(ui->widget);
    Text_R3->position->setCoords((R+(B/2.0))/2.0, -0.075*B);
    Text_R3->setText(str_R);
    Text_R3->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R4 = new QCPItemLine(ui->widget);
    arrow_R4->start->setCoords(R, 0);
    arrow_R4->end->setCoords(R, R);
    arrow_R4->setHead(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R4 = new QCPItemText(ui->widget);
    Text_R4->position->setCoords(R+0.075*B,0.5*R);
    Text_R4->setRotation(90);
    Text_R4->setText(str_R);
    Text_R4->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R5 = new QCPItemLine(ui->widget);
    arrow_R5->start->setCoords(R+0.125*B, R);
    arrow_R5->end->setCoords(R+0.125*B, H);
    arrow_R5->setHead(QCPLineEnding::esSpikeArrow);
    arrow_R5->setTail(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R5 = new QCPItemText(ui->widget);
    Text_R5->position->setCoords(R+0.2*B, (H+R)/2.0);
    Text_R5->setRotation(90);
    Text_R5->setText(str_H1);
    Text_R5->setFont(QFont(font().family(), 10));

    QCPItemLine *arrow_R6 = new QCPItemLine(ui->widget);
    arrow_R6->start->setCoords(-R, H+0.125*B);
    arrow_R6->end->setCoords(R, H+0.125*B);
    arrow_R6->setHead(QCPLineEnding::esSpikeArrow);
    arrow_R6->setTail(QCPLineEnding::esSpikeArrow);

    QCPItemText *Text_R6 = new QCPItemText(ui->widget);
    Text_R6->position->setCoords(0, H+0.2*B);
    Text_R6->setText(str_B1);
    Text_R6->setFont(QFont(font().family(), 10));
}

void ThirdWindow::DrawParabolic()
{
    Name = "Параболическая арка";
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
    Name = "Арка в форме квадратного корня";
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
    Name = "Эллиптическая арка";
    DrawPerimeter();    
    for(X=xBegin;X<=xEnd;X+=h){
        x.push_back(X);
        y.push_back(H*sqrt(1-(4*X*X)/(B*B)));
    }

    for(X=xBegin;X<=xEnd;X+=h){
        x3.push_back(X);
        y3.push_back(-H*sqrt(1-(4*X*X)/(B*B)));
    }

    if(H<=B/2.0){
        C = sqrt(((B*B)/4.0) - H*H);
        x2.push_back(-C);
        y2.push_back(0);
        x2.push_back(C);
        y2.push_back(0);
    }
    else{
        C = sqrt(H*H - ((B*B)/4.0));
        x2.push_back(0);
        y2.push_back(-C);
        x2.push_back(0);
        y2.push_back(C);
    }

    DrawGraph();
}

void ThirdWindow::DrawCycloid()
{
    Name = "Циклоидная арка";
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
    QPen Pen1;
    Pen1.setWidthF(3);
    Pen1.setColor(Qt::blue);

    QCPScatterStyle Scatter1; //описывает точки
    Scatter1.setShape(QCPScatterStyle::ssPlus);//тип точки
    Scatter1.setPen(QPen(Qt::red)); //внешний цвет точки
    Scatter1.setSize(10);  //размер точки

    QPen Pen2;
    Pen2.setWidthF(3);
    Pen2.setColor(Qt::red);
    Pen2.setStyle(Qt::DashLine);

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->graph(0)->setPen(Pen1);

    ui->widget->addGraph();
    ui->widget->graph(1)->addData(x1,y1);
    ui->widget->graph(1)->setPen(Pen1);

    ui->widget->addGraph();
    ui->widget->graph(2)->setData(x2, y2);
    ui->widget->graph(2)->setScatterStyle(Scatter1);
    ui->widget->graph(2)->setLineStyle(QCPGraph::lsNone); //убирает линию

    ui->widget->addGraph();
    ui->widget->graph(3)->addData(x3,y3);   
    ui->widget->graph(3)->setPen(Pen2);

    ui->widget->addGraph();
    ui->widget->graph(4)->addData(x4,y4);
    ui->widget->graph(4)->setPen(Pen2);

    ui->widget->addGraph();
    ui->widget->graph(5)->addData(x5,y5);
    ui->widget->graph(5)->setPen(Pen2);
}
