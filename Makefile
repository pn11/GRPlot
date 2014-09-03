ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)
ROOTGLIBS = $(shell root-config --glibs)
CC = g++


grplot:
	g++ grplot.cc -pthread -stdlib=libc++ -std=c++11 -m64 -I/Users/oka/root/include -L/Users/oka/root/lib -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lpthread -Wl,-rpath,/Users/oka/root/lib -stdlib=libc++ -lm -ldl -o grplot
