#ifndef MOD_MATH
#define MOD_MATH 1
bool commandparser::mod_math(string command){
    if(command == "math"){
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
        return true;
    }
    return false;
}
#endif
