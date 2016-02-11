#ifndef _PARSER
#define _PARSER

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;

class lineParser
{
 private:
  string histfilename = ".grplot_history";
  int count = 0;
  string line;
 public:
  lineParser();
  ~lineParser();
  int readLine();
  int parse();
  int setHistFileName(string histfilename);
};


#endif // _PARSER


