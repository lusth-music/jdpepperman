#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "bass-acoustic/adrian-drawn_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "bass";
char *PROGRAM_VERSION = "0.01";

static int last = 0;

static void
verse(int instrument, int octave)
{
	b(6, Wd, instrument, octave, "x--", SX);
	b(6, H, instrument, octave, "-x-", SX);

	b(4, Wd, instrument, octave, "x--", SX);
	b(5, H, instrument, octave, "x--", SX);

	b(1, Wd, instrument, octave, "x--", SX);
	b(5, Q, instrument, octave, "x--", SX);
	b(4, Q, instrument, octave, "-x-", SX);
	b(5, W+W, instrument, octave, "x--", SX);
}

static void
chorus(int instrument, int octave)
{
	//4156
	b(4, W, instrument, octave, "x--", SX);
	b(1, W, instrument, octave, "x--", SX);
	b(5, W, instrument, octave, "x--", SX);
	b(6, W, instrument, octave, "x--", SX);
	b(4, W, instrument, octave, "x--", SX);
	b(1, W, instrument, octave, "x--", SX);
	b(5, W, instrument, octave, "x--", SX);
	b(6, W, instrument, octave, "x--", SX);
}

static void
intro(int instrument, int octave)
{
	rest(W+W+W+W);
	rest(W+W+W+W);
	b(6, W+W, instrument, octave, "x--", SX);
	b(4, W+W, instrument, octave, "x--", SX);
	b(1, Wd, instrument, octave, "x--", SX);
	b(5, Q, instrument, octave, "x--", SX);
	b(4, Q, instrument, octave, "-x-", SX);
	b(5, W+W, instrument, octave, "x--", SX);
	verse(instrument, octave);
}

static void
bridge(int instrument, int octave)
{
	setTempo(100);
	rest(W+W+W+W);
	//octave = octave + 1;
	////6 1 5 4
	//rest(H-T);
	//b(6, H+T, instrument, octave, "x----", "-x---", "--x--", "---x-", SX);
	//b(6, H+Id, instrument, octave, "----x", "--x--", "x----", SX);
	//rest(H-Id-T);
	//b(5, Q, instrument, octave, "-x-", SX);
	//rest(Q-T);
	//b(5, Q, instrument, octave, "-x-", "-n-", SX);
	//b(5, Q, instrument, octave, "-x-", SX);
	//b(4, H, instrument, octave, "-x-", SX);
	//b(4, H, instrument, octave, "-d-", SX);
	//rest(T+T);
	setTempo(200);
}

int
main()
{
	int instrument;
	int octave = 2;

	songInit();

	instrument = readScale(dir,base);

	setKey(G);
	setTempo(200);
	setTime(8,4);
	setStride(0.05);
	setAmplitude(0.15);
	setSustain(0.99995);

	openOutput("bass.rra",0,0);
	

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
	startMeasure();
	for (i=0; i<2; i++) {
		bridge(instrument, octave);
		rest(W/30000);
	}
	checkMeasure();
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
