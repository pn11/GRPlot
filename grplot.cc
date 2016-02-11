#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

#include<TROOT.h>
#include<TApplication.h>
#include<TCanvas.h>
#include<TGraph.h>


#include <sys/types.h> //http://tech.ckme.co.jp/cpp/cpp_readdir.shtml
#include <dirent.h> //http://www.loose-info.com/main/memolist/c/lib_dirent_readdir.html

//GNU Readline
#include <readline/readline.h>
#include <readline/history.h>

#include "lineParser.h"

int main(int argc, char* argv[]){
  using namespace std;
  
  TApplication *app = new TApplication("App", &argc, argv);
  
  string str;
//  vector<string> line;
//  char *command;  
  
  TGraph *g1;
  
  
  using_history();  
  //  ofstream fout("grplot.log", ios::app);
  
  lineParser *parser = new lineParser();
  while (true){
    parser->readLine();
    int parse_result = parser->parse();
    if (parse_result == -1) break;
  }
 
  delete parser;
  return 0;


//  while(1){
//    read_history(".grplot_history");
//    command = readline("grplot> ");    
//    add_history(command);
//    write_history(".grplot_history");
//    free(command);
    
//    str = command;
//    stringstream ss;    
//    ss.str(str);
//    line.clear();

//    while (ss >> str){
//      line.push_back(str);
//    }
//    cout << line.size() << endl;        
    
//    if (line.size() == 0){
//      cout << "Input command!" << endl;
//      continue;
//    }

    //    cout << line.at(0) << endl;
    
      
//    if ( line.at(0) == "plot"){
//      if (line.size()>1 && line.at(1) != "[" ){
//	TCanvas *c1 = new TCanvas("c1", "grplot");
//	g1 = new TGraph(line.at(1).c_str());
//	g1->SetMarkerColor(kRed);
//	g1->SetMarkerSize(1);
//	g1->SetMarkerStyle(2);
//	g1->Draw("AP");
//	  c1->Update();
//	  app->Run();
//      }
//    }
    
//    else if ( line.at(0) == "ls"){
//      DIR *dp = opendir(".");
//      struct dirent *dent;
//      while ( dp != NULL ){
//	dent = readdir(dp);
//	  if ( dent != NULL ){
//	    string fname = dent->d_name;
//	    cout << fname << endl;
//	  }
//	  else {
//	    break;
//	  } 
//      }
//      closedir(dp);	
//    }      
//    else if (line.at(0) == ".q" || line.at(0) == "q" || line.at(0) == "exit"){
//      gROOT->ProcessLine(".q");
//    }
//    else{
//      cout << "^" << endl
//	   << "invalid command" << endl;
//    } 
//  }	

}
