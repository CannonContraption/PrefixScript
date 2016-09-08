#ifndef MOD_STRINGS
#define MOD_STRINGS 1
bool commandparser::mod_strings(string command){
	string buffer;
	if(command == "replace"){
		vector<string> replacewords;
		string         with;
		
		//Look for all the words to replace
		do{
			replacewords.emplace_back(read());
		} while (buffer != "/with");
		
		//And now the expression to replace them with
		with   = read();
		buffer = read();
		
		//if we're in a string
		if (buffer == "/in"){
			buffer = read();
		}
		else {
			cerr << "improper use of replace."<<endl;
			cerr << "Replace: replace (string [string [string [...]]]) /with (string) /in (string) /replace" << endl;
		}
		return true;
	}
	else if(command[0]=='"'){
		buffer="";
		for(;;){
			for(char i : command){
				buffer+=i;
			}
			if(command[command.size()-1] == '"'){
				strstorage.push(buffer);
				buffer="";
				return true;
			}
			command=read();
		}
		return true;
	}
	else if(command=="sinput"){
		buffer="";
		getline(cin, buffer);
		strstorage.push(buffer);
		buffer="";
		return true;
	}
	return false;
}
#endif