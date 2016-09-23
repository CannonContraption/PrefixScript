#include "commandparser.hh"

int main(){
	currentstorage=0;
}

bool commandparser::store(double value){
	storage.push(value);
}

double commandparser::top(){
	return storage.top();
}

double commandparser::pop(){
	double result = top();
	storage.pop();
	return result;
}

bool commandparser::setfilename(string file){
	filename = file;
	return openfile();
}

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
