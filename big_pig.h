#ifndef BIG_PIG_H
#define BIG_PIG_H
#include <math.h>
#include <iostream>
#include <gameitem.h>
#include <pigs.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>
#include <mainwindow.h>

#define BPIG_DENSITY 50.0f
#define BPIG_FRICTION 0.2f
#define BPIG_RESTITUTION 0.2f

class BigPig:public Pigs
{
public:
    BigPig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void minuslife(float total);
    virtual void savelife();
    int getPoint();
};

#endif // BIG_PIG_H
