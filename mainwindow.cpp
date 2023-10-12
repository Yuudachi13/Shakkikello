#include "mainwindow.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQTimer = new QTimer(this);
    pQTimer->setSingleShot(false);
    alustus();
    connect(pQTimer,SIGNAL(timeout()),this,SLOT(aikakuluu()));
    connect(ui->min_2,SIGNAL(clicked()),this,SLOT(peliaika()));
    connect(ui->min_5,SIGNAL(clicked()),this,SLOT(peliaika()));
    connect(ui->StopGame,SIGNAL(clicked()),this,SLOT(stopgame()));
    connect(ui->StartGame,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(ui->PbPlayer1,SIGNAL(clicked()),this,SLOT(currentplayer()));
    connect(ui->PbPlayer2,SIGNAL(clicked()),this,SLOT(currentplayer()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::peliaika()
{
    QPushButton * btn = qobject_cast<QPushButton*>(sender());
    QString d = btn->objectName();
    int minutes = d.last(1).toInt();
    gameTime = 60 * minutes;
    player1Time = gameTime;
    player2Time = gameTime;
    ui->ProgbarPlayer1->setRange(0,gameTime);
    ui->ProgbarPlayer2->setRange(0,gameTime);
    updateProgressBar();
    ui->StartGame->setDisabled(false);
    ui->min_5->setDisabled(true);
    ui->min_2->setDisabled(true);
    ui->label->setText("alkoo");

}
void MainWindow::aikakuluu()
{
    if(vuoro == 1){
       player1Time--;
    }
    else {
        player2Time--;
    }
    if(player1Time == 0 || player2Time == 0 ){
        timeout();
    }
    else {
        updateProgressBar();
    }
}
void MainWindow::pelikuluu()
{
    ui->min_5->setDisabled(true);
    ui->min_2->setDisabled(true);
    ui->StopGame->setDisabled(false);
    ui->StartGame->setDisabled(true);
    ui->PbPlayer1->setDisabled(true);
    ui->PbPlayer2->setDisabled(false);
    vuoro =1;
    ui->label->setText("Peli menossa");
}
void MainWindow::startGame()
{
   pQTimer->start(1000);
   pelikuluu();
}

void MainWindow::timeout()
{
   if(player1Time <= 0) {
    ui->label->setText("vituiks meni toinen voitti");
    ui->PbPlayer1->setDisabled(true);
    ui->PbPlayer2->setDisabled(true);
   } else  if(player2Time <=0){
        ui->label->setText("vituiks meni eka voitti");
    }
}
void MainWindow::currentplayer()
{
    if(vuoro == 1){
        vuoro = 2;
        ui->PbPlayer2->setDisabled(true);
        ui->PbPlayer1->setDisabled(false);
    }
    else{
        vuoro = 1;
    ui->PbPlayer1->setDisabled(true);
    ui->PbPlayer2->setDisabled(false);
}
}

void MainWindow::updateProgressBar()
{
    ui->ProgbarPlayer1->setValue(player1Time);
    ui->ProgbarPlayer2->setValue(player2Time);
}
void MainWindow::stopgame()
{
    pQTimer->stop();
    alustus();
}

void MainWindow::alustus()
{
   pQTimer->stop();
   player1Time = 0;
   player2Time = 0;
   ui->min_2->setDisabled(false);
   ui->min_5->setDisabled(false);
   ui->StopGame->setDisabled(true);
   ui->StartGame->setDisabled(true);
   ui->PbPlayer1->setDisabled(true);
   ui->PbPlayer2->setDisabled(true);
   updateProgressBar();
   ui->label->setText("Valihte peli aika ja paina pellaa");

}
/*
if(gameDuration == 120)
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString Minude = button->objectName();
    int minute = Minude.last(1).toInt();
    gameTime = 60*2;
    player1Time = gameTime;
    player2Time = gameTime;
    ui->ProgbarPlayer1->setValue(100);
    ui->ProgbarPlayer2->setValue(100);
    ui->ProgbarPlayer1->setRange(0, gameTime);
    ui->ProgbarPlayer2->setRange(0, gameTime);

    ui->label->setText("ready to play");
}
else if(gameDuration == 300)
{
    gameTime = 300;
    player1Time = gameTime;
    player2Time = gameTime;
    ui->ProgbarPlayer1->setRange(0, gameTime);
    ui->ProgbarPlayer2->setRange(0, gameTime);
    ui->ProgbarPlayer1->setValue(100);
    ui->ProgbarPlayer2->setValue(100);
    ui->label->setText("ready to play");

}
*/
