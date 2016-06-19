#ifndef OBSTACLES_H
#define OBSTACLES_H


#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define OBS_DENSITY 100.0f
#define OBS_FRICTION 0.95f
#define OBS_RESTITUTION 0.2f

class Obstacles : public GameItem
{
public:
    Obstacles(float x, float y, float w, float h, QTimer *timer,QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void objectTilt(b2Vec2 vecf, b2Vec2 vecpos);
};

#endif // OBSTACLES_H
