#Place the names of all your tracks here (as RRA filenames)

RRA = piano.rra drums.rra bass.rra
SRRA = s-piano.rra
INCLUDE=/usr/local/include/songlib/
LIB=/usr/local/lib/

all : $(RRA)

%.rra	: %.x
		./$<

%.x	: %.c
		gcc -Wall -g -o $@ -I$(INCLUDE) $< -L$(LIB) -lsong -lm 

mix.rra		: $(RRA)
		rrafastmixer $(RRA) > mix.rra

play	: mix.rra
		rplay mix.rra

playmix : mix.rra
		rplay mix.rra

playpiano : piano.rra
		rplay piano.rra

playbass : bass.rra
		rplay bass.rra

playdrums : drums.rra
		rplay drums.rra

playmaster:  $(SRRA)
	rrafastmixer $(SRRA) | rramaster ! rplay

master.rra :  $(SRRA)
	rrafastmixer $(SRRA) | rramaster > master.rra

master.mp3 : master.rra
	rra2mp3 master.rra

rraidentity : rraidentity.c
		gcc -Wall -g -o rraidentity rraidentity.c -lsong -lm 

.PHONY : clean

clean :
		rm -f $(RRA) $(SRRA) master.rra mix.rra master.mp3
