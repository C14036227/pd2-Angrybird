#include "big_pig.h"

BigPig::BigPig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Pigs(x,y,radius,timer,pixmap,world,scene)
{
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BPIG_DENSITY;
    fixturedef.friction = BPIG_FRICTION;
    fixturedef.restitution = BPIG_RESTITUTION;
    g_body->CreateFixture(&fixturedef);
    impulse = 4000;
    lifeminus =1;

}

void BigPig::minuslife(float total){
    if(lifeminus==1){


        impulse = impulse - total;
        lifeminus=0;
        pointadd++;
        //std::cout<< "Big:  "<<impulse <<std::endl;
    }


}

void BigPig::savelife(){
    if(lifeminus==0)lifeminus=1;
}

int BigPig::getPoint(){
    int i=0;
    //if(pointadd!=0){

    //    i=pointadd;
    //    pointadd=0;
    //}
    return i;
}
