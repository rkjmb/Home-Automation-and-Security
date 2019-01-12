#define _DISABLE_TLS_
#define _DEBUG_
#include "thinger/thinger.h"
#include <wiringPi.h>

#define USER_ID             "rkjmb"
#define DEVICE_ID           "" //Device Id
#define DEVICE_CREDENTIAL   "" //Device Cridential

int main(int argc, char *argv[])
{
    if (wiringPiSetup () == -1)
    	return 1 ;
  	pinMode (8, OUTPUT) ; //GPIO Port 3
	pinMode (9, OUTPUT) ; //GPIO Port 5
	pinMode (2, OUTPUT) ; //GPIO Port 13
	pinMode (0, OUTPUT) ; //GPIO Port 11
	thinger_device thing(USER_ID, DEVICE_ID, DEVICE_CREDENTIAL);

   // resource input for 4 relay module
   thing["Switch 1"] << [](pson& in){ digitalWrite(8,in ? 1 : 0); };
   thing["Switch 2"] << [](pson& in){ digitalWrite(9,in ? 1 : 0); };
   thing["Switch 3"] << [](pson& in){ digitalWrite(0,in ? 1 : 0); };
   thing["Switch 4"] << [](pson& in){ digitalWrite(2,in ? 1 : 0); };	

    thing.start();
    return 0;
}

