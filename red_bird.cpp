#include "red_bird.h"

RedBird::RedBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = RBIRD_DENSITY;
    fixturedef.friction = RBIRD_FRICTION;
    fixturedef.restitution = RBIRD_RESTITUTION;
    g_body->CreateFixture(&fixturedef);


}


void RedBird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

void RedBird::birdAct(){

}

