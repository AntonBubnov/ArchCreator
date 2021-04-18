#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    setWindowTitle("Каталог");

    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_13->setEnabled(false);

    Arch = "image: url(:/new/Круговая_1.jpg);";
    semicircle = ui->pushButton_2;
    semicircle ->setStyleSheet(Arch);

    Arch = "image: url(:/new/Сегментная_1.jpg);";
    segment = ui->pushButton_3;
    segment ->setStyleSheet(Arch);

    Arch = "image: url(:/new/Стрельчатая_1.jpg);";
    lancet = ui->pushButton_4;
    lancet ->setStyleSheet(Arch);

    Arch = "image: url(:/new/Трилисник_1.jpg);";
    shamrock = ui->pushButton_5;
    shamrock ->setStyleSheet(Arch);

    Arch = "image: url(:/new/Плечо_1.jpg);";
    shouldered_flat = ui->pushButton_6;
    shouldered_flat ->setStyleSheet(Arch);

    Arch = "image: url(:/new/Корень_1.jpg);";
    root = ui->pushButton_7;
    root ->setStyleSheet(Arch);

    Arch = "image: url(:/new/Занавеса_1.jpg);";
    inflexed = ui->pushButton_8;
    inflexed ->setStyleSheet(Arch);

    Arch = "image: url(:/new/Парабола_1.jpg);";
    parabolic = ui->pushButton_9;
    parabolic ->setStyleSheet(Arch);

    Arch = "image: url(:/new/Эллипс_1.jpg);";
    cycloid = ui->pushButton_10;
    cycloid ->setStyleSheet(Arch);

    Arch = "image: url(:/new/Эллипс_1.jpg);";
    elliptical = ui->pushButton_12;
    elliptical ->setStyleSheet(Arch);
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

    if(h>=1 && b>=1 && a>=1 && h<=10000 && b<=10000 && a<=10000){
        ui->pushButton_7->setEnabled(true);
        Arch = "image: url(:/new/Корень.jpg);";
        root = ui->pushButton_7;
        root ->setStyleSheet(Arch);

        ui->pushButton_9->setEnabled(true);
        Arch = "image: url(:/new/Парабола.jpg);";
        parabolic = ui->pushButton_9;
        parabolic ->setStyleSheet(Arch);

        if(h==b/2){
            ui->pushButton_2->setEnabled(true);
            Arch = "image: url(:/new/Круговая.jpg);";
            semicircle = ui->pushButton_2;
            semicircle ->setStyleSheet(Arch);

            ui->pushButton_5->setEnabled(true);
            Arch = "image: url(:/new/Трилисник.jpg);";
            shamrock = ui->pushButton_5;
            shamrock ->setStyleSheet(Arch);

            ui->pushButton_12->setEnabled(false);
            Arch = "image: url(:/new/Эллипс_1.jpg);";
            elliptical = ui->pushButton_12;
            elliptical ->setStyleSheet(Arch);
        }
        else{
            ui->pushButton_2->setEnabled(false);
            Arch = "image: url(:/new/Круговая_1.jpg);";
            semicircle = ui->pushButton_2;
            semicircle ->setStyleSheet(Arch);

            ui->pushButton_5->setEnabled(false);
            Arch = "image: url(:/new/Трилисник_1.jpg);";
            shamrock = ui->pushButton_5;
            shamrock ->setStyleSheet(Arch);

            ui->pushButton_12->setEnabled(true);
            Arch = "image: url(:/new/Эллипс.jpg);";
            elliptical = ui->pushButton_12;
            elliptical ->setStyleSheet(Arch);
        }

        if(h>b/2){
            ui->pushButton_4->setEnabled(true);
            Arch = "image: url(:/new/Стрельчатая.jpg);";
            lancet = ui->pushButton_4;
            lancet ->setStyleSheet(Arch);

            ui->pushButton_8->setEnabled(false);
            Arch = "image: url(:/new/Занавеса_1.jpg);";
            inflexed = ui->pushButton_8;
            inflexed ->setStyleSheet(Arch);
        }
        else{
            ui->pushButton_4->setEnabled(false);
            Arch = "image: url(:/new/Стрельчатая_1.jpg);";
            lancet = ui->pushButton_4;
            lancet ->setStyleSheet(Arch);

            ui->pushButton_8->setEnabled(true);
            Arch = "image: url(:/new/Занавеса.jpg);";
            inflexed = ui->pushButton_8;
            inflexed ->setStyleSheet(Arch);
        }

        if(h>=b/4){
            ui->pushButton_6->setEnabled(true);
            Arch = "image: url(:/new/Плечо.jpg);";
            shouldered_flat = ui->pushButton_6;
            shouldered_flat ->setStyleSheet(Arch);
        }
        else{
            ui->pushButton_6->setEnabled(false);
            Arch = "image: url(:/new/Плечо_1.jpg);";
            shouldered_flat = ui->pushButton_6;
            shouldered_flat ->setStyleSheet(Arch);
        }

        if(h>=b/M_PI-1 && h<=b/M_PI+1){
            ui->pushButton_10->setEnabled(true);
            Arch = "image: url(:/new/Эллипс.jpg);";
            cycloid = ui->pushButton_10;
            cycloid ->setStyleSheet(Arch);
        }
        else{
            ui->pushButton_10->setEnabled(false);
            Arch = "image: url(:/new/Эллипс_1.jpg);";
            cycloid = ui->pushButton_10;
            cycloid ->setStyleSheet(Arch);
        }

        if(h<b/2){
            ui->pushButton_3->setEnabled(true);
            Arch = "image: url(:/new/Сегментная.jpg);";
            segment = ui->pushButton_3;
            segment ->setStyleSheet(Arch);
        }
        else{
            ui->pushButton_3->setEnabled(false);
            Arch = "image: url(:/new/Сегментная_1.jpg);";
            segment = ui->pushButton_3;
            segment ->setStyleSheet(Arch);
        }
    }
    else{
        ui->pushButton_2->setEnabled(false);
        Arch = "image: url(:/new/Круговая_1.jpg);";
        semicircle = ui->pushButton_2;
        semicircle ->setStyleSheet(Arch);

        ui->pushButton_3->setEnabled(false);
        Arch = "image: url(:/new/Сегментная_1.jpg);";
        segment = ui->pushButton_3;
        segment ->setStyleSheet(Arch);

        ui->pushButton_4->setEnabled(false);
        Arch = "image: url(:/new/Стрельчатая_1.jpg);";
        lancet = ui->pushButton_4;
        lancet ->setStyleSheet(Arch);

        ui->pushButton_5->setEnabled(false);
        Arch = "image: url(:/new/Трилисник_1.jpg);";
        shamrock = ui->pushButton_5;
        shamrock ->setStyleSheet(Arch);

        ui->pushButton_6->setEnabled(false);
        Arch = "image: url(:/new/Плечо_1.jpg);";
        shouldered_flat = ui->pushButton_6;
        shouldered_flat ->setStyleSheet(Arch);

        ui->pushButton_7->setEnabled(false);
        Arch = "image: url(:/new/Корень_1.jpg);";
        root = ui->pushButton_7;
        root ->setStyleSheet(Arch);

        ui->pushButton_8->setEnabled(false);
        Arch = "image: url(:/new/Занавеса_1.jpg);";
        inflexed = ui->pushButton_8;
        inflexed ->setStyleSheet(Arch);

        ui->pushButton_9->setEnabled(false);
        Arch = "image: url(:/new/Парабола_1.jpg);";
        parabolic = ui->pushButton_9;
        parabolic ->setStyleSheet(Arch);

        ui->pushButton_10->setEnabled(false);
        Arch = "image: url(:/new/Эллипс_1.jpg);";
        cycloid = ui->pushButton_10;
        cycloid ->setStyleSheet(Arch);

        ui->pushButton_12->setEnabled(false);
        Arch = "image: url(:/new/Эллипс_1.jpg);";
        elliptical = ui->pushButton_12;
        elliptical ->setStyleSheet(Arch);
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

void SecondWindow::on_pushButton_13_clicked()
{
    n=11;
    FormCreation();
}

void SecondWindow::on_pushButton_11_clicked()
{
    n=12;
    FormCreation();
}
