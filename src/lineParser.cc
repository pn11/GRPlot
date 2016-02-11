#include "lineParser.h"
#include "TString.h"

lineParser::lineParser()
{
    read_history(histfilename.c_str());
    cout << histfilename << " loaded." << endl;
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
    cout << line << endl;
    stringstream ss;    
    ss.str(line);
    string str;
    vector<string> commands;
//    commands.clear();

    while (ss >> str){
      commands.push_back(str);
    }
    cout << commands.size() << endl;        
    
    if (commands.size() == 0){
      cout << "Input command!" << endl;
      return 0;
    }
   
    if (commands[0] == "exit" || commands[0] == "quit" || commands[0] == "q" || commands[0] == ".q" ){
        return -1;
    }
}
