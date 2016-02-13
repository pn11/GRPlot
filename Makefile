CC = g++
ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --libs)
ROOTGLIBS := $(shell root-config --glibs)
READLINELIBS := -lreadline -lcurses
GRPLOTFLAGS := -I./include
GRPLOTLIBS := -L./lib -llineParser

grplot: lineParser
	$(CC) $@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) $(GRPLOTLIBS) -o $@

lineParser:
	$(CC) src/$@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) $(GRPLOTFLAGS) -shared -o lib/lib$@.so

