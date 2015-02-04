#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
//#define base "piano/bright_"
#define base "bass/campbell-drawn_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "bass";
char *PROGRAM_VERSION = "0.01";

static int last = 0;

int
main()
{
	int instrument;
	int octave = 5;

	songInit();

	instrument = readScale(dir,base);

	setTempo(200);
	setTime(4,4);
	setStride(0.05);
	//setSustain(0.99995);
	setAmplitude(0.7);

	openOutput("bass.rra",0,0);

	int i;
//	for (i=0; i<2; i++) {
//		setSustain(0.5);
//		b(5,H,instrument,octave-1, "x---", "-x--", "--x-", SX);
//		b(5,H,instrument,octave-1, "---x", "x---", "--x-", SX);
//		//b(chord, duration[whole(w), half(h), quarter(q), eighth(i), sixteenth(s), thirtysecond(t)], instrument, octave, which notes to play, SX is the terminator)
//		setSustain(0.99965);
//		b(1,W, instrument, octave, "xxxx", "xxxx", "xxxx", SX);
//		setSustain(0.5);
//		b(4,H, instrument, octave-1, "x---", "---x", "x---", SX);
//		b(4,H, instrument, octave-1, "-x--", "--x-", "---x", SX);
//		//ci[1-6)
//		setSustain(0.99965);
//		b(6, W, instrument, octave-1, "x-xx", "---", "x-xx", SX);
//	}
	setSustain(0.99993);
	
	for (i=0; i<2; i++) {
		b(1,W,instrument,octave, "x--", SX);
		b(4,W,instrument,octave, "x--", SX);
		b(6,W,instrument,octave, "x--", SX);
		b(5,W,instrument,octave, "x--", SX);
	}	
	b(5,Q,instrument,octave, "x--", SX);
	b(1, W, instrument, octave+1, "x--", SX);

	closeOutput();

	return 0;
}
