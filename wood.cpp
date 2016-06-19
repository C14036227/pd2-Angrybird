#include "wood.h"

Wood::Wood(float x, float y, float w, float h, QTimer *timer,QPixmap pixmap, b2World *world, QGraphicsScene *scene):Obstacles(x,y,w,h,timer,pixmap,world,scene)
{
    b2PolygonShape bodyob;
    bodyob.SetAsBox(w/2,h/2);


    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyob;
    fixturedef.density = OBWO_DENSITY;
    fixturedef.friction = OBWO_FRICTION;
    fixturedef.restitution = OBWO_RESTITUTION;

    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);


}
