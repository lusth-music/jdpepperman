#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "sundayBloodySunday";
char *PROGRAM_VERSION = "0.01";

int
main()
{
	int spot;

	songInit();

	//setSlopTiming(W);	

	setTempo(100);
	setTime(4,4);
	setStride(0.05);
	setSustain(0.99995);
	setAmplitude(0.4);
	setPrimaryEmphasis(1);
	setSecondaryEmphasis(1);
	openOutput("sundayBloodySunday.rra",0,0);

	spot = getLocation();
	drumkitSnare(1,1,	"----------------------------x-x-",SX); 
	
	spot = getLocation();
	//drumkitHHClosed(1,1,	"-----x-x---x-x-x-x-x-x-x-x-x-----","-x-x-x-x-x-x-----x-x-x-x-x-x-----",SX); setLocation(spot);
	drumkitSnare(1,1,	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx","xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",SX); setLocation(spot);
	//drumkitSnare(1,1,	"-x-x-----x-------------------x-x-","-------------x-x-------------x-x-",SX); setLocation(spot);
	//drumkitKick(1,3,	"-x-------x-------x-------x-------","-x-------x-------x-------x-------",SX); //that 3 changes amp

	closeOutput();

	return 0;
}
