#ifndef STEEL_H
#define STEEL_H


#include <gameitem.h>
#include <obstacles.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>

#define OBST_DENSITY 150.0f
#define OBST_FRICTION 0.95f
#define OBST_RESTITUTION 0.2f

class Steel:public Obstacles
{
public:
    Steel(float x, float y, float w, float h, QTimer *timer,QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // STEEL_H
