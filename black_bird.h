#ifndef BLACK_BIRD_H
#define BLACK_BIRD_H

#include <iostream>
#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>

#define BBIRD_DENSITY 24.0f
#define BBIRD_FRICTION 0.3f
#define BBIRD_RESTITUTION 0.25f


class BlackBird:public Bird
{
public:
    BlackBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void setLinearVelocity(b2Vec2 velocity);
    virtual void birdAct();
};

#endif // BLACK_BIRD_H
