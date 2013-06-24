OBJDIR = obj
PROGRAMS = $(patsubst %.cc, $(OBJDIR)/%, $(wildcard *.cc))
CPPFLAGS = -Wall -g -lm
RM = rm -rf

all: $(PROGRAMS)

# Order-only prerequisite - we want to create $(OBJDIR) before the programs,
# but we don't want all programs to be recompiled when the dir timestamp
# is updated.
# http://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html
$(PROGRAMS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%: %.cc
	g++ $(CPPFLAGS) $^ -o $@

clean:
	$(RM) $(OBJDIR)
