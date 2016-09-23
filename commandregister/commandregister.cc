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

