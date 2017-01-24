/*! \brief cin a string from the user

Takes command, cins a string, adds it to the string stack.
 */
bool inputstring(){
	string input;
	if(!prs.getScriptRead()) cin.get();
	getline(cin,input);
	prs.strstore(input);
}

/*! \brief pops the top string

Takes the top string on the stack and pops it with no newline
 */
bool stringpop(){
	if(!prs.strempty()){
		cout<<prs.strpop()<<endl;
	}
	else{
		prs.strpop();
	}
}

/*!\brief pops the top string and linebreaks

Takes the top string on the stack and pops it followed by a line break
 */
bool stringpopn(){
	if(!prs.strempty())
		cout<<prs.strpop()<<endl;
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
}

/*! \brief Displays the top string

Displays the top string with no line break
 */
bool strtop(){
	if(!prs.strempty())
		cout<<prs.strtop();
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
}

/*! \brief Displays the top string and linebreaks

Takes the top string on the stack and displays it followed by a line break. No change to stack
contents.
 */
bool strtopn(){
	if(!prs.strempty())
		cout<<prs.strtop()<<endl;
	else
		prs.strtop();
}

/*! \brief allows the scripter to add a string to the stack

uses print /print style formatting in order to store a string to the stack.

/ for line break

// for a single /

/// for an extra space

/ns to get rid of space between preceeding and following word
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
