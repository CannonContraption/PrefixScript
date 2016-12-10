#include "commandregister.hh"

bool commandregister::checkforcommand(string command){
	commandmodule * current = head;
	while(current != nullptr){
		if(current->command == command) return true;
		current = current -> next;
	}
	//false otherwise
	return false;
}
bool commandregister::insertcommand(string command, bool(*function)()){
	//Define and set up our command module
	commandmodule * cmd = new commandmodule;
	cmd->command = command;
	cmd->function = function;
	cmd->next = nullptr;
	if(head == nullptr){
		head = cmd;
	}
	else{
		commandmodule * current = head;
		while(current -> next != nullptr){
			current = current -> next;
		}
		current -> next = cmd;
	}
	return true;
}
bool commandregister::runcommand(string command){
	commandmodule * current = head;
	while(current != nullptr){
		if(current->command == command){
			return current->function();
		}
		current = current -> next;
	}
	//false otherwise
	return false;
}

