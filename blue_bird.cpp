#include "blue_bird.h"
#include "mainwindow.h"
BlueBird::BlueBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{


    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BBBIRD_DENSITY;
    fixturedef.friction = BBBIRD_FRICTION;
    fixturedef.restitution = BBBIRD_RESTITUTION;
    g_body->CreateFixture(&fixturedef);
    split=0;


}


void BlueBird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

void BlueBird::birdAct(){
    split=1;


}
