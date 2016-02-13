#include "lineParser.h"

lineParser::lineParser(TApplication *application)
{
    read_history(histfilename.c_str());
    cout << histfilename << " loaded." << endl;
    canvlist = new TList();
    app = application;
}

lineParser::~lineParser()
{
    write_history(histfilename.c_str());
}

int lineParser::readLine()
{
  char *command;
  command = readline(Form("grplot [%d] > ", count));
  if (!strcmp(command, "\0")) return -1;
  count++;
  add_history(command);
  free(command);
  line = command;
  return 0;
}

int lineParser::parse(){
//    cout << line << endl;
    stringstream ss;    
    ss.str(line);
    string str;
    vector<string> commands;
//    commands.clear();

    while (ss >> str){
      commands.push_back(str);
    }
//    cout << commands.size() << endl;        
    
    if (commands.size() == 0){
      cout << "Input command!" << endl;
      return 0;
    }

    else if (commands[0] == "ls"){
        ls();
        return 0;
    }
   
    else if (commands[0] == "exit" || commands[0] == "quit" || commands[0] == "q" || commands[0] == ".q" ){
        return -1;
    }
    
    else if (commands[0] == "plot"){
        if (commands.size() < 2){
            cout << line << endl
                 << "     ^^" << endl
                 << "    Input data or function." << endl;
        }
        else {
            plot(commands);
        }
    }
    else {
        cout << line << endl
             << "^^" << endl
             << "invalid command" << endl; 
    }
    return 0;
}


int lineParser::plot(vector<string> commands){
    TCanvas *c = createCanvas();
    
    if (commands[1].substr(0, 1) == "\"" && commands[1].substr(0, 1) != "["){
        cout << "Open " << commands[1] << endl;
        int length = commands[1].size();
        TGraph *g = new TGraph(commands[1].substr(1, length-2).c_str());
        g->SetMarkerSize(1);
    	g->SetMarkerStyle(2);
        g->Draw("AP");
    }
    else {
        cout << "Plot function " << commands[1] << endl;
    }

    c->Update();
    app->Run();   
    return 0;    
}

void lineParser::ls(){
    DIR *dp = opendir(".");
    struct dirent *dent;
    while ( dp != NULL ){
    	dent = readdir(dp);
        if ( dent != NULL ){
	        string fname = dent->d_name;
	        cout << fname << endl;
        }
        else {
	        break;
        } 
   }
   closedir(dp);
}

TCanvas *lineParser::createCanvas(){
    int ncanvas = canvlist->GetEntries();
    TCanvas *c = new TCanvas(Form("c%d", ncanvas), Form("GRplot Canvas #%d", ncanvas));
    canvlist->Add(c);
    c->cd();
    return c;
}

