#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
//#define base "piano/bright_"
#define base "piano/bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "piano";
char *PROGRAM_VERSION = "0.01";

static void
intro(int instrument, int octave)
{
	startMeasure();
	b(5,I,instrument,octave-1, "xx-x", SX);
	b(1,Hd,instrument,octave, "xxx", SX);
	rest(Q-I); // 7/8 beats
	b(1,I,instrument,octave, "xxx", SX);
	b(4,Hd,instrument,octave-1, "xxx", SX);
	rest(Q-I);
	b(4,I,instrument,octave-1, "xxx", SX);
	b(6,Hd,instrument,octave-1, "xxx", SX);
	rest(Q-I);
	b(6,I,instrument,octave-1, "xxx", SX);
	b(5,Hd,instrument,octave-1, "xxx", SX);
	rest(Q-I);
	checkMeasure();
	
}

static void
verse(int instrument, int octave)
{
	startMeasure();
	b(4, H, instrument, octave-1, "---x", SX);
	b(4, Q, instrument, octave-1, "--x-", SX);
	b(4, H, instrument, octave-1, "-x--", SX);
	b(4, Q, instrument, octave-1, "x---", SX);
	
	b(4, Q, instrument, octave-1, "-x--", SX);
	b(4, Q, instrument, octave-1, "--x-", SX);

	b(6, H, instrument, octave-1, "---x", SX);
	b(6, Q, instrument, octave-1, "--x-", SX);
	b(6, H, instrument, octave-1, "-x--", SX);
	b(6, Q, instrument, octave-1, "x---", SX);

	b(6, Q, instrument, octave-1, "-x--", SX);
	b(6, Q, instrument, octave-1, "--x-", SX);

	b(1, H, instrument, octave, "---x", SX);
	b(1, Q, instrument, octave, "--x-", SX);
	b(1, H, instrument, octave, "-x--", SX);
	b(1, Q, instrument, octave, "x---", SX);

	b(1, Q, instrument, octave, "-x--", SX);
	b(1, Q, instrument, octave, "--x-", SX);

	b(5, H, instrument, octave-1, "---x", SX);
	b(5, Q, instrument, octave-1, "--x-", SX);
	b(5, H, instrument, octave-1, "-x--", SX);
	b(5, Q, instrument, octave-1, "x---", SX);

	b(5, Q, instrument, octave-1, "-x--", SX);
	b(5, Q, instrument, octave-1, "--x-", SX);
}

static void
outro(int instrument, int octave)
{
	b(5,Q,instrument,octave-1, "xx-x", SX);
	setSustain(0.99995);
	cpower2(1, W, instrument, octave);
	
}

int
main()
{
	int instrument;
	int octave = 4;

	songInit();

	instrument = readScale(dir,base);

	setTempo(200);
	setTime(4,4);
	setStride(0.05);
	//setSustain(0.99995);
	setAmplitude(0.3);

	openOutput("piano.rra",0,0);

	goto verse;

	int i;
	intro: 
	for (i=0; i<2; i++) {
		intro(instrument, octave);
	}
	//verse
	verse: 
	verse(instrument, octave);
	goto end;
	//chorus
	//verse
	//chorus
	//bridge
	//verse
	//chorus
	//chorus
	outro(instrument, octave);
	
	end:
	closeOutput();

	return 0;
}
