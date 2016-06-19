#include "yellow_bird.h"

YellowBird::YellowBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{


    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = YBIRD_DENSITY;
    fixturedef.friction = YBIRD_FRICTION;
    fixturedef.restitution = YBIRD_RESTITUTION;
    g_body->CreateFixture(&fixturedef);


}


void YellowBird::setLinearVelocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

void YellowBird::mousePressEvent(QMouseEvent *e){

    if(e->button() == Qt::LeftButton){
        std::cout << "GOOD!" << std::endl ;
    }

}

void YellowBird::birdAct(){
    g_body->SetLinearVelocity(b2Vec2(100,g_body->GetLinearVelocity().y));

}
