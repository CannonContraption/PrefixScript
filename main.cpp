/*
 * WELCOME TO PREFIXSCRIPT!
 * 
 * Right now PREFIXSCRIPT can do basic math with multiple
 * inputs using its main stack feature, print values and
 * text, and do basic formulas. All input is from stdin,
 * so there is no really excellent way to pipe a script file
 * to the program on Windows, to the knowledge of the author.
 * 
 * This is the main file, which contains the main loop and a
 * reference to the command runner in the next file.
 * 
 * Note that this is a WORK IN PROGRESS, and will probably
 * be vastly different, should it ever be completed.
 * 
 * Enjoy your copy of PREFIXSCRIPT!
 */

#include<iostream>
#include<sstream>
#include"Stacky.cpp"
#include"defs.hh"
#include"extensions.cpp"
#include"commands.cpp"
#include"core.cc"
using namespace std;

int main(int argc, char* argv[]){
    string command;
    commandparser parser;
    parser.main();
    string filename;
    double extensionargument;
    if(argc == 2){
        parser.usescript(argv[1]);
    }
    try{
        while(command != "quit" && command != "exit"){
            command = parser.read();
            parser.runcommand(command);
        }
    }
    catch (int e) {
        return e;
    }
    return 0;
}
