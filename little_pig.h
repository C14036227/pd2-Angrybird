#ifndef LITTLE_PIG_H
#define LITTLE_PIG_H
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

#define LPIG_DENSITY 30.0f
#define LPIG_FRICTION 0.4f
#define LPIG_RESTITUTION 0.4f

class LittlePig:public Pigs
{
public:
    LittlePig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void minuslife(float total);
    virtual void savelife();
    int getPoint();
};

#endif // LITTLE_PIG_H
