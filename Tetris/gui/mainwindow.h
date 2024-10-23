#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../src/model/util/Observer.hpp"
#include "../src/controller/Tetriscontroller.h"
#include "qlabel.h"
#include <QMainWindow>
#include <QtWidgets/QGraphicsscene>
#include "qlabel.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QMessageBox>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QUrl>
#include <QAudioOutput>
#include <QFileDialog>
#include <QCoreApplication>
#include <QDir>
#include <QTimer>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public model::Observer
{
    Q_OBJECT

public:
    //MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(const controller::TetrisController &ctrl,int gridWidth, int gridHeight, QWidget *parent = nullptr);
    ~MainWindow();

private slots:





private:

    Ui::MainWindow *ui;
    controller::TetrisController controller;
    QGraphicsScene _scene;
    QGraphicsScene _sceneBrick;
    QMediaPlayer *effect;
    QAudioOutput *audio;
    QTimer *timer;
    QMediaPlayer *theme;
    model::Brick _currBrick;
    model::Brick _shadow;
    model::Brick _nextBrick;



    void updateGrid();

    void update(model::Notification notification) override;
    void keyPressEvent(QKeyEvent *event) override;

    void gameOver();
    void gameWon();

    void drawNextBrick();

    void onThemeMediaStatusChanged(QMediaPlayer::MediaStatus status);

    void focusOutEvent(QFocusEvent *event);

    void autoMoveBrick();

};

#endif // MAINWINDOW_H
