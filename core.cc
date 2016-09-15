#include "versioninfo.h"

void commandparser::main(){
    a = 0.0;
    b = 0.0;
    c = 0;
    d = 0;
    repeatindex = 0;
    repeatc = 0;
    issx = false;
    int versionmajor = PrefixScript_VERSION_MAJOR;
    double versionminor = PrefixScript_VERSION_MINOR / 1000.0;
    version = versionmajor + versionminor;
    int mincompmajor = PrefixScript_MINCOMP_MAJOR;
    double mincompminor = PrefixScript_MINCOMP_MINOR / 1000.0;
    double mincomp = mincompmajor + mincompminor;
    mincompversion = mincomp;
    failcount = 0;
    maxfails = 10;
    scriptreturn = 99999;
}

void commandparser::setrepeatread(bool setting){
    repeatread = setting;
}

double commandparser::getreturn(){
    return scriptreturn;
}

string commandparser::read(){
    string toread;
    if(repeatread){
        toread = repetitionbuffer[repeatindex];
        repeatindex++;
    } else if(scriptread){
        scriptfile>>toread;
    } else if(failcount>maxfails){
        toread = "exit";
    } else{
        cin>>toread;
    }
    return toread;
}

double commandparser::getDouble(){
    double iwant;
    cin>>iwant;
    storage.push(iwant);
    return iwant;
}

string commandparser::getString(){
    string iwant;
    cin>>iwant;
    return iwant;
}

/* todouble_multsafe turns a string into a double and returns 1 if it can't.
 * It's multsafe because 1 in multiplication and division doesn't make everything 0*/
double commandparser::todouble_multsafe( const string& s ){
    istringstream i(s);
    double x;
    if (!(i >> x))
        //cerr<<"Not a number!"<<endl;
        return 1;
    return x;
}

//same as above, just defaults to 0 for addition and subtraction
//default for now
double commandparser::todouble( const string& s ){
    istringstream i(s);
    double x;
    if (!(i >> x))
        return 0;
    return x;
}

//used for repeat /repeat command
int commandparser::toint( const string& s ){
    istringstream i(s);
    int x;
    if(!(i >> x))
        return 0;
    return x;
}
