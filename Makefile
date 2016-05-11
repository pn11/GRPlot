CC = g++
#ROOTCFLAGS := $(shell root-config --cflags)
#ROOTLIBS := $(shell root-config --libs)
#ROOTGLIBS := $(shell root-config --glibs)

ROOTSYS := /Users/oka/root
ROOTCFLAGS := $(shell $(ROOTSYS)/bin/root-config --cflags) ## Write implicitly for xcode. Rewrite some day using ./configure or cmake.
ROOTLIBS := $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS := $(shell $(ROOTSYS)/bin/root-config --glibs)
ROOTCINT := $(ROOTSYS)/bin/rootcint

GRPLOTFLAGS := -I./include
GRPLOTLIBS := -L./lib  -lTRint_gr

DICT := grplot_dict.cc

grplot:  TRint_gr linkdef
	$(CC) $@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) $(GRPLOTLIBS) -o $@

linkdef: include/TRint_gr.h linkdef.h
	$(ROOTCINT) -f $(DICT) -c $(ROOTCFLAGS) $(GRPLOTFLAGS) $^

TRint_gr: linkdef 
	$(CC) src/$@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) -shared $(DICT) -o lib/lib$@.so

.SUFFIXES: .o .cc clean
.cc.o:
	$(CC) -o $@ $(ROOTCFLAGS) -c $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) $<
clean:
	rm *.o *.pcm $(DICT)
