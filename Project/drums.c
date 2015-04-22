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

static void
verse()
{
	int spot;
	spot = getLocation();
	startMeasure();
	drumkitHHClosed(1, 1,	"-x-----x","-x----xx","xx-----x","-x----xx","xx-----x","-x----xx","xx-----x","---xxxxx", SX); setLocation(spot);
	drumkitSnare(1, 1,	"----x---","----x---","----x---","----x---","----x---","----x---","----x---","-x--x---", SX); setLocation(spot);
	drumkitKick(1, 2,	"x-xx----","--xx----","x-xx----","--xx----","x-xx----","--xx----","x-xx----","--xx----", SX);
	checkMeasure();
}

static void
chorus()
{
	int spot;
	//spot = getLocation();
	//startMeasure();
	//drumkitHHClosed(1, 1,	"--------","--------","--------","--------","--------","--------","--------","--------", SX); setLocation(spot);
	//drumkitSnare(1, 1,	"----x---","--------","----x---","--------","----x---","--------","----x---","--------", SX); setLocation(spot);
	//drumkitKick(1, 2,	"x-----x-","x-------","x-----x-","x-------","x-----x-","x-------","x-----x-","x-------", SX); 

	spot = getLocation();
	drumkitHHClosed(1, 1,	"--------","--Xx--Xx","--------","--Xx--Xx","--------","--Xx--Xx","--------","--Xx-xXx", SX); setLocation(spot);
	drumkitSnare(1, 1,	"----x---","--------","----x---","--------","----x---","--------","----x---","--------", SX); setLocation(spot);
	drumkitKick(1, 2,	"x-----x-","x-------","x-----x-","x-------","x-----x-","x-------","x-----x-","x-------", SX);
	checkMeasure();
}

static void
bridge()
{
	setTempo(100);
	rest(W+W+W+W);
	setTempo(200);
}

static void
intro()
{
	rest(W+W+W+W);
	rest(W+W+W+W);
	rest(W+W+W+W);
	rest(W+W+W+W);
	rest(W+W+W+W);
	rest(W+W+W+W);
	verse();
}

static void
outro()
{
}

int
main()
{

	songInit();

	//setSlopTiming(W);	

	setTempo(200);
	setTime(8,4);
	setStride(0.05);
	setSustain(0.99995);
	setAmplitude(0.4);
	openOutput("drums.rra",0,0);

	int i;
	goto bridge;

	//v r v r b v r
	intro();
	for (i=0; i<2; i++) {
		verse();
	}
	for (i=0; i<2; i++) {
		chorus();
	}
	for (i=0; i<2; i++) {
		verse();
	}
bridge:
	for (i=0; i<2; i++) {
		chorus();
	}
	bridge();
	for (i=0; i<2; i++) {
		verse();
	}
	for (i=0; i<2; i++) {
		chorus();
	}

	end:
	closeOutput();

	return 0;
}
