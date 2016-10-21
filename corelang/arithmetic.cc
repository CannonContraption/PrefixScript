bool add(){
	double sum = 0;
	string input;
	for(;;){
		input=prs.read();
		if(input == "pop"){
			sum += prs.pop();
		}
		else if(input == "top"){
			sum += prs.top();
		}
		else if(input == "/+"){
			prs.store(sum);
			return true;
		}
		else {
			sum += prs.todouble(input);
		}
	}
}

bool sub(){
	double number;
	double difference;
	string input = prs.read();
	if(input == "/-"){
		difference=0;
	}
	else{
		if(input == "pop"){
			difference = prs.pop();
		}
		else if(input == "top"){
			difference = prs.top();
		}
		else{
			difference = prs.todouble(input);
		}
		input = prs.read();
	}
	while(input != "/-"){
		if(input == "pop"){
			difference -= prs.pop();
		} else if (input == "top"){
			difference -= prs.top();
		}
		else difference -= prs.todouble(input);
		input = prs.read();
	}
	prs.store(difference);
	return true;
}

bool mul(){
	double product = 1;
	string input;
	for(;;){
		input = prs.read();
		if(input == "pop") product *= prs.pop();
		else if (input == "top") product *= prs.top();
		else if(input == "/*"){
			prs.store(product);
			return true;
		}
		else {
			product *= prs.todouble(input);
		}
	}
}

bool div(){
	double number;
	double result;
	string input = prs.read();
	if(input == "//"){
		result = 0;
	}
	else {
		if(input == "pop") result = prs.pop();
		else if(input == "top") result = prs.top();
		else result = prs.todouble(input);
		input = prs.read();
	}
	while(input != "//"){
		if(input == "pop") result /= prs.pop();
		else if (input == "top") result /= prs.top();
		else result /= prs.todouble(input);
		input = prs.read();
	}
	prs.store(result);
	return true;
}
