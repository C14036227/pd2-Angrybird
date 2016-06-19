#ifndef MY_CONTACT_LISTENER_H
#define MY_CONTACT_LISTENER_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>
#include <QCursor>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <red_bird.h>
#include <yellow_bird.h>
#include <black_bird.h>
#include <blue_bird.h>
#include <obstacles.h>
#include <pigs.h>
#include <little_pig.h>
#include <big_pig.h>
#include <wood.h>
#include <glass.h>
#include <steel.h>

class my_contact_listener:public b2ContactListener
{
public:
    my_contact_listener();
    virtual void BeginContact(b2Contact *contact);
    virtual void EndContact(b2Contact *contact);
};

#endif // MY_CONTACT_LISTENER_H
