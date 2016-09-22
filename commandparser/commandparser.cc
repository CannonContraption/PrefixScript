#include "commandparser.hh"

bool commandparser::store(double value){
	storage.push(value);
}

double commandparser::top(){
	return storage.top();
}

double commandparser::pop()
