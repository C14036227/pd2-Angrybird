#ifndef WOOD_H
#define WOOD_H

#include <gameitem.h>
#include <obstacles.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>

#define OBWO_DENSITY 60.0f
#define OBWO_FRICTION 0.8f
#define OBWO_RESTITUTION 0.3f

class Wood:public Obstacles
{
public:
    Wood(float x, float y, float w, float h, QTimer *timer,QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};


#endif // WOOD_H
