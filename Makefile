CC = g++
ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --libs)
ROOTGLIBS := $(shell root-config --glibs)

grplot:
	$(CC) $@.cc $(ROOTCFLAGS) $(ROOTLIBS) -o $@
