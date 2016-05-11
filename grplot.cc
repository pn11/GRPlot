#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

#include<TROOT.h>
#include<TApplication.h>
#include <TRint_gr.h>

#include <sys/types.h> //http://tech.ckme.co.jp/cpp/cpp_readdir.shtml
#include <dirent.h> //http://www.loose-info.com/main/memolist/c/lib_dirent_readdir.html

//GNU Readline
#include <readline/readline.h>
#include <readline/history.h>

#include "lineParser.h"

int main(int argc, char* argv[]){
    
    //  TApplication *app = new TApplication("App", &argc, argv);
    TRint_gr *app = new TRint_gr("App", &argc, argv);
    
    using_history();
    
    lineParser *parser = new lineParser(app);
    while (true){
        parser->readLine();
        int parse_result = parser->parse();
        if (parse_result == -1) break;
    }
    
    delete parser;
    return 0;
}
