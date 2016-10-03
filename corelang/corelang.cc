bool commentsearch(){
	string command;
	while(command != "/c"){
		command = prs.read();
	}
}

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
