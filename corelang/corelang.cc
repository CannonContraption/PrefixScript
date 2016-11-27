/*
 * commentsearch()
 *
 * function run when the c command is executed
 * prevents the interpreter from doing anything until it sees /c
 */
bool commentsearch(){
	string command;
	while(command != "/c"){
		command = prs.read();
	}
}

/*
 * printtoscreen()
 *
 * command run when the print command is executed
 * prints everything it reads until it sees /print
 * includes some workarounds for PrefixScript's more peculiar tendancies
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
			continue;
		}
		else if(command == "/ns"){
			space = "";
			continue;
		}
		toprint += space + command;
		space = " ";
		command = prs.read();
	}
	cout<<toprint;
}

/*
 * inputdouble()
 *
 * function run on input command
 * searches cin for a double whether or not we are reading from a script.
 * useful for when we want user input.
 */
bool inputdouble(){
	double input;
	cin>>input;
	prs.store(input);
}

/*
 * newline()
 *
 * function run on linebreak command
 * adds a line break.
 */
bool newline(){
	cout<<endl;
}

/*
 * vcheck()
 * 
 * old version-checking code
 * used to ensure script compatiblity during developement as a sort of
 * check to make sure that the code had been modified when the version
 * number went up
 */
bool vcheck(){
	string input;
	cin >> input;
	while (input != "/vcheck")
		cin>>input;
	cout<<"VCheck is broken. Results are not available."<<endl;
}

/*
 * programreturn()
 *
 * function run on return command
 * causes the interpreter to return with the next entered number as the
 * return code.
 */
bool programreturn(){
	string input = prs.read();
	int code = prs.toint(input);
	prs.exitprogram(code);
	return true;
}
