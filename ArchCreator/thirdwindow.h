#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ThirdWindow *ui;
    int H, A, B;
    double xBegin, xEnd, h, X, Y, C, R;;
    QVector<double> x, y, x1, y1, x2, x3, y3, x4, y4, x5, y5;
    void DrawPerimeter();
    void ChangeArch();
    void DrowNArch();
    void Read_from_file();
};

#endif // THIRDWINDOW_H
