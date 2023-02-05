#include <knxp_platformio.h>

DECLARE_TIMER( YourCodeShoutOut, 5 );

knxapp knxApp;

unsigned long xx=0;

void knxapp::loop()
{
    if (DUE( YourCodeShoutOut ))
    {
        Log.verbose("Log Your loop %l\n", xx);
        xx=0;
    }
    xx++;
    if(xx % 1000 == 0)
    {
        Log.verbose("Log Your loop %l\n", xx);
    }
}

void knxapp::setup()
{
    Println("Your setup");
}