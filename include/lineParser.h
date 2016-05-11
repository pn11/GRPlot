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

#include <sys/types.h> //http://tech.ckme.co.jp/cpp/cpp_readdir.shtml
#include <dirent.h> //http://www.loose-info.com/main/memolist/c/lib_dirent_readdir.html

#include "TGraphErrors.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TList.h"
#include "TString.h"
#include "TGraphErrors.h"
#include "TApplication.h"

using namespace std;

class lineParser
{
private:
    string histfilename = ".grplot_history";
    int count = 0;
    string line;
    TList *canvlist;
    TApplication *app;
public:
    lineParser(TApplication *application);
    ~lineParser();
    int readLine();
    int parse();
    int setHistFileName(string histfilename);
    int demo();
    int plot(vector<string> commands);
    void ls();
    TGraphErrors *plotData(string fname);
    TF1 *plotFunction(string funcname);
    TCanvas *createCanvas();
};


#endif // _PARSER


