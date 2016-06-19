#include "steel.h"

Steel::Steel(float x, float y, float w, float h, QTimer *timer,QPixmap pixmap, b2World *world, QGraphicsScene *scene):Obstacles(x,y,w,h,timer,pixmap,world,scene)
{
    b2PolygonShape bodyob;
    bodyob.SetAsBox(w/2,h/2);


    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyob;
    fixturedef.density = OBST_DENSITY;
    fixturedef.friction = OBST_FRICTION;
    fixturedef.restitution = OBST_RESTITUTION;

    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);


}
