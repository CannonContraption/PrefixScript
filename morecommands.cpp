#include"stacks.cpp"

/*
 * This is the extended language parser portion of the program.
 * It takes care of things that aren't stack-management, basic
 * arithmetic, comments, or program exit commands.
 * 
 * This includes printing to the console, math (not implemented,
 * stay tuned!) logic, repetition, logical repetition, version
 * checking, memory, and how to handle invalid commands.
 */

bool commandparser::morecommands(string command){
    if(command == "print"){
        println();
    }
    else if(command == "vcheck"){
        c=confirmversion(version);
        if(c = 1) return false;
        command="";
    }
    else if(command == "math"){
        while(command != "/math"){
            command = read();
            if(command == "sqrt"){
                if(storage.empty()){
                    cerr<<"ERROR: Stack is empty!"<<endl;
                } else {
                    a = storage.pop();
                    a = sqrt(a);
                    storage.push(a);
                }
            }
            else if(command == "abs"){
                if(!storage.empty()){
                    storage.push(abs(storage.pop()));
                }
                else{
                    cerr<<"ERROR: Stack is empty!"<<endl;
                }
            }
            else if (command == "pow"){
                if(!storage.empty()){
                    command = read();
                    if(command == "pop")
                        c = storage.pop();
                    else if(command =="top")
                        c = storage.top();
                    else
                        c = toint(command);
                    b = storage.pop();
                    storage.push(pow(b,c));
                }
                else{
                    cerr<<"ERROR: Stack is empty!"<<endl;
                }
            }
            else if (command == "loge"){
                if(!storage.empty()){
                    a = storage.pop();
                    storage.push(log(a));
                } else {
                    cerr<<"ERROR: Stack is empty!"<<endl;
                }
            }
            else if (command == "log10"){
                if(!storage.empty()){
                    a = storage.pop();
                    storage.push(log10(a));
                } else {
                    cerr<<"ERROR: Stack is empty!"<<endl;
                }
            }
            else if(command == "cos" || command == "acos" || command == "sin" || command == "asin" || command== "tan" || command=="atan"){
                if(command == "acos" || command == "asin" || command == "atan") issx = true; else issx = false;
                if(command == "cos"  || command=="acos") d=1;
                if(command == "sin"  || command=="asin") d=2;
                if(command == "tan"  || command=="atan") d=3;
                command = read();
                if(!storage.empty()){
                    if(command == "rad")
                        a = storage.pop();
                    else if(command == "deg")
                        a = (3.14159265358979/180)*storage.pop();
                    if(d == 1)
                        b = cos(a);
                    if(d == 2)
                        b = sin(a);
                    if(d == 3)
                        b = tan(a);
                    if(issx)
                        storage.push(1/b);
                    else
                        storage.push(b);
                } else {
                    cerr<<"ERROR: Stack is empty!"<<endl;
                }
            }
            else if (command == "/math");
            else{
                cerr<<"math: ERROR: Command not valid."<<endl;
            }
        }
    }
    else if(command == "if"){
        bool e = false;
        bool f = false;
        double a = 0;
        double b = 0;
        while(command != "/if"){
            if(!f){
                for(int i = 0; i<=2; i++){
                    command = read();
                    if(i == 0){
                        if(command == "pop"){
                            if(storage.empty()){
                                cerr<<"ERROR: Storage is empty!"<<endl;
                                cerr<<"Pushing random value to prevent stack segmentation"<<endl;
                                storage.push(124567890.001);
                            }
                        }
                        else if(command == "disp"){
                            if(!storage.empty()){
                                storage.push(storage.top());
                            } else {
                                cerr<<"ERROR: Storage is empty!"<<endl;
                                cerr<<"Pushing random value to prevent stack segmentation"<<endl;
                                storage.push(123456780.001);
                            }
                        } else storage.push(todouble(command));
                        a = storage.pop();
                    }
                    if(i==2){
                        if(command == "pop"){
                            if(storage.empty()){
                                cerr<<"ERROR: Storage is empty!"<<endl;
                                cerr<<"Pushing random value to prevent stack segmentation"<<endl;
                                storage.push(123567890.001);
                            }
                        }
                        else if(command == "disp"){
                            if(!storage.empty()){
                                storage.push(storage.top());
                            } else {
                                cerr<<"ERROR: Storage is empty!"<<endl;
                                cerr<<"Pushing random value to prevent stack segmentation"<<endl;
                                storage.push(234567890.001);
                            }
                        } else storage.push(todouble(command));
                        b = storage.pop();
                    }
                    else buffer = command;
                }
                if(testconditions(buffer, a, b) == 0)
                    e = true;
                else 
                    e = false;
                f=true;
            }
            command = read();
            if(e && command != "/if" && command != "/else"){
                runcommand(command);
            } if (command == "/else"){
                while(command != "/if"){
                    command = read();
                    if(!e && command != "/if"){
                        runcommand(command);
                    }
                }
            }
        }
        e = false;
        f = false;
        buffer = "empty";
    }
    else if(command == "linebreak") cout<<endl;
    else if(command == "repeat"){
        command = read();
        if(command == "pop"){
            if(!storage.empty()){
                repeatc = storage.pop();
            } else{
                cerr<<"ERROR: Stack is empty!"<<endl;
                repeatc = 0;
            }
        } else if(command == "top"){
            if(!storage.empty()){
                repeatc = storage.top();
            } else {
                cerr<<"ERROR: Stack is empty!"<<endl;
                repeatc = 0;
            }
        } else {
            repeatc = toint(command);
        }
        while(command != "/repeat"){
            command = read();
            if(command == "/repeat") break;
            repetitionbuffer.emplace_back(command);
        }
        repeatindex = 0;
        setrepeatread(true);
        for(int i=0; i<repeatc; i++){
            while(repeatindex<repetitionbuffer.size()){
                runcommand(read());
            }
            repeatindex = 0;
        }
        setrepeatread(false);
        repetitionbuffer.clear();
    }
    else if(command == "sxrepeat"||command=="srepeat"){
        if(command == "sxrepeat") issx=true; else issx=false;
        command = read();
        repeatmemoryindex = toint(command);
        if(repeatmemoryindex<0||repeatmemoryindex>31){
            cerr<<"repeat memory index out of bounds."<<endl;
            while(command!="/sxrepeat"&&command!="/srepeat") command =read();
        } else {
            command = read();
            if(command == "pop"){
                if(!storage.empty()){
                    repeatc = storage.pop();
                } else{
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    repeatc = 0;
                }
            } else if(command == "top"){
                if(!storage.empty()){
                    repeatc = storage.top();
                } else {
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    repeatc = 0;
                }
            } else {
                repeatc = toint(command);
            }
            while(command != "/srepeat" && command != "/sxrepeat"){
                command = read();
                if(command == "/srepeat" || command == "/sxrepeat") break;
                repetitionbuffer.emplace_back(command);
            }
            repeatindex = 0;
            setrepeatread(true);
            if(issx){
                for(int i=0; repeatmemory[repeatmemoryindex]!=repeatc; i++){
                    while(repeatindex<repetitionbuffer.size()){
                        runcommand(read());
                    }
                    repeatindex = 0;
                }
            } else {
                for(int i=0; repeatmemory[repeatmemoryindex]==repeatc; i++){
                    while(repeatindex<repetitionbuffer.size()){
                        runcommand(read());
                    }
                    repeatindex = 0;
                }
            }
            setrepeatread(false);
            repetitionbuffer.clear();
        }
    }
    else if(command == "input"){
        getDouble();
    }
    else if(command == "sinput"){
        uinput = getString();
    }
    else if(command == "repeatmemory"){
        command =read();
        c = toint(command);
        if(c<0||c>31){
            cerr<<"ERROR: Memory slot out of bounds."<<endl;
        } else{
            if(!storage.empty()){
                repeatmemory[c] = storage.pop();
            } else{
                cerr<<"ERROR: Stack is empty."<<endl;
            }
        }
    }
    else if(command == "memory"){
        command = read();
        if(command == "store"){
            command =read();
            c = toint(command);
            if(c<0||c>31){
                cerr<<"ERROR: Memory slot out of bounds."<<endl;
            } else{
                if(!storage.empty()){
                    memory[c] = storage.pop();
                } else{
                    cerr<<"ERROR: Stack is empty."<<endl;
                }
            }
        }
        if(command == "recall"){
            command =read();
            c = toint(command);
            if(c<0||c>31){
                cerr<<"ERROR: Memory slot out of bounds."<<endl;
            } else{
                storage.push(memory[c]);
            }
        }
    }
    else if(command == "setfails"){
        command = read();
        maxfails = toint(command);
    }
    //else if(command.at(0)=='#'&&command.at(1)=='!'); //patches to allow unix shbang (#!) line
    else {
        cerr<<"ERROR: Invalid command: "<<command<<endl;
        failcount++;
        if(failcount > maxfails){
            cerr<<"Number of bad commands is over "<<maxfails<<". Exiting."<<endl;
            command = "exit";
            throw(2);
            return false;
        }
    }
    return true;
}
