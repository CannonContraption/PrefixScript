/*
 * inputstring()
 *
 * function run on sinput command
 * reads next string from cin whether or not we're reading from a script and puts it in
 * the string stack. Useful for user input.
 */
bool inputstring(){
	string input;
	if(!prs.getScriptRead()) cin.get();
	getline(cin,input);
	prs.strstore(input);
}

/*
 * stringpop()
 *
 * function run on strpop command
 * prints the top string and pops it from the string stack
 */
bool stringpop(){
	if(!prs.strempty()){
		cout<<prs.strpop()<<endl;
	}
	else{
		prs.strpop();
	}
}

/*
 * stringpopn()
 *
 * function run on strpopn command
 * prints the top string and pops it from the stack, printing a newline after the fact.
 */
bool stringpopn(){
	if(!prs.strempty())
		cout<<prs.strpop()<<endl;
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
}

/*
 * strtop()
 *
 * function run on strtop command
 * Prints the top string on the string stack
 */
bool strtop(){
	if(!prs.strempty())
		cout<<prs.strtop();
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
}

/*
 * strtopn()
 *
 * function run on strtopn command
 * Prints thetop string on the string stack followed by a line break
 */
bool strtopn(){
	if(!prs.strempty())
		cout<<prs.strtop()<<endl;
	else
		prs.strtop();
}

/*
codestring()

Function used to add strings, similar to setting a string variable in
C++. Syntax is similar to the print statement, using the same escape
format. This is in part because it works, and in part because the code
is shared between the two, with only the end action actually changing.
*/
bool codestring(){
	string command = prs.read();
	string toprint = "";
	string space = "";
	while(command != "/string"){
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
	prs.strstore(toprint);
}
