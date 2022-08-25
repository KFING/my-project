#ifndef INTEGRALSS_H
#define INTEGRALSS_H

#include <QMainWindow>

namespace Ui {
class integralss;
}

class integralss : public QMainWindow
{
    Q_OBJECT

public:
    explicit integralss(QWidget *parent = nullptr);
    ~integralss();
private slots:
    void on_pushButton_calc_clicked();
    void on_pushMathOperations();

    void on_pushButton_dot_clicked();

    void on_pushButton_ac_clicked();

    void on_pushButton_decr_clicked();
    void on_triganomenations_Integrals();

private:
    Ui::integralss *ui;
};

#endif // INTEGRALSS_H
