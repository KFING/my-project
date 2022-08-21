#include "calculate.h"
#include "ui_calculate.h"
#include "SourceForCalculate.cpp"

double num_firstP = 0;
double num_firstM = 1;

calculate::calculate(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculate)
{
    ui->setupUi(this);
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
    connect(ui->pushButton_set,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_pro,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_dis,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));


    ui->pushButton_dis->setCheckable(true);
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_min->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
}

calculate::~calculate()
{
    delete ui;
}

void calculate::digits_numbers(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if(ui->result_show->text().contains(".") && button->text() == "0"){
        new_label = ui->result_show->text() + button->text();
    }else{
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers,'g',15);
    }
    ui->result_show->setText( new_label );
}

void calculate::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.'))){
    ui->result_show->setText( ui->result_show->text() + '.' );
    }
}
void calculate::operations(){
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text()=="+/-")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText( new_label );
    }else     if(button->text()=="%")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers,'g',15);

        ui->result_show->setText( new_label );
    }
}

void calculate::on_pushButton_ac_clicked()
{
    ui->pushButton_dis->setChecked(false);
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_min->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->result_show->setText("0");
    num_firstP = 0;
    num_firstM = 1;

}


void calculate::on_pushButton_exec_clicked()
{
    double  num_second;
    QString new_label;
    num_second = ui->result_show->text().toDouble();


    if(ui->pushButton_plus->isChecked()){
        num_firstP = num_firstP + num_second;
        new_label = QString::number(num_firstP,'g',15);
        ui->result_show->setText( new_label );
        ui->pushButton_plus->setChecked(false);
    }
    else if(ui->pushButton_min->isChecked()){
        num_firstP = num_firstP - num_second;
        new_label = QString::number(num_firstP,'g',15);
        ui->result_show->setText( new_label );
        ui->pushButton_min->setChecked(false);
    }
    else if(ui->pushButton_dis->isChecked()){
        if(num_second == 0){
            ui->result_show->setText("ERROR");
        }else{
        num_firstM =   num_firstM / num_second ;
        new_label = QString::number(num_firstM,'g',15);
        ui->result_show->setText( new_label );
        }ui->pushButton_dis->setChecked(false);
    }else if(ui->pushButton_mul->isChecked()){
        num_firstM = num_firstM * num_second;
        new_label = QString::number(num_firstM,'g',15);
        ui->result_show->setText( new_label );
        ui->pushButton_mul->setChecked(false);
    }
}


void calculate::math_operations(){
    QPushButton *button = (QPushButton *)sender();
    //num_first = ui->result_show->text().toDouble();
    double  num_second;
    num_second = ui->result_show->text().toDouble();

    ui->result_show->setText("");
    button->setChecked(true);
    QString new_label;


    if(ui->pushButton_plus->isChecked()){
        num_firstP = num_firstP + num_second;
        num_firstM = num_firstP;
        new_label = QString::number(num_firstP,'g',15);
        //ui->result_show->setText( new_label );
        ui->pushButton_mul->setChecked(false);
        ui->pushButton_min->setChecked(false);
        ui->pushButton_dis->setChecked(false);
    }
    else if(ui->pushButton_min->isChecked()){
        num_firstP =   num_second - num_firstP;
        num_firstM = num_firstP;
        new_label = QString::number(num_firstP,'g',15);
        //ui->result_show->setText( new_label );
        ui->pushButton_mul->setChecked(false);
        ui->pushButton_plus->setChecked(false);
        ui->pushButton_dis->setChecked(false);
    }
    else if(ui->pushButton_dis->isChecked()){
        if(num_second == 0){
            ui->result_show->setText("ERROR");
        }else{
        num_firstM = num_firstM / num_second;
        num_firstP = num_firstM;
        new_label = QString::number(num_firstM,'g',15);
        //ui->result_show->setText( new_label );
        }
        ui->pushButton_mul->setChecked(false);
        ui->pushButton_min->setChecked(false);
        ui->pushButton_plus->setChecked(false);
    }else if(ui->pushButton_mul->isChecked()){
        num_firstM = num_firstM * num_second;
        num_firstP = num_firstM;
        new_label = QString::number(num_firstM,'g',15);
        //ui->result_show->setText( new_label );
        ui->pushButton_plus->setChecked(false);
        ui->pushButton_min->setChecked(false);
        ui->pushButton_dis->setChecked(false);
    }

}

