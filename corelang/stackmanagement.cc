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
