/* Scripting Command Module
 * Version 1, original implementation
 * Used for basic scripting functions such as doing a
 * version check, printing to the console, and writing
 * comments.
 */
#ifndef MOD_SCRIPT
#define MOD_SCRIPT 1
bool commandparser::mod_script(string command){
    if(command == "input"){
        getDouble();
        return true;
    }
    if(command == "sinput"){
        uinput = getString();
        return true;
    }
    if(command =="return"){
        command = read();
        if(command =="pop"||command=="top") 
            scriptreturn=storage.pop();
        else
            scriptreturn = todouble(command);
        return true;
    }
    if(command == "quit" || command == "exit"){
        scriptreturn = 0;
        cout<<endl;
        throw(0);
        return true;
    }
    if (command == "c"){
        while(command != "/c"){
            command = read();
        }
        return true;
    }
    if(command == "print"){
        println();
        return true;
    }
    if(command == "linebreak"){
        cout<<endl;
        return true;
    }
    if(command == "vcheck"){
        c=confirmversion(version);
        if(c = 1) return true;
        command="";
        return true;
    }
    if(command == "function"){
        runfunction();
        return true;
    }
    return false;
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

void commandparser::println(){
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
    return 0;
}
#endif