CC = g++
ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --libs)
ROOTGLIBS := $(shell root-config --glibs)

ROOTSYS := "/Users/oka/root"
ROOTCFLAGS := $(shell $(ROOTSYS)/bin/root-config --cflags) ## Write implicitly for xcode. Rewrite some day.
ROOTLIBS := $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS := $(shell $(ROOTSYS)/bin/root-config --glibs)

READLINELIBS := -lreadline -lcurses
GRPLOTFLAGS := -I./include
GRPLOTLIBS := -L./lib -llineParser

grplot: lineParser
	$(CC) $@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) $(GRPLOTLIBS) -o $@

lineParser:
	$(CC) src/$@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) -shared -o lib/lib$@.so

