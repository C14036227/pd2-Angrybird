#include "little_pig.h"


LittlePig::LittlePig(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Pigs(x,y,radius,timer,pixmap,world,scene)
{
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = LPIG_DENSITY;
    fixturedef.friction = LPIG_FRICTION;
    fixturedef.restitution = LPIG_RESTITUTION;
    g_body->CreateFixture(&fixturedef);
    impulse = 1500;
    lifeminus = 1;

}

void LittlePig::minuslife(float total){
    if(lifeminus==1){

        impulse = impulse - total;
        lifeminus=0;
        pointadd++;
        //std::cout<< "Small:  "<<impulse <<std::endl;
    }


}

void LittlePig::savelife(){
    if(lifeminus==0)lifeminus=1;
}

int LittlePig::getPoint(){
    /*int i=0;
    if(pointadd!=0){

        i=pointadd;
        pointadd=0;


    }
    return i;*/
}

