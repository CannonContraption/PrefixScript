#include "commandparser.hh"

void commandparser::store(double value){
	storage[currentstorage].push(value);
}

bool commandparser::listen(){
	command = "";
	while(command != "exit"){
		command = read();
		if(cmdreg->checkforcommand(command)){
			cmdreg->runcommand(command);
		}
	}
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

double commandparser::top(){
	if(!storage[currentstorage].empty())
		return storage[currentstorage].top();
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mStack is empty!\033[m"<<endl;
}

bool commandparser::empty(){
	return storage[currentstorage].empty();
}

bool commandparser::strempty(){
	return strstorage.empty();
}

double commandparser::pop(){
	if(!storage[currentstorage].empty()){
		double result = top();
		storage[currentstorage].pop();
		return result;
	}
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mStack is empty!\033[m"<<endl;
}

void commandparser::strstore(string value){
	strstorage.push(value);
}

string commandparser::strtop(){
	if(!strstorage.empty())
		return strstorage.top();
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
}
string commandparser::strpop(){
	string result = strtop();
	strstorage.pop();
	return result;
}

bool commandparser::openfile(){
	//This will do stuff with the file object! Promise!
}

bool commandparser::setfilename(string file){
	filename = file;
	if (openfile()) return true;
	return false;
}

string commandparser::read(){
	string toread;
    if(repeatread){
        toread = repetitionbuffer[repeatlevel][repeatindex];
        repeatindex++;
    } else if(scriptread){
        scriptfile>>toread;
        if(repeatread){
        	//use tellg and seekg to work this
        	//Repetition buffer turned out to be
        	//kind of clumsy with a file on hand.
        }
    } else if(failcount>maxfails){
        toread = "exit";
    } else{
        cin>>toread;
    }
    return toread;
}
