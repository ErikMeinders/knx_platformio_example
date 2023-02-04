#include <knxp_platformio.h>

DECLARE_TIMER( YourCodeShoutOut, 5 );

knxapp knxApp;

unsigned long xx=0;

void knxapp::loop()
{
    if (DUE( YourCodeShoutOut ))
    {
        Log.verbose("Log Your loop %u\n", xx);
        xx=0;
    }
    xx++;   
}

void knxapp::status()
{
    _knxapp::status();
    Println("Your status");
}