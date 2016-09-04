#ifndef MOD_LOGIC
#define MOD_LOGIC
bool commandparser::mod_logic(string command){
    if(command == "if"){
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
        return true;
    }
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
        return true;
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
        return true;
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
        return true;
    }
    return false;
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
#endif