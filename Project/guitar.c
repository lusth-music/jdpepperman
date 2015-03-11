#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
//#define base "guitar/bright_"
#define base "guitar-electric/sox_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "guitar";
char *PROGRAM_VERSION = "0.01";


static void
verse(int instrument, int octave)
{
	startMeasure();
	c(6, I, instrument, octave);
	c(6, I, instrument, octave);
	c(6, I, instrument, octave);
	c(6, I, instrument, octave);
	rest(Q);
	c(6, I, instrument, octave);
	c(6, I, instrument, octave);
	c(6, I, instrument, octave);
	c(6, I, instrument, octave);
	rest(Q);
	c(6, I, instrument, octave);
	c(6, I, instrument, octave);
	c(6, I, instrument, octave);
	rest(I);	
	c(4, I, instrument, octave);
	c(4, I, instrument, octave);
	c(4, I, instrument, octave);
	c(4, I, instrument, octave);
	rest(Q);
	c(4, I, instrument, octave);
	c(4, I, instrument, octave);
	c(4, I, instrument, octave);
	c(4, I, instrument, octave);
	rest(Q);
	c(4, I, instrument, octave);
	c(4, I, instrument, octave);
	c(4, I, instrument, octave);
	rest(I);	
	c(1, I, instrument, octave);
	c(1, I, instrument, octave);
	c(1, I, instrument, octave);
	c(1, I, instrument, octave);
	rest(Q);
	c(1, I, instrument, octave);
	c(1, I, instrument, octave);
	c(1, I, instrument, octave);
	c(1, I, instrument, octave);
	rest(Q);
	c(1, I, instrument, octave);
	c(1, I, instrument, octave);
	c(1, I, instrument, octave);
	rest(I);	
	c(5, I, instrument, octave);
	c(5, I, instrument, octave);
	c(5, I, instrument, octave);
	c(5, I, instrument, octave);
	rest(Q);
	c(5, I, instrument, octave);
	c(5, I, instrument, octave);
	c(5, I, instrument, octave);
	c(5, I, instrument, octave);
	rest(Q);
	c(5, I, instrument, octave);
	c(5, I, instrument, octave);
	c(5, I, instrument, octave);
	rest(I);	
}

static void
intro(int instrument, int octave)
{
	int i;
	for (i=0; i<4; i++) {
		rest(W+W+W+W);
		rest(W+W+W+W);
	}
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
	setAmplitude(0.03);
	setSustain(0.9995);

	openOutput("guitar.rra",0,0);
	//goto verse;

	int i;
	intro: 
	intro(instrument, octave);
	//verse
	verse: 
	for (i=0; i<2; i++) {
		verse(instrument, octave);
	}
	//verse(instrument, octave);
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