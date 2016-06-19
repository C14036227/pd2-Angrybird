#ifndef PIGS_H
#define PIGS_H


#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define PIG_DENSITY 50.0f
#define PIG_FRICTION 0.4f
#define PIG_RESTITUTION 0.2f

class Pigs : public GameItem
{
public:
    Pigs(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void minuslife(float total)=0;
    virtual void savelife()=0;
    int lifeminus;
    float impulse;
    int pointadd;

};
#endif // PIGS_H
