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


int main(int argc, char* argv[]){
  using namespace std;
  
  TApplication *app = new TApplication("App", &argc, argv);

  string str;
  vector<string> line;

  TGraph *g1;
  
  ofstream fout("grplot.log", ios::app);

  
  while(1){
    
    cout << "grplot> ";    
    
    getline(cin, str);
    fout << str << endl;
    fout.close();

    stringstream ss;    
    ss.str(str);
    line.clear();

    while (ss >> str){
      line.push_back(str);
    }
    cout << line.size() << endl;        
    
    if (line.size() > 0){
      cout << line.at(0) << endl;
      
      
      if ( line.at(0) == "plot"){
	if (line.size()>1 && line.at(1) != "[" ){
	  TCanvas *c1 = new TCanvas("c1", "grplot");
	  g1 = new TGraph(line.at(1).c_str());
	  g1->SetMarkerColor(kRed);
	  g1->SetMarkerSize(1);
	  g1->SetMarkerStyle(2);
	  g1->Draw("AP");
	  c1->Update();

	}
      }
      
      else if (line.at(0) == ".q" || line.at(0) == "q" || line.at(0) == "exit"){
	gROOT->ProcessLine(".q");
      }

      else{
	cout << "^" << endl
	     << "invalid command" << endl;
	continue;
      }
    } 
  }	
  
}
