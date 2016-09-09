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
			buffer+=" ";
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
	else if(command == "strpop"){
		if(strstorage.empty()){
			cerr<<"ERROR: no variable at string stack(0)!"<<endl;
		}
		else{
			cout<<strstorage.pop();
		}
		return true;
	}
	else if(command == "strpopn"){
		if(strstorage.empty()){
			cerr<<"ERROR: no variable at string stack(0)!"<<endl;
		}
		else{
			cout<<strstorage.pop()<<endl;
		}
		return true;
	}
	else if(command == "strtop"){
		if(strstorage.empty()){
			cerr<<"ERROR: no variable at string stack(0)!"<<endl;
		}
		else{
			cout<<strstorage.top();
		}
		return true;
	}
	else if(command == "strtopn"){
		if(strstorage.empty()){
			cerr<<"ERROR: no variable at string stack(0)!"<<endl;
		}
		else{
			cout<<strstorage.top()<<endl;
		}
		return true;
	}
	else if(command == "strsilentpop"){
		if(strstorage.empty()){
			cerr<<"ERROR: no variable at string stack(0)!"<<endl;
		}
		else{
			strstorage.pop();
		}
		return true;
	}
	else if(command == "concat"){
		if(strstorage.empty()){
			cerr<<"ERROR: no variable at string stack(0)!"<<endl;
		}
		else{
			command = read();
			buffer = strstroage.pop();
			if(command == "pop"){
				strstorage.push(buffer+strstorage.pop());
			}
			else if(command == "top"){
				strstorage.push(buffer+strstorage.top());
			}
		}
		return true;
	}
	return false;
}
#endif