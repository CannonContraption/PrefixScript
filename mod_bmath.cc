/* Basic math modules
 * Module version 1, original implementation.
 * Used for four-function calculator stuff
 */
#ifndef MOD_BMATH
#define MOD_BMATH 1
bool commandparser::mod_bmath(string command){
    //addition command
    if(command == "+"){
        c=0;
        b=0;
        while(command != "/+"){
            command=read();
            if(command == "/+") continue;
            else if(command == "pop"){
                if(!storage.empty()){
                    a = storage.pop();
                } else {
                    a = 0;
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    cerr<<"Used zero instead of nonexistant stack value"<<endl;
                }
            }
            else if(command == "top"){
                if(!storage.empty()){
                    a = storage.top();
                } else {
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    cerr<<"Used zero instead of nonexistant stack value"<<endl;
                    a = 0;
                }
            }
            else{
                a = todouble(command);
            }
            stackpush(a);
            c++;
        }
        for(;c>0;c--){
            b+=storage.pop();
        }
        stackpush(b);
        b=0;
        a=0;
        c=0;
        return true;
    }
    else if(command == "-"){
        while(command != "/-"){
            command = read();
            if(command == "/-") break;
            else if(command == "pop"){
                if(!storage.empty()){
                    a = storage.pop();
                } else {
                    a = 0;
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    cerr<<"Used zero instead of nonexistant stack value"<<endl;
                }
            }
            else if(command == "top"){
                if(!storage.empty()){
                    a = storage.top();
                } else {
                    a = 0;
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    cerr<<"Used zero instead of nonexistant stack value"<<endl;
                }
            }
            else{
                a = todouble(command);
            }
            if(c ==0) b = a;
            else storage.push(a);
            c++;
        }
        for(;c>1;c--){
            b-=storage.pop();
        }
        storage.push(b);
        b=0;
        a=0;
        c=0;
        return true;
    }
    else if(command == "*"){
        c=0;
        b=1;
        while(command != "/*"){
            command = read();
            if(command == "/*") continue;
            else if(command == "pop"){
                if(!storage.empty()){
                    a = storage.pop();
                } else {
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    cerr<<"Used one instead of nonexistant stack value"<<endl;
                    a = 1;
                }
            }
            else if(command == "top"||command=="disp"){
                if(!storage.empty()){
                    a = storage.top();
                } else {
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    cerr<<"Used one instead of nonexistant stack value"<<endl;
                    a = 1;
                }
            }
            else{
                a = todouble_multsafe(command);
            }
            storage.push(a);
            c++;
        }
        for(;c>0;c--){
            b*=storage.pop();
        }
        storage.push(b);
        b=0;
        a=0;
        c=0;
        return true;
    }
    else if(command == "/"){
        while(command != "//"){
            command = read();
            if(command == "//") break;
            else if(command == "pop"){
                if(!storage.empty()){
                    a = storage.pop();
                } else {
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    cerr<<"Used one instead of nonexistant stack value"<<endl;
                    a = 1;
                }
            }
            else if(command == "top"||command=="disp"){
                if(!storage.empty()){
                    a = storage.top();
                } else {
                    cerr<<"ERROR: Stack is empty!"<<endl;
                    cerr<<"Used one instead of nonexistant stack value"<<endl;
                    a = 1;
                }
            }
            else{
                a = todouble(command);
            }
            if(c ==0) b = a;
            else storage.push(a);
            c++;
        }
        for(;c>1;c--){
            b/=storage.pop();
        }
        storage.push(b);
        b=0;
        a=0;
        c=0;
        return true;
    }
    return false;
}
#endif