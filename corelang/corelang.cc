bool add(){
	double number;
	double sum = 0;
	string input;
	for(;;){
		cin>>input;
		if(input == "/+"){
			prs.store(sum);
			return true;
		}
		else {
			number = prs.todouble(input);
			sum += number;
		}
	}
}

