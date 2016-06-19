#ifndef BLUE_BIRD_H
#define BLUE_BIRD_H


#include <iostream>
#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>

#define BBBIRD_DENSITY 10.0f
#define BBBIRD_FRICTION 0.4f
#define BBBIRD_RESTITUTION 0.7f


class BlueBird:public Bird
{
public:
    BlueBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void setLinearVelocity(b2Vec2 velocity);
    virtual void birdAct();


};

#endif // BLUE_BIRD_H
