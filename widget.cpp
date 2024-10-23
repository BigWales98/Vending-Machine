#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    updateButtons();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateButtons() {
    ui->lcdNumber->display(money);

    ui->pushButton_coffee->setEnabled(money >= 100);
    ui->pushButton_tea->setEnabled(money >= 150);
    ui->pushButton_milk->setEnabled(money >= 200);
}

void Widget::on_pushButton_10_clicked()
{
    money += 10;
    updateButtons();
}

void Widget::on_pushButton_50_clicked()
{
    money += 50;
    updateButtons();
}


void Widget::on_pushButton_100_clicked()
{
    money += 100;
    updateButtons();
}


void Widget::on_pushButton_500_clicked()
{
    money += 500;
    updateButtons();
}

void Widget::on_pushButton_coffee_clicked()
{
    money -= 100;
    updateButtons();
}


void Widget::on_pushButton_tea_clicked()
{
    money -= 150;
    updateButtons();
}


void Widget::on_pushButton_milk_clicked()
{
    money -= 200;
    updateButtons();
}




void Widget::on_pushButton_reset_clicked()
{
    QString message;
    int remaining = money;

    int count500 = remaining / 500;
    remaining %= 500;

    int count100 = remaining /100;
    remaining %= 100;

    int count50 = remaining /50;
    remaining %50;

    int count10 = remaining /10;

    message = QString("잔돈 반환:\n500원: %1개\n100원: %2개\n50원: %3개\n10원: %4개")
        .arg(count500)
        .arg(count100)
        .arg(count50)
        .arg(count10);

    QMessageBox::information(this, "거스름돈", message);

    money = 0;
    updateButtons();

}



