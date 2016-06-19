#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QCursor>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <red_bird.h>
#include <yellow_bird.h>
#include <black_bird.h>
#include <blue_bird.h>
#include <obstacles.h>
#include <pigs.h>
#include <little_pig.h>
#include <big_pig.h>
#include <wood.h>
#include <glass.h>
#include <steel.h>
#include <my_contact_listener.h>
#include <QPushButton>
#include <QLabel>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    void initSet();
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);

    void MyWorld();

    QPushButton *btn_restart;
    QLabel *label;
    QLabel *background;
    QPushButton *btn_exit;


    int posxi;
    int posyi;
    int posxf;
    int posyf;
    int posgo=0;
    int domnum;
    int actflag=0;
    int point = 0;
    int enemykill = 0;
    int proceed = 0;
    int checked1=0;
    int checked2=0;


signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void restart_game();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    Bird *birdie[6];
    Land *ground[2];
    Obstacles *map[11];
    Pigs *pig[2];
    QList<GameItem *> itemList2;


};

#endif // MAINWINDOW_H
