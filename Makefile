CC = g++
#ROOTCFLAGS := $(shell root-config --cflags)
#ROOTLIBS := $(shell root-config --libs)
#ROOTGLIBS := $(shell root-config --glibs)

ROOTSYS := /Users/oka/root
ROOTCFLAGS := $(shell $(ROOTSYS)/bin/root-config --cflags) ## Write implicitly for xcode. Rewrite some day using ./configure or cmake.
ROOTLIBS := $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS := $(shell $(ROOTSYS)/bin/root-config --glibs)

READLINELIBS := -lreadline -lcurses
GRPLOTFLAGS := -I./include
GRPLOTLIBS := -L./lib -llineParser -lTRint_gr

DICT := grplot_dict.cc

grplot: lineParser TRint_gr linkdef
	$(CC) $@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) $(GRPLOTLIBS) -o $@

linkdef: include/TRint_gr.h linkdef.h
	rootcint -f $(DICT) -c $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) $^

lineParser:
	$(CC) src/$@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) -shared -o lib/lib$@.so

TRint_gr: linkdef
	$(CC) src/$@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) -shared $(DICT) -o lib/lib$@.so

.SUFFIXES: .o .cc clean
.cc.o:
	$(CC) -o $@ $(ROOTCFLAGS) -c $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) $<
clean:
	rm *.o *.pcm $(DICT)


