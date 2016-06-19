#ifndef RED_BIRD_H
#define RED_BIRD_H




#include <iostream>
#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>

#define RBIRD_DENSITY 15.0f
#define RBIRD_FRICTION 0.2f
#define RBIRD_RESTITUTION 0.5f


class RedBird:public Bird
{
public:
    RedBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void setLinearVelocity(b2Vec2 velocity);
    virtual void birdAct();
};



#endif // RED_BIRD_H
