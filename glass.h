#ifndef GLASS_H
#define GLASS_H


#include <gameitem.h>
#include <obstacles.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>

#define OBGL_DENSITY 25.0f
#define OBGL_FRICTION 0.5f
#define OBGL_RESTITUTION 0.35f

class Glass:public Obstacles
{
public:
    Glass(float x, float y, float w, float h, QTimer *timer,QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};


#endif // GLASS_H
