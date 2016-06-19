#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void setLinearVelocity(b2Vec2 velocity);
    b2Vec2 getBirdVelocity();
    float getBirdx();
    float getBirdy();
    virtual void birdAct()=0;
    int split =0;
    int chgravity=0;
};

#endif // BIRD_H
