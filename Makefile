PROGRAMS = $(patsubst %.cc, %, $(wildcard *.cc))
CPPFLAGS = -Wall -g -lm

all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS)
