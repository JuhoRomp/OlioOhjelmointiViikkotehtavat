#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <string>

#include <QMainWindow>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startGame();
    void stopGame();
    void switchPlayer1();
    void switchPlayer2();
    void set120Seconds();
    void set5Minutes();
    void setGameInfo(QString, short);
private slots:
    void updateTime();

private:
    Ui::MainWindow *ui;
    int leftTime;
    int rightTime;
    bool leftTurn;
    bool gameRunning;
    QTimer *timer;

};
#endif // MAINWINDOW_H
