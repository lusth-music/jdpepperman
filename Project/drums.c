#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"

#define dir "/usr/local/share/samples/piano/"
#define base "bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "drums";
char *PROGRAM_VERSION = "0.01";

int
main()
{
	int spot;

	songInit();

	//setSlopTiming(W);	

	setTempo(200);
	setTime(4,4);
	setStride(0.05);
	setSustain(0.99995);
	setAmplitude(0.4);
	openOutput("drums.rra",0,0);

	int i;
	startMeasure();
	for (i = 0; i < 4; i++){
		spot = getLocation();
		drumkitHHClosed(1,1,	"--------","--------",SX); setLocation(spot);
		drumkitSnare(1,1,	"--------","-----x--",SX); setLocation(spot);
		drumkitKick(1,2,	"xx--x--x","---x----",SX); //that 3 changes amp
		checkMeasure();
	}
	drumkitKick(1,2,"x-x-----",SX);
	closeOutput();

	return 0;
}
