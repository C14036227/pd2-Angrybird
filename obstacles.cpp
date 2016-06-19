#include "obstacles.h"

Obstacles::Obstacles(float x, float y, float w, float h, QTimer *timer,QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,h);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2PolygonShape bodyob;
    bodyob.SetAsBox(w/2,h/2);


    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyob;
    fixturedef.density = OBS_DENSITY;
    fixturedef.friction = OBS_FRICTION;
    fixturedef.restitution = OBS_RESTITUTION;

    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void Obstacles::objectTilt(b2Vec2 vecf, b2Vec2 vecpos)
{


    g_body->ApplyForce(vecf, g_body->GetWorldPoint(vecpos),true);


}
