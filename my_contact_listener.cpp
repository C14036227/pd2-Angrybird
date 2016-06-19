#include "my_contact_listener.h"
#include <math.h>
my_contact_listener::my_contact_listener(){}

    void my_contact_listener::BeginContact(b2Contact* contact) {
        float fucked;
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData ){
            if ( bodyUserData ){
                if(contact->GetFixtureB()->GetDensity()==24||contact->GetFixtureB()->GetDensity()==15||contact->GetFixtureB()->GetDensity()==10)
                    fucked = 30*contact->GetFixtureB()->GetDensity()*contact->GetFixtureB()->GetBody()->GetLinearVelocity().x;
                    else fucked = contact->GetFixtureB()->GetDensity()*sqrt(pow(contact->GetFixtureB()->GetBody()->GetLinearVelocity().x,2)+pow(contact->GetFixtureB()->GetBody()->GetLinearVelocity().y,2));
            if(contact->GetFixtureA()->GetDensity()==50)static_cast<BigPig*>( bodyUserData )->minuslife(fucked);
            if(contact->GetFixtureA()->GetDensity()==30)static_cast<LittlePig*>( bodyUserData )->minuslife(fucked);
        }
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData ){

            if(contact->GetFixtureA()->GetDensity()==24||contact->GetFixtureA()->GetDensity()==15||contact->GetFixtureA()->GetDensity()==10)
                fucked = 30*contact->GetFixtureA()->GetDensity()*contact->GetFixtureA()->GetBody()->GetLinearVelocity().x;
                else fucked = contact->GetFixtureA()->GetDensity()*sqrt(pow(contact->GetFixtureA()->GetBody()->GetLinearVelocity().x,2)+pow(contact->GetFixtureA()->GetBody()->GetLinearVelocity().y,2));
            if(contact->GetFixtureB()->GetDensity()==50)static_cast<BigPig*>( bodyUserData )->minuslife(fucked);
            if(contact->GetFixtureB()->GetDensity()==30)static_cast<LittlePig*>( bodyUserData )->minuslife(fucked);
        }
        }

    }
    void my_contact_listener::EndContact(b2Contact* contact) {
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData ){
            if(contact->GetFixtureA()->GetDensity()==50)static_cast<BigPig*>( bodyUserData )->savelife();
            else if(contact->GetFixtureA()->GetDensity()==30)static_cast<LittlePig*>( bodyUserData )->savelife();
        }
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData ){
            if(contact->GetFixtureB()->GetDensity()==50)static_cast<BigPig*>( bodyUserData )->savelife();
            else if(contact->GetFixtureB()->GetDensity()==30)static_cast<LittlePig*>( bodyUserData )->savelife();
        }
    }

