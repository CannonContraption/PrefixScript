bool add(){
	double sum = 0;
	string input;
	for(;;){
		input=prs.read();
		if(input == "/+"){
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
		difference = prs.todouble(input);
		input = prs.read();
	}
	while(input != "/-"){
		difference -= prs.todouble(input);
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
		if(input == "/*"){
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
		result = prs.todouble(input);
		input = prs.read();
	}
	while(input != "//"){
		result /= prs.todouble(input);
		input = prs.read();
	}
	prs.store(result);
	return true;
}

