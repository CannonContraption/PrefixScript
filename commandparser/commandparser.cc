#include "commandparser.hh"

bool commandparser::store(double value){
	storage[currentstorage].push(value);
}

double commandparser::top(){
	return storage[currentstorage].top();
}

double commandparser::pop(){
	double result = top();
	storage[currentstorage].pop();
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
        toread = repetitionbuffer[repeatindex];
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
