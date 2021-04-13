#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

}

SecondWindow::~SecondWindow()
{
    delete ui;
}


void SecondWindow::on_pushButton_clicked()
{

    QString arrow = ui->arrow->text();
    h = arrow.toInt();
    QString height = ui->height->text();
    a = height.toInt();
    QString width = ui->width->text();
    b = width.toInt();

    if(h>b/2){
        log2 = "image: url(:/new/lancet.PNG);";
        lancet = ui->pushButton_4;
        lancet ->setStyleSheet(log2);
        log2 = "image: url(:/new/shouldered_flat.png);";
        shouldered_flat = ui->pushButton_6;
        shouldered_flat ->setStyleSheet(log2);
    }
    else if(h<b/2){
        log2 = "image: url(:/new/segment.PNG);";
        segment = ui->pushButton_3;
        segment ->setStyleSheet(log2);
        log2 = "image: url(:/new/Inflexed.png);";
        inflexed = ui->pushButton_8;
        inflexed ->setStyleSheet(log2);
    }
    else{
        log2 = "image: url(:/new/semicircle.PNG);";
        semicircle = ui->pushButton_2;
        semicircle ->setStyleSheet(log2);
        log2 = "image: url(:/new/shamrock.PNG);";
        shamrock = ui->pushButton_5;
        shamrock ->setStyleSheet(log2);
        log2 = "image: url(:/new/Inflexed.png);";
        inflexed = ui->pushButton_8;
        inflexed ->setStyleSheet(log2);
    }
}

void SecondWindow::on_pushButton_2_clicked()
{
    n=1;
    Write_to_file();
    window3 = new ThirdWindow(this);
    window3->show();
}

void SecondWindow::Write_to_file()
{
    QFile file(".//data.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::information(this,"Error","Path not correct!");
        return;
    }

    QTextStream stream(&file);

    stream << n << " " << h << " " << b << " " << a;

    file.close();
}

void SecondWindow::on_pushButton_4_clicked()
{
    n=3;
    Write_to_file();
    window3 = new ThirdWindow(this);
    window3->show();

}

void SecondWindow::on_pushButton_3_clicked()
{
    n=2;
    Write_to_file();
    window3 = new ThirdWindow(this);
    window3->show();
}

void SecondWindow::on_pushButton_5_clicked()
{
    n=4;
    Write_to_file();
    window3 = new ThirdWindow(this);
    window3->show();
}

void SecondWindow::on_pushButton_8_clicked()
{
    n=5;
    Write_to_file();
    window3 = new ThirdWindow(this);
    window3->show();
}

void SecondWindow::on_pushButton_6_clicked()
{
    n=6;
    Write_to_file();
    window3 = new ThirdWindow(this);
    window3->show();
}
