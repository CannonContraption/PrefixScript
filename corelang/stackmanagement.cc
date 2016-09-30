bool stack_pop(){
	if(!prs.empty())
		cout<<prs.pop();
	else
		prs.pop();
}

bool stack_popn(){
	if(!prs.empty())
		cout<<prs.pop()<<endl;
	else
		prs.pop();
}
