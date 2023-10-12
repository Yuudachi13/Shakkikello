#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timeout();

public slots:
    void startGame();
    void stopgame();
    void peliaika();
    void currentplayer();
    void aikakuluu();
private:
    Ui::MainWindow *ui;
    QTimer *pQTimer;
    int player1Time;
    int player2Time;
    int gameTime;
    int vuoro;
    void alustus();
    void updateProgressBar();
    void pelikuluu();

};
#endif // MAINWINDOW_H
