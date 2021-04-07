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

    Write_to_file();

    if(h>b/2){
        log2 = "image: url(:/new/lancet.PNG);";
        lancet = ui->pushButton_4;
        lancet ->setStyleSheet(log2);
    }
    else if(h<b/2){
        log2 = "image: url(:/new/segment.PNG);";
        segment = ui->pushButton_3;
        segment ->setStyleSheet(log2);
    }
    else{
        log2 = "image: url(:/new/semicircle.PNG);";
        semicircle = ui->pushButton_2;
        semicircle ->setStyleSheet(log2);
        log2 = "image: url(:/new/shamrock.PNG);";
        shamrock = ui->pushButton_5;
        shamrock ->setStyleSheet(log2);
    }
}

void SecondWindow::on_pushButton_2_clicked()
{
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

    stream << h << " " << b << " " << a << endl;

    file.close();
}
