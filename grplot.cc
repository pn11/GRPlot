#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

#include <TRint_gr.h>

int main(int argc, char* argv[]){
    
    TRint_gr *app = new TRint_gr("App", &argc, argv);
    app->Run();
    return 0;
}
