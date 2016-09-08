#ifndef MOD_MEMORY
#define MOD_MEMORY
bool commandparser::mod_memory(string command){
    if(command == "input"){
        getDouble();
        return true;
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
        else if(command == "recall"){
            command =read();
            c = toint(command);
            if(c<0||c>31){
                cerr<<"ERROR: Memory slot out of bounds."<<endl;
            } else{
                storage.push(memory[c]);
            }
        }
        else {
            cerr<<"ERROR: Memory functions include store,recall."<<endl;
            cerr<<"Refer to documentation for more information."<<endl;
        }
        return true;
    }
    return false;
}
#endif