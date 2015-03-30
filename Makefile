CC = g++
ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --libs)
ROOTGLIBS := $(shell root-config --glibs)
READLINELIBS := -lreadline -lcurses

grplot:
	$(CC) $@.cc $(ROOTCFLAGS) $(ROOTLIBS) $(READLINELIBS) -o $@
