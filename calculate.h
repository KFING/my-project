#ifndef CALCULATE_H
#define CALCULATE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calculate; }
QT_END_NAMESPACE

class calculate : public QMainWindow
{
    Q_OBJECT

public:
    calculate(QWidget *parent = nullptr);
    ~calculate();

private:
    Ui::calculate *ui;
private slots:
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_ac_clicked();
    void on_pushButton_exec_clicked();
    void math_operations();
};
#endif // CALCULATE_H
