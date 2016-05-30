#include"extensions.hh"
int extensions::runfile(string file){
    string command;
    parser.usescript(file);
    string filename;
    try{
        while(command !="quit" && command !="exit" && command != "return"){
            command = parser.read();
            parser.runcommand(command);
        }
        extensionreturncode = parser.scriptreturn;
    }
    catch(int e){
        return e;
    }
    return 0;
}

void extensions::passargument(double argument){
    parser.storage.push(argument);
}

double extensions::getreturn(){
    return extensionreturncode;
}

