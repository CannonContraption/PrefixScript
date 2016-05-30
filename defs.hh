//commands.h file
//for variable storage and initilization purposes.
#include"Stacky.cpp"
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
class commandparser{
protected:
    //Storage and temp variables
    Stacky<double> storage2;
    Stacky<double> storage3;
    vector<string> repetitionbuffer;
    string buffer; //because sometimes we need more than just the command for strings
    string uinput; //user input buffer, used primarily by sinput
    double memory[32];
    double repeatmemory[32];
    fstream scriptfile;
    double a; //6 temp variables that can be used for multiple purposes by
    double b; //various commands.
    int c;
    int d;
    int repeatindex;
    int repeatc;
    int repeatmemoryindex;
    bool issx;
    
    //Command and common functions
    bool secondstack();
    bool thirdstack();
    int testconditions(string condition, double second, double first);
    double todouble_multsafe(const string& s);
    int toint(const string& s);
    bool morecommands(string command);
    void println();
    double getDouble();
    string getString();
    
    //Init values and protected functions
    void setrepeatread(bool setting);
    int runfunction();
    bool repeatread = false;
    bool scriptread = false;
    string filename;
    double extensionargument;
    
    //Version and runtime information
    double version;
    double mincompversion;
    int failcount;
    int maxfails;
public:
    Stacky<double> storage;
    string command;
    void usescript(char* url);
    void usescript(string url);
    string read();
    void runcommand(string command);
    int confirmversion(double version);
    double getreturn();
    void stackpush(double topush);
    double todouble(const string& s);
    double scriptreturn;
    void main();
};
