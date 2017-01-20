#include "commandparser.hh"

/*!
 * \brief Stores the value it gets to the stack
 * 
 * Takes whatever value is passed, and then stores it to the currently selected
 * stack.
 */
void commandparser::store(double value){
	storage[currentstorage].push(value);
}

/*!
 * \brief Listens for commands
 * 
 * Listens for the user to type a new command.
 * 
 * This function reads from script files and std::cin alike. It is responsible for
 * fetching the next command, dealing with the repetition buffer, and exiting when
 * its time has come. It also does cleanup for the command register on interpreter
 * exit. This needs to be run every time the interpreter runs and every time a new
 * level of recursion is read to be executed.
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

/*!
 * \brief exits the program or loop with the specified return code
 * 
 * Tells the command listener when we're ready to exit and with what return code
 * to do so.
 */
void commandparser::exitprogram(int rcd){
	returncode = rcd;
	exitnow    = true;
}

/*!
 * \brief does nothing, placeholder for the command register
 * 
 * The command register needs to have a command for everything it runs else the interpreter
 * will throw an error at the user. In order to allow the parser to handle exit and to prevent
 * other modules from taking over the command themselves, this blank function has been added
 * to fill the gap.
 */
bool exit(){}

/*!
 * \brief standard way to convert to a double, defaults to 1
 * 
 * This function is built for use throughout the program in order to convert strings to numbers
 * in a standard way.
 * 
 * When it gets a string it can't convert to a number, this will return 1 (which doesn't affect
 * muliplication operations, thus it is named the multiplication-safe (multsafe) version).
 */
double commandparser::todouble_multsafe( const string& s ){
	istringstream i(s);
	double x;
	if (!(i >> x))
		return 1;
	return x;
}

/*!
 * \brief standard way to convert to a double, defaults to 0
 * 
 * This function is built for use throughout the program in order to convert strings to numbers
 * in a standard way.
 * 
 * When it gets a string it can't convert to a number, this will return 0 (so that it won't
 * contribute to a sum if it fails).
 */
double commandparser::todouble( const string& s ){
	istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
}

/*! \brief standard way to convert to an int, defaults to 0
 * 
 * This function is a standard way to convert a string to an integer, such as in places where there
 * is a need of an index number. It is written to prevent the need for a specific integer-based read
 * command while still providing a conversion method for other parts of the program.
 */
int commandparser::toint( const string& s ){
	istringstream i(s);
	int x;
	if (!(i >> x))
		return 0;
	return x;
}

/*! \brief sets the current stack number.
 * 
 * Switches to whatever stack number is passed. This checks to make sure the number is in range, and
 * if it is, it sets the current stack number in order to tell the interpreter where to store and read
 * numbers from.
 */
void commandparser::setstack(int stacknum){
	if(stacknum<4&&stacknum>0){
		currentstorage = stacknum;
	} else{
		cerr<<"\033[1;31mERROR: \033[0;31mInvalid stack number.\033[m"<<endl;
	}
}

/*! \brief grabs the top stack number and returns it
 * 
 * Checks whether the current stack is empty. If it is, the interpreter screams profanity (gently) at
 * the user. If it isn't, it returns the top number from the stack without removing or adding anything.
 * 
 * Obeys the currentstorage attribute
 */
double commandparser::top(){
	if(!storage[currentstorage].empty())
		return storage[currentstorage].top();
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mStack is empty!\033[m"<<endl;
}

/*!
 * \brief checks if the current stack is empty
 * 
 * literally just pipes the return code of the stack's internal empty() function. This returns true if
 * it's actually empty. Used to allow the program to always check the current stack without specifying
 * that every time.
 */
bool commandparser::empty(){
	return storage[currentstorage].empty();
}

/*! \brief checks if the string storage is empty
 * 
 * Similar to the empty() function, but this time it checks the string stack instead of the default
 * double stack.
 */
bool commandparser::strempty(){
	return strstorage.empty();
}

/*! \brief pops the stack
 * 
 * Returns the top number from the stack and removes it. Exactly the same as true RPN pop.
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

/*! \brief stores a string to the string stack
 */
void commandparser::strstore(string value){
	strstorage.push(value);
}

/*! \brief returns the top string on the string stack
 * 
 * Checks if the string stack is empty. If it is, it throws a fit to politely inform the user of their
 * egregious error. Otherwise it returns the top string without touching the stack's contents.
 */
string commandparser::strtop(){
	if(!strstorage.empty())
		return strstorage.top();
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
}

/*! \brief returns the top string on the string stack and pops it
 * 
 * Checks if the string stack is empty. If it isn't, returns the top string on the string stack and then
 * pops it. If it is empty, rants at the user about how they just tried to read a blank book.
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

/*!
 * \brief Opens the file to parse for reading as a script file.
 * 
 * Function to start the script read mode. This opens the script file, and sets the scriptread
 * bit so that the listener knows we're reading from a file instead of std::cin
 */
bool commandparser::openfile(){
	scriptfile.open(filename, fstream::in);
	scriptread = true;
}

/*! \brief Sets the file name to read from
 * 
 * Sets the file name to read from and sets the interpreter on its way to open that file. If it
 * succeeds, it returns truth. Otherwise it returns lies (returns false).
 */
bool commandparser::setfilename(string file){
	filename = file;
	if (openfile()) return true;
	return false;
}

/*! \brief grabs the next command to execute and returns it
 * 
 * The read function is responsible in large part for making sure that the interpreter can always
 * fetch the next space-separated string. It is responsible for determining what to read from where
 * and then returning that to the user. It plays an even greater role in scripting and use of the
 * repetition buffer because it's designed to abstract that distinction from individual commands so
 * they don't have to care where they're reading from.
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

/*! \brief Sets the contents of the next repetition buffer
 * 
 * Sets the string contents of the next repetition buffer, allowing for commands in a loop to be properly
 * repeated. This also feeds the [read](@ref read) command by giving it stuff to read when we're repeating stuff.
 */
void commandparser::setrepetitionbuff(string buff){
	repetitionbuffer.emplace_back(buff);
	repeatindex.emplace_back(0);
	repeatlevel = repeatindex.size()-1;
}

/*! \brief Executes the current repetition buffer once.
 * 
 * When a command finishes recording what it wants to do with the repetition buffer and decides whether there 
 * is truth in its conditional statement, this tells [read()](@ref read) to read from the repetition buffer again.
 */
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

/*! \brief Increases the repetition buffer level
 * 
 * Tells the interpreter we've got one more nested loop.
 */
void commandparser::increaserepeatlevel(){
	repeatlevel++;
}

/*! \brief Decreases the repetition buffer level
 * 
 * Tells the interpreter we've got one less nested loop.
 */
void commandparser::decreaserepeatlevel(){
	repeatlevel--;
}

/*! \brief checks whether we're reading from a script and returns that information
 * 
 * In most cases this should not be done, simply because the design of the interpreter is such
 * that a command should not need to know whether we're reading from a script or not, however,
 * there are border cases where we need this information to direct program flow.
 * 
 * This facilitates those border cases while not allowing the rest of the interpreter (or other
 * commands) to change this value without good reason and the support of another part of the
 * command parser.
 */
bool commandparser::getScriptRead(){
	return scriptread;
}

/*! \brief tests a conditional statement based on three read() results
 * 
 * Tests for truth using the lanugage's native syntax. Takes a first and second string, and
 * compares them based on a conditional string in the middle. These conditionals should be space
 * separated.
 */
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

/*! \brief stores a value into a memory slot
 * 
 * Stores a value into a memory slot.
 */
void commandparser::memstore(int pos, double value){
	memory[pos] = value;
}

/*! \brief recalls a memory value based on its slot number.
 * 
 * Recalls a memory slot. Function similar to a mult-memory calculator.
 */
double commandparser::memrecall(int pos){
	return memory[pos];
}

/*! \brief command parser constructor
 * 
* Initializes the command parser and sets the active command register.
 */
commandparser::commandparser(commandregister * r){
	cmdreg = r;
	repeatlevel=-1;
	currentstorage = 1;
	r->insertcommand("exit", exit);
}

