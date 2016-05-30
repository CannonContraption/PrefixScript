#include"housekeeping.cpp"
void commandparser::stackpush(double topush){
    storage.push(topush);
}
bool commandparser::secondstack(){
    command = read();
    if(command == "pop"){
        if(storage2.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage2.pop();
        }
    }
    //pop with newline
    else if(command == "popn"){
        if(storage2.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage2.pop()<<endl;
        }
    }
    else if(command == "s1pop"){
        if(storage2.empty()){
            cerr<<"ERROR: no variable at stack2(0)!"<<endl;
        } else {
            storage.push(storage2.pop());
        }
    }
    else if(command == "s1top"){
        if(storage2.empty()){
            cerr<<"ERROR: no variable at stack2(0)!"<<endl;
        } else {
            storage.push(storage2.top());
        }
    }
    //silent pop: pops and outputs nothing.
    else if(command == "silentpop"){
        if(storage2.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            storage2.pop();
        }
    }
    //stack top
    else if(command == "disp"){
        if(storage2.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage2.top();
        }
    }
    //stack top with newline
    else if(command == "top"){
        if(storage2.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage2.top()<<endl;
        }
    }
    else if(command == "add"){
        storage2.push(storage.pop());
    }
    else if(command == "dupe"){
        storage2.push(storage.top());
    }
    else{
        cout<<"Command not found."<<endl;
        cout<<"s2 is a storage-only stack. It cannot be used otherwise."<<endl;
    }
}
bool commandparser::thirdstack(){
    command = read();
    if(command == "pop"){
        if(storage3.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage3.pop();
        }
    }
    //pop with newline
    else if(command == "popn"){
        if(storage3.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage3.pop()<<endl;
        }
    }
    else if(command == "s1pop"){
        if(storage3.empty()){
            cerr<<"ERROR: no variable at stack2(0)!"<<endl;
        } else {
            storage.push(storage3.pop());
        }
    }
    else if(command == "s1top"){
        if(storage3.empty()){
            cerr<<"ERROR: no variable at stack2(0)!"<<endl;
        } else {
            storage.push(storage3.top());
        }
    }
    //silent pop: pops and outputs nothing.
    else if(command == "silentpop"){
        if(storage3.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            storage3.pop();
        }
    }
    //stack top
    else if(command == "disp"){
        if(storage3.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage3.top();
        }
    }
    //stack top with newline
    else if(command == "top"){
        if(storage3.empty()){
            cerr<<"ERROR: no variable at stack(0)!"<<endl;
        } else {
            cout<<storage3.top()<<endl;
        }
    }
    else if(command == "add"){
        storage3.push(storage.pop());
    }
    else if(command == "dupe"){
        storage3.push(storage.top());
    }
    else{
        cout<<"Command not found."<<endl;
        cout<<"s3 is a storage-only stack. It cannot be used otherwise."<<endl;
    }
}
