#include "glass.h"

Glass::Glass(float x, float y, float w, float h, QTimer *timer,QPixmap pixmap, b2World *world, QGraphicsScene *scene):Obstacles(x,y,w,h,timer,pixmap,world,scene)
{
    b2PolygonShape bodyob;
    bodyob.SetAsBox(w/2,h/2);


    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyob;
    fixturedef.density = OBGL_DENSITY;
    fixturedef.friction = OBGL_FRICTION;
    fixturedef.restitution = OBGL_RESTITUTION;

    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);


}

