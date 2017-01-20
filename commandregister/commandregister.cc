#include "commandregister.hh"

/*!
 * \brief Check for a command in the register
 * 
 * A simple command checker. Looks up the command string in the register and
 * returns true if it finds it there.
 */
bool commandregister::checkforcommand(string command){
	commandmodule * current = head;
	while(current != nullptr){
		if(current->command == command) return true;
		current = current -> next;
	}
	//false otherwise
	return false;
}

/*!
 * \brief Add a command to the register
 * 
 * Adds a command to the command register. First argument is the string the
 * user will type to activate the command, and the second argument is a function
 * pointer which will be executed when the command is typed.
 * 
 * Note that command input uses the C++ formatted stream input, so any whitespace
 * acts as the command separator. The string must match exactly, and must not
 * contain any line breaks, spaces, or other whitespace characters.
 */
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

/*!
 * \brief Runs the command associated with the command argument
 * 
 * Takes strings as inputted from the commandparser's read() command.
 * 
 * This is built to run whatever the user types, and pass off input and output
 * to that command. It searches our list and then runs the associated command.
 */
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

/*!
 * \brief empties the command register
 * 
 * This function unlinks and deletes all of the command parser modules, leaving
 * the program with no possibility for memory leaks from the register itself.
 */
void commandregister::unlink(){
	commandmodule * current = head;
	commandmodule * old = current;
	while(current){
		old = current;
		current = current -> next;
		delete old;
	}
}
