bool stack_pop(){
	if(!prs.empty())
		cout<<prs.pop();
	else
		prs.pop();
}
bool stack_silentpop(){
	prs.pop();
}

bool stack_popn(){
	if(!prs.empty())
		cout<<prs.pop()<<endl;
	else
		prs.pop();
}

bool stack_top(){
	if(!prs.empty())
		cout<<prs.top();
	else
		prs.top();
}

bool stack_topn(){
	if(!prs.empty())
		cout<<prs.top()<<endl;
	else
		prs.top();
}

bool switchstack(){
	string input = prs.read();
	int stacknum = prs.toint(input);
	if(stacknum<4&&stacknum>0){
		prs.setstack(stacknum);
	}
	else{
		cerr<<"\033[1;31mERROR: \033[0;31mInvalid stack number.\033[m"<<endl;
	}
}
