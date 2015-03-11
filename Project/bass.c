#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
//#define base "piano/bright_"
#define base "bass-acoustic/adrian-drawn_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "bass";
char *PROGRAM_VERSION = "0.01";

static int last = 0;

static void
verse(int instrument, int octave)
{
	startMeasure();
	b(6, W+W, instrument, octave, "x--", SX);
	checkMeasure();
	b(4, W+W, instrument, octave, "x--", SX);
	b(1, Wd, instrument, octave, "x--", SX);
	b(5, Q, instrument, octave, "x--", SX);
	b(4, Q, instrument, octave, "-x-", SX);
	b(5, W+W, instrument, octave, "x--", SX);
}

int
main()
{
	int instrument;
	int octave = 3;

	songInit();

	instrument = readScale(dir,base);

	setTempo(150);
	setTime(8,4);
	setStride(0.05);
	setAmplitude(0.15);
	setSustain(0.99995);

	openOutput("bass.rra",0,0);
	goto verse;
	
	int i;

	rest(W+W+W+W);
	rest(W+W+W+W);
	verse:
	for (i=0; i<3; i++) {
		verse(instrument, octave);
	}
	goto end;

	outro(instrument, octave);

	end:
	closeOutput();

	return 0;
}
