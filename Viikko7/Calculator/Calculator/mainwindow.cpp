#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
// Tämän olisi voinut tehdä kaikille buttoneill erikseen mutta halusin tehdä
// sen lyhyemmin looppaamalla olemassa olevat pushbuttonit
// Kysyin chatgptltä miten tällainen looppi tehdään
    QList<QPushButton*> buttons =
        this->findChildren<QPushButton*>();
    for (QPushButton* button : buttons) {
        connect(button, &QPushButton::clicked,
                this, &MainWindow::onButtonClicked);
    }
    showResult(result);
    showNum1(num1);
    showNum2(num2);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QString name = button->objectName();
    qDebug()<<"Painettiin: "<<name;


        if (name == "clear") {
            num1 = 0;
            num2 = 0;
            result = 0;
            operation = "";
            showResult(result);
            showNum1(num1);
            showNum2(num2);
            return;
        }
        if (name == "add" || name == "sub" ||
            name == "mul" || name == "div") {
            operation = name;
            return;
        }
        if (name == "enter") {
            if (operation == "add")
                result = num1 + num2;
            else if (operation == "sub")
                result = num1 - num2;
            else if (operation == "mul")
                result = num1 * num2;
            else if (operation == "div" && num2 != 0)
                result = num1 / num2;

            showResult(result);
            return;
        }
        if(result == 0){


        if (name.startsWith("N")) {
            int digit = name.mid(1).toInt();

            if (operation == "") {
                num1 = num1 * 10 + digit;
                showNum1(num1);
            } else {
                num2 = num2 * 10 + digit;
                showNum2(num2);
            }
            return;
        }
                }


}




void MainWindow::showResult(int num)
{
    ui->result->setText(QString::number(num));
}
void MainWindow::showNum1(int num1)
{
    ui->num1->setText(QString::number(num1));
}

void MainWindow::showNum2(int num2)
{
    ui->num2->setText(QString::number(num2));
}

