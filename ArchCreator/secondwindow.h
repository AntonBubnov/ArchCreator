#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include "thirdwindow.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    //int value(int X);
    QString value();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SecondWindow *ui;
    QString log2;
    QPushButton *lancet, *segment, *semicircle, *shamrock;
    int h=0, a=0, b=0;
    ThirdWindow *window3;

};

#endif // SECONDWINDOW_H
