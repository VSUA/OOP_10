#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rational.h"
#include "rational.cpp"
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int Rational::amountOfObjects = 0;

void MainWindow::on_SetRational_clicked()
{

    Rational First;
    Rational Second;
    Rational Third2;

    First.set_numerator(ui->numerator1->text().toInt());
    First.set_denominator(ui->denominator1->text().toInt());
    Second.set_numerator(ui->numerator2->text().toInt());
    Second.set_denominator(ui->denominator2->text().toInt());

    //Сума
    Third2 = First + Second;
    if(Third2.get_numerator() == 0)
    {
    ui->sumAns->setText("0");
    }else if(Third2.get_denominator() == 1)
    {
        ui->sumAns->setText(QString::number(Third2.get_denominator()));
    }else{
        ui->sumAns->setText(QString::number(Third2.get_numerator()) + "\n" + "——"+ "\n" + QString::number(Third2.get_denominator()));
    }

    //Різниця
    Third2 = First - Second;
    if(Third2.get_numerator() == 0)
    {
        ui->subAns->setText("0");
    }else if(Third2.get_denominator() == 1)
    {
        ui->subAns->setText(QString::number(Third2.get_denominator()));
    }else{
    ui->subAns->setText(QString::number(Third2.get_numerator()) + "\n" + "——"+ "\n" + QString::number(Third2.get_denominator()));
    }

    //Множення
    Third2 = First*Second;
    if(Third2.get_numerator() == 0)
    {
        ui->sumAns->setText("0");
    }else if(Third2.get_denominator() == 1)
    {
        ui->mulAns->setText(QString::number(Third2.get_denominator()));
    }else{
        ui->mulAns->setText(QString::number(Third2.get_numerator()) + "\n" + "——"+ "\n" + QString::number(Third2.get_denominator()));
    }

    //Ділення
    Third2 = First/Second;
    if(Third2.get_numerator() == 0)
    {
        ui->sumAns->setText("0");
    }else if(Third2.get_denominator() == 1)
    {
        ui->divAns->setText(QString::number(Third2.get_denominator()));
    }else{
        ui->divAns->setText(QString::number(Third2.get_numerator()) + "\n" + "——"+ "\n" + QString::number(Third2.get_denominator()));
    }

    //Більше
    if(First > Second)
    {
        ui->greateAns->setText(QString::number(First.get_numerator()) + "\n" + "——"+ "\n" + QString::number(First.get_denominator()));
    }else{
        ui->greateAns->setText(QString::number(Second.get_numerator()) + "\n" + "——"+ "\n" + QString::number(Second.get_denominator()));
    }

    //Меньше
    if(First < Second)
    {
        ui->lessAns->setText(QString::number(First.get_numerator()) + "\n" + "——"+ "\n" + QString::number(First.get_denominator()));
    }else{
        ui->lessAns->setText(QString::number(Second.get_numerator()) + "\n" + "——"+ "\n" + QString::number(Second.get_denominator()));
    }

    //Рівність
    if(First == Second)
    {
        ui->eqAns->setText("They equal");
    }else{
        ui->eqAns->setText("They not equal");
    }

    ui->amount->setText("Amount of objects: " + QString::number(Rational::amountOfObjects));
}
