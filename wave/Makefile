# These are all the files to be compiled.
ALL	= wave.o

# These are the gcc flags.
FLAGS	= -c -O -w

# These are the libraries to be linked in.
LDLIBS	= -lglut -lGL -lGLU -lXmu -lX11 -lm

all:	$(ALL)
	g++ $(ALL) $(LDFLAGS) $(LDLIBS) -o wave

clean:
	rm -f *.o wave

.c.o:
	g++ $(FLAGS) -o $@ $<
