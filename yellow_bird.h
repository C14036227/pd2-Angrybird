#ifndef YELLOW_BIRD_H
#define YELLOW_BIRD_H

#include <iostream>
#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>

#define YBIRD_DENSITY 15.0f
#define YBIRD_FRICTION 0.2f
#define YBIRD_RESTITUTION 0.5f

class YellowBird : public Bird
{

public:
    YellowBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void setLinearVelocity(b2Vec2 velocity);
    void mousePressEvent(QMouseEvent *e);
    virtual void birdAct();

};


#endif // YELLOW_BIRD_H
