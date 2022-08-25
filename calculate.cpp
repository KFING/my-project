#include <QFile>
#include <QMessageBox>
#include<QFileDialog>
#include<QTextEdit>

#include "calculate.h"
#include "ui_calculate.h"
#include "sourcemathoperation.cpp"
#include "decHex.cpp"
#include "DecBin.cpp"

int counterC = 0;

calculate::calculate(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculate)
{
    ui->setupUi(this);
    integral_ = new integralss();
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_pro,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(on_pushButton_13_clicked()));
    connect(ui->pushButton_dis,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));

    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(triganomentation()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(triganomentation()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(triganomentation()));
    connect(ui->pushButton_ctan,SIGNAL(clicked()),this,SLOT(triganomentation()));
    connect(ui->pushButton_Y,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_V,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_decr,SIGNAL(clicked()),this,SLOT(decrementoper()));

    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(on_pushButton_11_clicked()));
    connect(ui->pushButton_integrals,SIGNAL(clicked()),this,SLOT(on_pushButton_integrals_clicked()));


}

calculate::~calculate()
{
    delete ui;
}

void calculate::digits_numbers(){
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    new_label = ui->result_show->toPlainText() + button->text();

    ui->result_show->setText( new_label );
}

void calculate::on_pushButton_dot_clicked()
{
    if(counterC == 0){
    ui->result_show->setText( ui->result_show->toPlainText() + '.' );
    }
    counterC = 1;
}
void calculate::operations(){
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    new_label = ui->result_show->toPlainText() + button->text();
    ui->result_show->setText( new_label );
}

void calculate::on_pushButton_ac_clicked()
{
    ui->result_show->setText("");

}


void calculate::on_pushButton_exec_clicked()
{
    QString str;
    QString str1;
    str1 = ui->result_show->toPlainText();
    std::string s = str1.toStdString();
    if (s != "")
    {
        OPN strP = s;
        str = QString::fromStdString(strP.Calculate());
        ui->answer->setText(str);
        QFile logFile("C:\\Users\\IT-baby\\Desktop\\calculate\\calculate\\history_calculate.txt");
        if(logFile.open(QIODevice::Append|QIODevice::Text))
        {
            QTextStream outLog(&logFile);
            outLog<<str1<<'='<<'\n';
            outLog<<str<<'\n';
        }
        logFile.close();
    }
}


void calculate::math_operations(){
    counterC = 0;
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    new_label = ui->result_show->toPlainText() + button->text();
    ui->result_show->setText( new_label );
}


void calculate::on_pushButton_13_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    new_label = ui->result_show->toPlainText() + button->text();
    ui->result_show->setText( new_label );
}

void calculate::decrementoper()
{
    QString str = ui->result_show->toPlainText();
    str.chop(1);
    ui->result_show->setText(str);
}
void calculate::triganomentation()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    if(button->text() == "ctan"){
        new_label = ui->result_show->toPlainText() + "1/tan(";
    }
    else new_label = ui->result_show->toPlainText() + button->text() + "(";
    ui->result_show->setText( new_label );
}


void calculate::on_pushButton_10_clicked()
{
    QString str;
    str = ui->result_show->toPlainText();
    std::string s = str.toStdString();
    OPN strP = s;
    str = QString::fromStdString(strP.Calculate());
    ui->answer->setText(str);
    if (!(ui->answer->text() == QString::fromStdString("Input error!")))
    {
        QString str = ui->answer->text();
        std::string hexNum  = str.toStdString();
        int numHex = stoi(hexNum);
        hexNum = DecHex(numHex);
        str = QString::fromStdString(hexNum);
        ui->answer->setText(str);
    }
}


void calculate::on_pushButton_11_clicked()
{
    QString str;
    str = ui->result_show->toPlainText();
    std::string s = str.toStdString();
    OPN strP = s;
    str = QString::fromStdString(strP.Calculate());
    ui->answer->setText(str);
    if (!(ui->answer->text() == QString::fromStdString("Input error!")))
    {
        QString str = ui->answer->text();
        std::string binNum  = str.toStdString();
        int numBin = stoi(binNum);
        binNum = decBin(numBin);
        str = QString::fromStdString(binNum);
        ui->answer->setText(str);
    }
}


void calculate::on_pushButton_clicked()
{
    QString fileName = "C:\\Users\\IT-baby\\Desktop\\calculate\\calculate\\history_calculate.txt";
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->result_show->setText(text);
    file.close();
}


void calculate::on_pushButton_15_clicked()
{
    QFile file("C:\\Users\\IT-baby\\Desktop\\calculate\\calculate\\history_calculate.txt");
    file.resize(0);
}


void calculate::on_pushButton_integrals_clicked()
{
    integral_->show();
}


