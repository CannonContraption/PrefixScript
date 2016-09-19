/* Main Stack Management Module
 * version 1, original implementation
 * Used for basic memory use and management.
 */
#ifndef MOD_STACK
#define MOD_STACK 1
bool commandparser::mod_stack(string command){
    //Stack pop
    if(command == "pop"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage.pop();
        }
        return true;
    }
    //pop with newline
    else if(command == "popn"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage.pop()<<endl;
        }
        return true;
    }
    //silent pop: pops and outputs nothing.
    else if(command == "silentpop"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            storage.pop();
        }
        return true;
    }
    //stack top
    else if(command == "top"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage.top();
        }
        return true;
    }
    //stack top with newline
    else if(command == "topn"){
        if(storage.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage.top()<<endl;
        }
        return true;
    }
    else{
        return false;
    }
}
#endif
