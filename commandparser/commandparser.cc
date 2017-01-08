#include "commandparser.hh"

/*
 * commandparser::store(value)
 * 
 * stores specified value to current stack
 * 
 * Arguments:
 *     value
 *         double value to push to the stack
 */
void commandparser::store(double value){
	storage[currentstorage].push(value);
}

/*
 * commandparser::listen()
 * 
 * begins a loop which listens for commands until the user enters exit
 * or the script ends.
 */
int commandparser::listen(){
	command = "";
	while(command != "exit" && exitnow == false){
		command = read();
		if(cin.fail()){
			break;
		}
		if(scriptread && scriptfile.fail()){
			break;
		}
		if(repeatread && repeatindex[repeatlevel] == repetitionbuffer[repeatlevel].length()-3) return returncode;
		if(cmdreg->checkforcommand(command)){
			cmdreg->runcommand(command);
		} else {
			cerr<<"\033[1;31mERROR: \033[0;31mInvalid command:\033[m\033[1;33m "<<command<<"\033[m"<<endl;
		}
	}
	cmdreg->unlink();
	if(exitnow){
		return returncode;
	}
}

/*
 * commandparser::exitprogram(rcd)
 * 
 * Instructs the interpreter to exit with a specified return code
 * 
 * Arguments
 *     rcd
 *         integer return value
 */
void commandparser::exitprogram(int rcd){
	returncode = rcd;
	exitnow    = true;
}

/*
 * exit()
 * 
 * placeholder command so the command register will not allow the exit
 * command to be used elsewhere.
 * 
 * DO NOT REMOVE THIS EMPTY FUNCTION.
 * DO NOT ADD CODE TO THIS FUNCTION UNLESS YOU KNOW WHAT YOU'RE DOING.
 */
bool exit(){}

/*
 * commandparser::todouble_multsafe(&s)
 * 
 * command to convert string to double. It is "multsafe" because if
 * its input can't be converted, it will simply return 1, instead of
 * zero.
 * 
 * Arguments
 *     &s
 *         pointer to the string to convert
 */
double commandparser::todouble_multsafe( const string& s ){
	istringstream i(s);
	double x;
	if (!(i >> x))
		return 1;
	return x;
}

/*
 * commandparser::todouble(&s)
 * 
 * function to convert string to double. It returns zero if its
 * input cannot be converted to a double.
 * 
 * Arguments:
 *     &s
 *         pointer to the string to convert
 */
double commandparser::todouble( const string& s ){
	istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
}

/*
 * commandparser::toint(&s)
 * 
 * converts string to int
 * 
 * Arguments:
 *     &s
 *         pointer to string to convert to int
 */
int commandparser::toint( const string& s ){
	istringstream i(s);
	int x;
	if (!(i >> x))
		return 0;
	return x;
}

/*
 * commandparser::setstack(stacknum)
 * 
 * sets the current main storage stack
 * 
 * Arguments:
 *     stacknum
 *         id number for the stack, between 1 and 3
 */
void commandparser::setstack(int stacknum){
	if(stacknum<4&&stacknum>0){
		currentstorage = stacknum;
	} else{
		cerr<<"\033[1;31mERROR: \033[0;31mInvalid stack number.\033[m"<<endl;
	}
}

/*
 * commandparser::top()
 * 
 * grabs the top value from the stack and returns it.
 */
double commandparser::top(){
	if(!storage[currentstorage].empty())
		return storage[currentstorage].top();
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mStack is empty!\033[m"<<endl;
}

/*
 * commandparser::empty()
 * 
 * checks if the current stack is empty and returns that information.
 */
bool commandparser::empty(){
	return storage[currentstorage].empty();
}

/*
 * commandparser::strempty()
 * 
 * Checks if the string stack is empty and returns that information
 */
bool commandparser::strempty(){
	return strstorage.empty();
}

/*
 * commandparser::pop()
 * 
 * returns the top value in the stack and removes it
 */
double commandparser::pop(){
	if(!storage[currentstorage].empty()){
		double result = top();
		storage[currentstorage].pop();
		return result;
	}
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mStack is empty!\033[m"<<endl;
}

/*
 * commandparser::strstore(value)
 * 
 * stores a string value to the string stack
 * 
 * Arguments:
 *     value
 *         the string to store
 */
void commandparser::strstore(string value){
	strstorage.push(value);
}

/*
 * commandparser::strtop()
 * 
 * returns the top value of the string stack
 */
string commandparser::strtop(){
	if(!strstorage.empty())
		return strstorage.top();
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
}

/*
 * commandparser::strpop()
 * 
 * returns the top value of the string stack then removes it.
 */
string commandparser::strpop(){
	if(!strstorage.empty()){
		string result = strstorage.top();
		strstorage.pop();
		return result;
	}
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
	return "";
}

/*
 * commandparser::openfile()
 * 
 * Opens the file to parse for reading as a script file.
 */
bool commandparser::openfile(){
	scriptfile.open(filename, fstream::in);
	scriptread = true;
}

/*
 * commandparser::setfilename()
 * 
 * Sets the file name of whatever script is about to be read
 * 
 * Arguments:
 *     file
 *         the script filename to open
 */
bool commandparser::setfilename(string file){
	filename = file;
	if (openfile()) return true;
	return false;
}

/*
 * commandparser::read()
 * 
 * Interprets the input file (be it stdin or otherwise) and grabs the next command
 * using cin>> like syntax. Does not differentiate between \n and ' ' purposefully
 */
string commandparser::read(){
	string toread;
	if(scriptread){
		scriptfile>>toread;
		if(repeatread){
			//use tellg and seekg to work this
			//Repetition buffer turned out to be
			//kind of clumsy with a file on hand.
		}
	} else if(repeatread){
		if(repeatindex[repeatlevel] >= repetitionbuffer[repeatlevel].length()-2){
			repeatread = false;
			repeatlevel--;
			return "";
		}
		for(int i = repeatindex[repeatlevel]; i<repetitionbuffer[repeatlevel].length(); i++){
			repeatindex[repeatlevel] = i;
			if(repetitionbuffer[repeatlevel][i] ==  ' ' ||  repetitionbuffer[repeatlevel][i] ==  '	' || repetitionbuffer[repeatlevel][i] == '\n') break;
			toread += repetitionbuffer[repeatlevel][i];
		}
		cout << "repeat read " << toread << endl;
	} else if(failcount>maxfails){
		toread = "exit";
	} else{
		cin>>toread;
	}
	return toread;
}

void commandparser::setrepetitionbuff(string buff){
	repetitionbuffer.emplace_back(buff);
	repeatindex.emplace_back(0);
	repeatlevel = repeatindex.size()-1;
}

void commandparser::execbuff(){
	cout << "gotexecbuff" << endl;
	previousrepeat = false;
	if(repeatread) previousrepeat = true;
	repeatread=true;
	while(repeatread) {
		cmdreg->runcommand(read());
		cout << "running command..." << endl;
	}
}

void commandparser::increaserepeatlevel(){
	repeatlevel++;
}

void commandparser::decreaserepeatlevel(){
	repeatlevel--;
}

bool commandparser::testcondition(string first, string condition, string second){
	char mode = ' ';
	bool fsde = true;
	for(int i = 0; i<condition.length(); i++){
		if(condition[i] == '=' && mode == ' ') mode = '=';
		if(condition[i] == '!')                mode = '!';
		if(condition[i] == '<')                mode = '<';
		if(condition[i] == '=' && mode == '<') mode = 'l';
		if(condition[i] == '>')                mode = '>';
		if(condition[i] == '=' && mode == '>') mode = 'g';
	}
	double firstdbl;
	double seconddbl;
	if(first ==  "pop")
		firstdbl = pop();
    else if (first ==  "top")
        firstdbl = top();
	else
		firstdbl = todouble(first);
	if(second ==  "pop")
		seconddbl = pop();
    else if (second == "top")
        seconddbl = top();
	else
		seconddbl = todouble(second);
	if(mode == '='){
		if(firstdbl == seconddbl) return true;
	} else if (mode == '!'){
		if(firstdbl != seconddbl) return true;
	} else if (mode == 'l'){
		if(firstdbl <= seconddbl) return true;
	} else if (mode == '<'){
		if(firstdbl < seconddbl) return true;
	} else if (mode == 'g'){
		if(firstdbl >= seconddbl) return true;
	} else if (mode == '>'){
		if(firstdbl > seconddbl) return true;
	}
	return false;
}

/*
 * commandparser::commandparser(r)
 * 
 * Commandparser class constructor
 * 
 * takes the command register pointer and sets it for the rest of the class
 * 
 * Arguments:
 *     r
 *          pointer to the command register which we should be using.
 */
commandparser::commandparser(commandregister * r){
	cmdreg = r;
	repeatlevel=-1;
	currentstorage = 1;
	r->insertcommand("exit", exit);
}

