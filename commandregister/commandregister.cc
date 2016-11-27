#include "commandregister.hh"

bool commandregister::checkforcommand(string command){
	//It's more efficient to get this first
	int registerlength = commands.size();
	//Now we loop thorugh the register returning true if we found a command
	//matching the search term
	for (int i = 0; i<registerlength; i++){
		if(commands[i].commandname == command){
			return true;
		}
	}
	//false otherwise
	return false;
}
bool commandregister::insertcommand(string command, bool(*function)()){
	//Define and set up our command module
	commandmodule cmd;
	cmd.commandname = command;
	cmd.function = function;
	//Then go through and check for the command. If it's already registered,
	//spit out an error. Otherwise, push it to the register.
	if(!checkforcommand(command)) commands.emplace_back(cmd);
	else{
		cerr<<"ERROR: "<<command<<" command already exists in the register!"<<endl;
		return false;
	}
	return true;
}
bool commandregister::runcommand(string command){
	//Again, more efficient to get this first
	int registerlength = commands.size();
	//Iterate through, and run the associated function if it exists. Else
	//just return false.
	for (int i = 0; i<registerlength; i++){
		if(commands[i].commandname == command){
			return commands[i].function();
		}
	}
	return false;
}

