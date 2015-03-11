#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
//#define base "piano/bright_"
#define base "piano/bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "lpiano";
char *PROGRAM_VERSION = "0.01";

static void
verse(int instrument, int octave)
{
	//6,4,1,5
	startMeasure();
	rest(Q);
	b(6, Q, instrument, octave, "x--", SX);
	b(6, Q, instrument, octave, "-x-", SX);
	b(6, Q, instrument, octave, "--x", SX);
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
	setAmplitude(0.3);
	setSustain(0.99995);

	openOutput("lpiano.rra",0,0);

	goto verse;

	int i;
	//verse
	//verse(instrument, octave);
	rest(W+W+W+W);
	rest(W+W+W+W);
	rest(W+W+W+W);
	rest(W+W+W+W);
	verse: 
	for (i=0; i<2; i++) {
		verse(instrument, octave);
	}
	goto end;
	//chorus
	//verse
	//chorus
	//bridge
	//verse
	//chorus
	//chorus
	
	end:
	closeOutput();

	return 0;
}
