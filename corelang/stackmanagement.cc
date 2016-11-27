/*
 * stack_pop()
 * 
 * function run on pop command
 * basically a wrapper for prs.pop(), pops the top value and displays it
 */
bool stack_pop(){
	if(!prs.empty())
		cout<<prs.pop();
	else
		prs.pop();
}

/*
 * stack_silentpop()
 *
 * function run on silentpop command
 * pops the top value without displaying it
 */
bool stack_silentpop(){
	prs.pop();
}

/*
 * stack_popn()
 *
 * function run on popn command
 * like stack_pop but adds a line break
 */
bool stack_popn(){
	if(!prs.empty())
		cout<<prs.pop()<<endl;
	else
		prs.pop();
}

/*
 * stack_top()
 *
 * function run on the top command
 * displays the top number on the current stack
 */
bool stack_top(){
	if(!prs.empty())
		cout<<prs.top();
	else
		prs.top();
}

/*
 * stack_topn()
 *
 * function run on the topn command
 * displays top number followed by newline
 */
bool stack_topn(){
	if(!prs.empty())
		cout<<prs.top()<<endl;
	else
		prs.top();
}

/*
 * switchstack()
 *
 * function run on stack command
 * takes next input and switches to the stack with that number.
 * If no such stack exists, it screams profanity gently at the user.
 */
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
