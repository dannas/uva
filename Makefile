OBJDIR = 	 obj
SRCDIR = 	 src
SOURCES = 	 $(wildcard $(SRCDIR)/*.cc)
UNSOLVED =   $(shell git status -s | grep '??' | sed 's/?? //')
PROGRAMS = 	 $(patsubst $(SRCDIR)/%.cc, $(OBJDIR)/%, $(SOURCES))
TESTS = 	 $(patsubst $(OBJDIR)/%, %, $(PROGRAMS))

TESTRUNNER = python uvatool.py test
CPPFLAGS =   -Wall -g -lm -std=c++11
RM = 	     rm -rf

all: $(PROGRAMS)

# Order-only prerequisite - we want to create $(OBJDIR) before the programs,
# but we don't want all programs to be recompiled when the dir timestamp
# is updated.
# http://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html
$(PROGRAMS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%: $(SRCDIR)/%.cc
	g++ $(CPPFLAGS) $^ -o $@

check: $(PROGRAMS)
	@for test in $(TESTS) ; do $(TESTRUNNER) $$test ; done

list:
	@for fname in $(SOURCES) ; do head -n 1 $$fname | sed 's|//||' ; done

list-unsolved:
	@for fname in $(UNSOLVED); do head -n 1 $$fname | sed 's|//||' ; done
clean:
	$(RM) $(OBJDIR)

.PHONY: all check list list-unsolved clean 
