#include "commandregister.hh"

bool commandregister::insertcommand(string command, bool(*function)()){
	commandmodule cmd;
	cmd.commandname = command;
	cmd.function = function;
	commands.emplace_back(cmd);
	return true;
}
bool commandregister::checkforcommand(string command){
	int registerlength = commands.size();
	for (int i = 0; i<registerlength; i++){
		if(commands[i].commandname == command){
			return true;
		}
	}
	return false;
}
bool commandregister::runcommand(string command){
	int registerlength = commands.size();
	for (int i = 0; i<registerlength; i++){
		if(commands[i].commandname == command){
			return commands[i].function();
		}
	}
	return false;
}
bool question(){
	cout<<"Hello world"<<endl;
	return true;
}
int main(){
	commandregister reg;
	reg.insertcommand("question", &question);
	if(reg.checkforcommand("question"))cout<<"Found"<<endl;
	else cout<<"Not found."<<endl;
	if(reg.runcommand("question"))cout<<"SUCCESS."<<endl;
	else cout<<"FAILED."<<endl;
}
