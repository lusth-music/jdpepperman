#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "piano/bright_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "piano";
char *PROGRAM_VERSION = "0.01";


static void
verse(int instrument, int octave)
{
	startMeasure();
	
	//6415

	c(6, Hd, instrument, octave);
	checkMeasure();
	backwards(1.0);
	b(6, H, instrument, octave, "x--", SX);
	backwards(1.0);

	c(6, Hd, instrument, octave);
	backwards(1.0);
	b(6, H, instrument, octave, "x--", SX);
	backwards(1.0);

	c(6, Q, instrument, octave);
	b(6, Q, instrument, octave, "x--", SX);
	checkMeasure();
	
	c(4, Hd, instrument, octave);
	checkMeasure();
	backwards(1.0);
	b(4, H, instrument, octave, "x--", SX);
	backwards(1.0);

	c(4, Hd, instrument, octave);
	backwards(1.0);
	b(4, H, instrument, octave, "x--", SX);
	backwards(1.0);

	c(4, Q, instrument, octave);
	b(4, Q, instrument, octave, "x--", SX);
	checkMeasure();

	c(1, Hd, instrument, octave);
	checkMeasure();
	backwards(1.0);
	b(1, H, instrument, octave, "x--", SX);
	backwards(1.0);

	c(1, Hd, instrument, octave);
	backwards(1.0);
	b(1, H, instrument, octave, "x--", SX);
	backwards(1.0);

	c(1, Q, instrument, octave);
	b(1, Q, instrument, octave, "x--", SX);
	checkMeasure();

	c(5, Hd, instrument, octave);
	checkMeasure();
	backwards(1.0);
	b(5, H, instrument, octave, "x--", SX);
	backwards(1.0);

	c(5, Hd, instrument, octave);
	backwards(1.0);
	b(5, H, instrument, octave, "x--", SX);
	backwards(1.0);

	c(5, Q, instrument, octave);
	b(5, Q, instrument, octave, "x--", SX);
	checkMeasure();
}

static void
intro(int instrument, int octave)
{
	int i;
	for (i=0; i<4; i++) {
		verse(instrument, octave);
	}
}

static void
chorus(int instrument, int octave)
{
	//4156
	c(4, W, instrument, octave);
	c(1, W, instrument, octave);
	c(5, W, instrument, octave);
	c(6, W, instrument, octave);
	c(4, W, instrument, octave);
	c(1, W, instrument, octave);
	c(5, W, instrument, octave);
	c(6, W, instrument, octave);
}

static void
bridge(int instrument, int octave)
{
	setTempo(100);
	//6 1 5 4
	rest(H);
	b(6, Q, instrument, octave, "x--", SX);
	b(6, Q, instrument, octave, "--x", SX);
	rest(H);
	b(1, Q, instrument, octave, "x--", SX);
	b(1, Q, instrument, octave, "--x", SX);
	rest(H);
	b(5, Q, instrument, octave, "x--", SX);
	b(5, Q, instrument, octave, "--x", SX);
	rest(H);
	b(4, Q, instrument, octave, "x--", SX);
	b(4, Q, instrument, octave, "--x", SX);
	setTempo(200);
}

int
main()
{
	int instrument;
	int octave = 4;

	songInit();

	instrument = readScale(dir,base);

	setTempo(200);
	setTime(8,4);
	setStride(0.05);
	setAmplitude(0.3);
	setSustain(0.99995);

	openOutput("piano.rra",0,0);

	int i;
	
	//v r v r b v r
	intro(instrument, octave);
	for (i=0; i<2; i++) {
		verse(instrument, octave);
	}
	for (i=0; i<2; i++) {
		chorus(instrument, octave);
	}
	for (i=0; i<2; i++) {
		verse(instrument, octave);
	}
	for (i=0; i<2; i++) {
		chorus(instrument, octave);
	}
bridge:
	for (i=0; i<2; i++) {
		bridge(instrument, octave);
	}
	for (i=0; i<2; i++) {
		verse(instrument, octave);
	}
	for (i=0; i<2; i++) {
		chorus(instrument, octave);
	}
	
	end:
	closeOutput();

	return 0;
}
