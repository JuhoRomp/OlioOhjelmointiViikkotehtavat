#include "./mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    connect(ui->min5, &QPushButton::clicked,
            this, &MainWindow::set5Minutes);
    connect(ui->sec120, &QPushButton::clicked,
            this, &MainWindow::set120Seconds);
    connect(ui->switch1, &QPushButton::clicked,
            this, &MainWindow::switchPlayer2);
    connect(ui->switch2, &QPushButton::clicked,
            this, &MainWindow::switchPlayer1);
    connect(ui->startGame, &QPushButton::clicked,
            this, &MainWindow::startGame);
    connect(ui->stopGame, &QPushButton::clicked,
            this, &MainWindow::stopGame);

    leftTime = 120;
    rightTime = 120;
    leftTurn = true;
    gameRunning = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    if(!gameRunning){
        return;
    }
    if (leftTurn){
        if(leftTime>0){
            leftTime--;
            ui->time1->setValue(leftTime);
        } else {
            timer->stop();
            gameRunning = false;
            setGameInfo("Right player wins!", 20);
        }
    } else {
        if(rightTime>0){
            rightTime--;
            ui->time2->setValue(rightTime);
        } else {
            timer->stop();
            gameRunning = false;
            setGameInfo("Left player wins!", 20);
        }
    }

}


void MainWindow::startGame(){
    gameRunning = true;
    timer->start(1000);
    setGameInfo("Game ongoing!", 8);
}

void MainWindow::stopGame(){
    gameRunning = false;
    timer->stop();
    setGameInfo("Game stopped!", 8);
}

void MainWindow::switchPlayer1(){
    if(!gameRunning){
        return;
    }
    leftTurn = true;
}
void MainWindow::switchPlayer2(){
    if(!gameRunning){
        return;
    }
    leftTurn = false;
}

void MainWindow::set120Seconds(){
    if(gameRunning){
        return;
    }
    leftTime = 120;
    rightTime = 120;

    ui->time1->setMaximum(120);
    ui->time2->setMaximum(120);

    ui->time1->setValue(120);
    ui->time2->setValue(120);

    setGameInfo("120 sec selected", 15);

}

void MainWindow::set5Minutes(){
    if(gameRunning){
        return;
    }
    leftTime = 60*5;
    rightTime = 60*5;

    ui->time1->setMaximum(60*5);
    ui->time2->setMaximum(60*5);

    ui->time1->setValue(60*5);
    ui->time2->setValue(60*5);

    setGameInfo("5 min selected", 18);

}

void MainWindow::setGameInfo(QString text, short fontSize){
    QFont font = ui->label->font();
    font.setPointSize(fontSize);
    ui->label->setFont(font);
    ui->label->setText(text);
}
