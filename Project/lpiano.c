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
	b(6, W+Q, instrument, octave, "--x", SX);

	rest(Q);
	b(4, Q, instrument, octave, "x--", SX);
	b(4, Q, instrument, octave, "-x-", SX);
	b(4, W+Q, instrument, octave, "--x", SX);

	rest(Q);
	b(1, Q, instrument, octave, "x--", SX);
	b(1, Q, instrument, octave, "-x-", SX);
	b(1, W+Q, instrument, octave, "--x", SX);

	rest(Q);
	b(5, Q, instrument, octave, "x--", SX);
	b(5, Q, instrument, octave, "-x-", SX);
	b(5, W+Q, instrument, octave, "--x", SX);

}

static void
bridge(int instrument, int octave)
{
	//4156

	b(4, Q, instrument, octave, "--x", SX); 		
	b(4, Q, instrument, octave, "x--", SX); 
	b(4, Q, instrument, octave, "-x-", SX); 		
	b(4, Q, instrument, octave, "--x", SX); 
	c(1, W, instrument, octave); 		
	b(5, Q, instrument, octave, "--x", SX); 		
	b(5, Q, instrument, octave, "x--", SX); 
	b(5, Q, instrument, octave, "-x-", SX); 		
	b(5, Q, instrument, octave, "--x", SX); 
	c(6, W, instrument, octave); 		

}

static void 
intro(int instrument, int octave)
{
	rest(W+W+W+W);
	rest(W+W+W+W);
	rest(W+W+W+W);
	rest(W+W+W+W);
	verse(instrument, octave);
	verse(instrument, octave);
}

int
main()
{
	int instrument;
	int octave = 3;

	songInit();

	instrument = readScale(dir,base);

	setTempo(200);
	setTime(8,4);
	setStride(0.05);
	setAmplitude(0.3);
	setSustain(0.99995);

	openOutput("lpiano.rra",0,0);

	int i;
	goto bridge;

	intro:
	intro(instrument, octave);
	//verse
	//verse(instrument, octave);
	verse: 
	for (i=0; i<2; i++) {
		verse(instrument, octave);
	}

	//chorus
	//verse
	//chorus
	//bridge
bridge:
	rest(W+W+W+W+W+W+W+W);
	for (i=0;i<2;i++) {
		bridge(instrument, octave);
	}

	goto end;
	//verse
	for (i=0; i<2; i++) {
		verse(instrument, octave);
	}
	//chorus
	//chorus
	
	end:
	closeOutput();

	return 0;
}
