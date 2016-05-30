#include"morecommands.cpp"

/* commands.cpp
 * Includes just the base language portion of the program.
 * It refers to morecommands.cpp to take care of extended language functions,
 * if only just to keep the files small enough for casual browsing. Note that
 * this entire file is JUST ONE FUNCTION, and a buttload of if statements.
 */

void commandparser::runcommand(string command){
    //Stack pop
    if(command == "pop"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage.pop();
        }
    }
    //pop with newline
    else if(command == "popn"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage.pop()<<endl;
        }
    }
    //silent pop: pops and outputs nothing.
    else if(command == "silentpop"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            storage.pop();
        }
    }
    //stack top
    else if(command == "disp"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage.top();
        }
    }
    //stack top with newline
    else if(command == "top"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage.top()<<endl;
        }
    }
    //addition command
    else if(command == "+"){
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
            storage.push(a);
            c++;
        }
        for(;c>0;c--){
            b+=storage.pop();
        }
        storage.push(b);
        b=0;
        a=0;
        c=0;
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
    }
    else if(command =="return"){
        command = read();
        if(command =="pop"||command=="top") 
            scriptreturn=storage.pop();
        else
            scriptreturn = todouble(command);
    }
    else if(command == "quit" || command == "exit"){
        scriptreturn = 0;
        cout<<endl;
        throw(0);
    } else if (command == "c"){
        while(command != "/c"){
            command = read();
        }
    }
    else if(command == "s2"){
        secondstack();
    }
    else if(command == "s3"){
        thirdstack();
    }
    else if(command == "function"){
        runfunction();
    }
    else morecommands(command);
}
