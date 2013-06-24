PROGRAMS = $(patsubst %.cc, %, $(wildcard *.cc))
OBJDIR = obj
CPPFLAGS = -Wall -g -lm
RM = rm -rf

all: $(PROGRAMS)

%: %.cc
	g++ $(CPPFLAGS) $^ -o $(OBJDIR)/$@

clean:
	$(RM) $(OBJDIR)
