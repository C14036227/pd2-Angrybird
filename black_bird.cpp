#include "black_bird.h"

BlackBird::BlackBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BBIRD_DENSITY;
    fixturedef.friction = BBIRD_FRICTION;
    fixturedef.restitution = BBIRD_RESTITUTION;
    g_body->CreateFixture(&fixturedef);
    chgravity=0;


}


void BlackBird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

void BlackBird::birdAct(){
    chgravity=1;

}
