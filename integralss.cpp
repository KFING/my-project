#include "integralss.h"
#include "ui_integralss.h"
#include "sourcemathoperation.cpp"

int counterI = 0;

std::string lettersI = "qweryuipdfghjklzxvbmsincota";
std::string lettersFunc = "qweryuipdfghjklzvbm";

integralss::integralss(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::integralss)
{
    ui->setupUi(this);
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));

    connect(ui->pushButton_pro,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_dis,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_mul,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_min,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_Y,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));
    connect(ui->pushButton_V,SIGNAL(clicked()),this,SLOT(on_pushMathOperations()));

    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(on_triganomenations_Integrals()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(on_triganomenations_Integrals()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(on_triganomenations_Integrals()));
    connect(ui->pushButton_ctan,SIGNAL(clicked()),this,SLOT(on_triganomenations_Integrals()));
}

integralss::~integralss()
{
    delete ui;
}
void integralss::on_pushButton_calc_clicked()
{
    QString Qfunc = ui->function->toPlainText();
    QString QlowerLimit = ui->lower_limit->toPlainText();
    QString QapperLimit = ui->upper_limit->toPlainText();
    QString Qaccuracy = ui->accuracy->toPlainText();
    QString QresultI;
    std::string result;
    std::string temp;
    std::string str;
    std::string apper_limit =  QapperLimit.toStdString();
    std::string lower_limit = QlowerLimit.toStdString();
    std::string accuracy = Qaccuracy.toStdString();
    int counterErrorI = 0;
    std::string func = Qfunc.toStdString();
    std::string commonString = apper_limit + lower_limit + accuracy;


    for (auto &i:func)
    {
        if (lettersFunc.find(i) != std::string::npos)
        {
            counterErrorI++;
        }
    }
    for (auto &i:commonString)
    {
        if (lettersI.find(i) != std::string::npos)
        {
            counterErrorI++;
        }
    }
    if (counterErrorI == 0){
    double dTemp = 0;
    double n = atof(apper_limit.c_str())- atof(lower_limit.c_str());
    double dAccuracy = n * atof(accuracy.c_str());
    int lenghtFunc = func.length();
    double i = atof(lower_limit.c_str());
    if (dAccuracy != 0){
    while( i <= atof(apper_limit.c_str()) ){
        for(int j = 0; j < lenghtFunc; j++){
            if (func[j] == 'x'){
                func.erase(j, 1);
                func.insert(j, std::to_string(i));
            }
        }
        OPN strP = func;
        temp = strP.Calculate();
        if (temp == "Input error!"){
            break;
        }else dTemp = dTemp + atof(temp.c_str())*dAccuracy;
        i = i + dAccuracy;
    }}else dTemp = 0;
    str = std::to_string(dTemp);
    QresultI = QString::fromStdString(str);}
    else QresultI = "Input error!";
    ui->Iresoult->setText(QresultI);

}
void integralss::on_pushMathOperations(){
    QPushButton *button = (QPushButton *)sender();
    QString new_label;
    QString QOperations;
    std::string operations = "*/-+%^!";
    std::string strOperation;
    QOperations = button->text();
    strOperation = QOperations.toStdString();
    if(ui->radioButton_acc->isChecked())
    {
        new_label = ui->accuracy->toPlainText() + button->text();

        ui->accuracy->setText( new_label );
    }else if(ui->radioButton_lo->isChecked())
    {
        new_label = ui->lower_limit->toPlainText() + button->text();

        ui->lower_limit->setText( new_label );
    }else if(ui->radioButton_up->isChecked())
    {
        new_label = ui->upper_limit->toPlainText() + button->text();

        ui->upper_limit->setText( new_label );
    }else
    {
        new_label = ui->function->toPlainText() + button->text();

        ui->function->setText( new_label );
    }
    if (operations.find(strOperation) != std::string::npos) {
        counterI = 0;
    }
}

void integralss::on_pushButton_dot_clicked()
{
    if(counterI == 0){
    if(ui->radioButton_acc->isChecked())
    {
        ui->accuracy->setText( ui->accuracy->toPlainText() + '.' );

    }else if(ui->radioButton_lo->isChecked())
    {
        ui->lower_limit->setText( ui->lower_limit->toPlainText() + '.' );

    }else if(ui->radioButton_up->isChecked())
    {
        ui->upper_limit->setText( ui->upper_limit->toPlainText() + '.' );

    }else
    {
        ui->function->setText( ui->function->toPlainText() + '.' );

    }
    }
    counterI = 1;
}


void integralss::on_pushButton_ac_clicked()
{
    if(ui->radioButton_acc->isChecked())
    {
        ui->accuracy->setText("");

    }else if(ui->radioButton_lo->isChecked())
    {
        ui->lower_limit->setText("");

    }else if(ui->radioButton_up->isChecked())
    {
        ui->upper_limit->setText("");

    }else if(ui->radioButton_fun->isChecked())
    {
        ui->function->setText("");

    }
}


void integralss::on_pushButton_decr_clicked()
{
    if(ui->radioButton_acc->isChecked())
    {
        QString str = ui->accuracy->toPlainText();
        str.chop(1);
        ui->accuracy->setText(str);

    }else if(ui->radioButton_lo->isChecked())
    {
        QString str = ui->lower_limit->toPlainText();
        str.chop(1);
        ui->lower_limit->setText(str);

    }else if(ui->radioButton_up->isChecked())
    {
        QString str = ui->upper_limit->toPlainText();
        str.chop(1);
        ui->upper_limit->setText(str);

    }else if(ui->radioButton_fun->isChecked())
    {
        QString str = ui->function->toPlainText();
        str.chop(1);
        ui->function->setText(str);

    }

}
void integralss::on_triganomenations_Integrals()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label;

    if(ui->radioButton_acc->isChecked())
    {
        if(button->text() == "ctan"){
            new_label = ui->accuracy->toPlainText() + "1/tan(";
        }
        else new_label = ui->accuracy->toPlainText() + button->text() + "(";
        ui->accuracy->setText( new_label );

    }else if(ui->radioButton_lo->isChecked())
    {
        if(button->text() == "ctan"){
            new_label = ui->lower_limit->toPlainText() + "1/tan(";
        }
        else new_label = ui->lower_limit->toPlainText() + button->text() + "(";
        ui->lower_limit->setText( new_label );

    }else if(ui->radioButton_up->isChecked())
    {
        if(button->text() == "ctan"){
            new_label = ui->upper_limit->toPlainText() + "1/tan(";
        }
        else new_label = ui->upper_limit->toPlainText() + button->text() + "(";
        ui->upper_limit->setText( new_label );

    }else
    {
        if(button->text() == "ctan"){
            new_label = ui->function->toPlainText() + "1/tan(";
        }
        else new_label = ui->function->toPlainText() + button->text() + "(";
        ui->function->setText( new_label );

    }
}
