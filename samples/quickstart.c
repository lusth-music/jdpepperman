#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "/usr/local/include/songlib/util.h"
#include "/usr/local/include/songlib/songlib.h"


#define dir "/usr/local/share/samples/"
#define base "guitar/classical_"

/* change PROGRAM_NAME and PROGRAM_VERSION appropriately */

char *PROGRAM_NAME = "quickstart";
char *PROGRAM_VERSION = "0.01";

static int last = 0;

static void
verse(int instrument,int octave)
    {
    startMeasure();
	
    b(1, Q, instrument, octave, "x-------", SX);
    b(1, Q, instrument, octave, "-x------", SX);
    b(1, Q, instrument, octave, "--x-----", SX);
    b(1, Q, instrument, octave, "---x----", SX);
    b(1, Q, instrument, octave, "----x---", SX);
    b(1, Q, instrument, octave, "-----x--", SX);
    b(1, Q, instrument, octave, "------x-", SX);
    b(1, Q, instrument, octave, "-------x", SX);

    b(2, Q, instrument, octave, "x-------", SX);
    b(2, Q, instrument, octave, "-x------", SX);
    b(2, Q, instrument, octave, "--x-----", SX);
    b(2, Q, instrument, octave, "---x----", SX);
    b(2, Q, instrument, octave, "----x---", SX);
    b(2, Q, instrument, octave, "-----x--", SX);
    b(2, Q, instrument, octave, "------x-", SX);
    b(2, Q, instrument, octave, "-------x", SX);

    b(3, Q, instrument, octave, "x-------", SX);
    b(3, Q, instrument, octave, "-x------", SX);
    b(3, Q, instrument, octave, "--x-----", SX);
    b(3, Q, instrument, octave, "---x----", SX);
    b(3, Q, instrument, octave, "----x---", SX);
    b(3, Q, instrument, octave, "-----x--", SX);
    b(3, Q, instrument, octave, "------x-", SX);
    b(3, Q, instrument, octave, "-------x", SX);

    b(4, Q, instrument, octave, "x-------", SX);
    b(4, Q, instrument, octave, "-x------", SX);
    b(4, Q, instrument, octave, "--x-----", SX);
    b(4, Q, instrument, octave, "---x----", SX);
    b(4, Q, instrument, octave, "----x---", SX);
    b(4, Q, instrument, octave, "-----x--", SX);
    b(4, Q, instrument, octave, "------x-", SX);
    b(4, Q, instrument, octave, "-------x", SX);

    b(5, Q, instrument, octave, "x-------", SX);
    b(5, Q, instrument, octave, "-x------", SX);
    b(5, Q, instrument, octave, "--x-----", SX);
    b(5, Q, instrument, octave, "---x----", SX);
    b(5, Q, instrument, octave, "----x---", SX);
    b(5, Q, instrument, octave, "-----x--", SX);
    b(5, Q, instrument, octave, "------x-", SX);
    b(5, Q, instrument, octave, "-------x", SX);

    b(6, Q, instrument, octave, "x-------", SX);
    b(6, Q, instrument, octave, "-x------", SX);
    b(6, Q, instrument, octave, "--x-----", SX);
    b(6, Q, instrument, octave, "---x----", SX);
    b(6, Q, instrument, octave, "----x---", SX);
    b(6, Q, instrument, octave, "-----x--", SX);
    b(6, Q, instrument, octave, "------x-", SX);
    b(6, Q, instrument, octave, "-------x", SX);

    checkMeasure();
    }

int
main()
    {
    int instrument;
    int octave = 1;

    songInit();

    instrument = readScale(dir,base);

    setTempo(250);
    setTime(4,4);
    setStride(0.05);
    setSustain(0.99995);
    setAmplitude(0.3);

    openOutput("quickstart.rra",0,0);

    verse(instrument,octave);

    closeOutput();

    return 0;
    }
