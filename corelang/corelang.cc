/*! \brief Comment handler

Function handes "c" command, allowing the program to handle comments correctly by doing nothing
until it sees /c
 */
bool commentsearch(){
	string command;
	while(command != "/c"){
		command = prs.read();
	}
}

bool memstore(){
	string getval = prs.read();
	int pos = prs.toint(getval);
	double value = prs.top();
	prs.memstore(pos, value);
}

bool memrecall(){
	string getval = prs.read();
	int pos = prs.toint(getval);
	prs.store(prs.memrecall(pos));
}

/*! \brief Print command handler

Takes print statement and then interprets the contained commands and outputs formatted text based
on whatever the user typed
 */
bool printtoscreen(){
	string command = prs.read();
	string toprint = "";
	string space = "";
	while(command != "/print"){
		if(command == "/"){
			command = "\n";
		}
		else if(command == "//"){
			command = "/";
		}
		else if(command == "///"){
			space = "  ";
			command = prs.read();
			continue;
		}
		else if(command == "/ns"){
			space = "";
			command = prs.read();
			continue;
		}
		toprint +=command;
		space = " ";
		command = prs.read();
	}
	cout<<toprint;
}

/*! \brief Handles the input command

When the user types input, this launches. It cin's a double and stores it to the stack.
 */
bool inputdouble(){
	double input;
	cin>>input;
	prs.store(input);
}

/*! \brief linebreak command handler

Adds a line break on the linebreak command
 */
bool newline(){
	cout<<endl;
}

/*! \brief basic logic if statement

On the if command reads for a logical statement. (value = value) Computes truth and executes the following code up to
/else or /if. If /else exists, it executes that if the logical statement was false.
 */
bool ifstatement(){
	string first = prs.read();
	string compareop = prs.read();
	string second = prs.read();
	string commandlist = "";
	string command = " ";
	bool   ifok = prs.testcondition(first, compareop, second);
	while(command != "/if" && command != "/else"){
		command = prs.read();
		if(ifok && reg.checkforcommand(command)) reg.runcommand(command);
	}
	if(command == "/else"){
		while (command != "/if") {
			command = prs.read();
			if (!ifok && reg.checkforcommand(command)) reg.runcommand(command);
		}
	}
}

/*! \brief Old VCheck placeholder

Placeholder for version check command.
 */
bool vcheck(){
	string input;
	cin >> input;
	while (input != "/vcheck")
		cin>>input;
	cout<<"VCheck is broken. Results are not available."<<endl;
}

/*! \brief Define return code and exit

Takes a function and pushes its return to the stack, or if not in a function, exits the interpreter with a specific
return code.
 */
bool programreturn(){
	string input = prs.read();
	int code = prs.toint(input);
	prs.exitprogram(code);
	return true;
}
