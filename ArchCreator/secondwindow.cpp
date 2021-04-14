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

    log2 = "image: url(:/new/Парабола.jpg);";
    parabolic = ui->pushButton_9;
    parabolic ->setStyleSheet(log2);

    log2 = "image: url(:/new/Корень.png);";
    root = ui->pushButton_7;
    root ->setStyleSheet(log2);

    if(h<1+b/3.14 && h>-1+b/3.14){
        log2 = "image: url(:/new/cycloid.png);";
        cycloid = ui->pushButton_10;
        cycloid ->setStyleSheet(log2);
    }

    log2 = "image: url(:/new/Эллипс.jpg);";
    elliptical = ui->pushButton_12;
    elliptical ->setStyleSheet(log2);

    if(h>b/2){
        log2 = "image: url(:/new/Стрельчатая.jpg);";
        lancet = ui->pushButton_4;
        lancet ->setStyleSheet(log2);
        log2 = "image: url(:/new/Плечо.jpg);";
        shouldered_flat = ui->pushButton_6;
        shouldered_flat ->setStyleSheet(log2);
    }
    else if(h<b/2){
        log2 = "image: url(:/new/Сегментная.jpg);";
        segment = ui->pushButton_3;
        segment ->setStyleSheet(log2);
        log2 = "image: url(:/new/Занавеса.jpg);";
        inflexed = ui->pushButton_8;
        inflexed ->setStyleSheet(log2);
    }
    else{
        log2 = "image: url(:/new/Круговая.jpg);";
        semicircle = ui->pushButton_2;
        semicircle ->setStyleSheet(log2);
        log2 = "image: url(:/new/Трилисник.jpg);";
        shamrock = ui->pushButton_5;
        shamrock ->setStyleSheet(log2);
        log2 = "image: url(:/new/Занавеса.jpg);";
        inflexed = ui->pushButton_8;
        inflexed ->setStyleSheet(log2);
        log2 = "image: url(:/new/Плечо.jpg);";
        shouldered_flat = ui->pushButton_6;
        shouldered_flat ->setStyleSheet(log2);
    }
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

void SecondWindow::FormCreation()
{
    Write_to_file();
    window3 = new ThirdWindow(this);
    window3->show();
}

void SecondWindow::on_pushButton_2_clicked()
{
    n=1;
    FormCreation();
}

void SecondWindow::on_pushButton_3_clicked()
{
    n=2;
    FormCreation();
}

void SecondWindow::on_pushButton_4_clicked()
{
    n=3;
    FormCreation();
}

void SecondWindow::on_pushButton_5_clicked()
{
    n=4;
    FormCreation();
}

void SecondWindow::on_pushButton_8_clicked()
{
    n=5;
    FormCreation();
}

void SecondWindow::on_pushButton_6_clicked()
{
    n=6;
    FormCreation();
}

void SecondWindow::on_pushButton_9_clicked()
{
    n=7;
    FormCreation();
}

void SecondWindow::on_pushButton_7_clicked()
{
    n=8;
    FormCreation();
}

void SecondWindow::on_pushButton_12_clicked()
{
    n=9;
    FormCreation();
}

void SecondWindow::on_pushButton_10_clicked()
{
    n=10;
    FormCreation();
}
