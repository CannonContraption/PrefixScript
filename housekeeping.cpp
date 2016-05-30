#include"extensions.cpp"

/* housekeeping.cpp
 * This file contains all the functions of the commandparser class which
 * do not actually directly parse the commands. For example, the verison
 * checker, the line printer, the string-to-double converter, really 
 * anything which does not actually parse the commands themselves, but
 * which makes them run is stored here.
 */
int commandparser::confirmversion(double version){
    /* confirmversion() is here so that scripts can be run on different versions
     * of the program. It is supposed to quietly exit should the version check fail.
     */
    string buffer = "vv";
    cout<<"Version check results: ";
    while(buffer != "/vcheck"){
        buffer = read();
        if(todouble(buffer) > version || todouble(buffer)<mincompversion && buffer != "/vcheck"){
            cerr<<"WRONG VERSION. Please either modify the script,"<<endl;
            cerr<<"or run it with a different PREFIXSCRIPT version."<<endl;
            throw(1);
            return 1;
        }
        else if(buffer != "/vcheck"){
            cout<<"Version "<<buffer<<" confirmed OK with "<<version<<" (current version)"<<endl;
        }
    }
}
int commandparser::runfunction(){
    filename = read();
    command = read();
    auto a =new extensions;
    while(command != "/function"){
        if(command == "pop") extensionargument = storage.pop();
        else if(command == "top") extensionargument = storage.top();
        else extensionargument = todouble(command);
        a->passargument(extensionargument);
        command=read();
    }
    a->runfile(filename);
    stackpush(a->extensionreturncode);
    delete a;
}
void commandparser::usescript(string url){
    scriptfile.open(url, ios::in);
    scriptread = true;
}
void commandparser::usescript(char* url){
    scriptfile.open(url, ios::in);
    scriptread = true;
}

void commandparser::setrepeatread(bool setting){
    repeatread = setting;
}
//so that we're not always stuck with cin
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
void commandparser::println(){ //basically just handles print /print
    string toprint="/print";
    do{
        toprint = read();
        if(toprint == "/print"){
        } else if (toprint == "/ns") {
            toprint = read();
            cout<<toprint;
        } else if (toprint == "/") {
            cout<<endl;
        } else if(toprint == "//"){
            cout<<"/ ";
        } else if(toprint == "///"){
            cout<<" ";
        } else {
            cout<<toprint<<" ";
        }
    } while(toprint != "/print");
}
int commandparser::testconditions(string condition, double second, double first){
    if(condition == "="){
        if(first == second){
            return 0;
        }
    } else if(condition == "/=" || condition == "!="){
        if(first != second){
            return 0;
        }
    } else if(condition == ">"){
        if(first < second){
            return 0;
        }
    } else if(condition == "<"){
        if(first > second){
            return 0;
        }
    } else if(condition == "<="){
        if(first >= second){
            return 0;
        }
    } else if(condition == ">="){
        if(first <= second){
            return 0;
        }
    }
    return 4;
}

double commandparser::getreturn(){
    return scriptreturn;
}
