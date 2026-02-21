#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->count, &QPushButton::clicked,
            this, &MainWindow::onCountClicked);
    connect(ui->reset, &QPushButton::clicked,
            this, &MainWindow::onResetClicked);
    showNumber(number);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCountClicked()
{
    number++;
    showNumber(number);
}


void MainWindow::onResetClicked()
{
    number=0;
    showNumber(number);

}

void MainWindow::showNumber(int num)
{
    ui->window->setText(QString::number(num));
}

