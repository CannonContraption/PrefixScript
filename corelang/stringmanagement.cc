bool inputstring(){
	string input;
	cin>>input;
	prs.strstore(input);
}

bool stringpop(){
	if(!prs.strempty()){
		cout<<prs.strpop()<<endl;
	}
	else{
		prs.strpop();
	}
}

bool stringpopn(){
	if(!prs.strempty())
		cout<<prs.strpop()<<endl;
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
}

bool strtop(){
	if(!prs.strempty())
		cout<<prs.strtop();
	else
		cerr<<"\033[1;31mERROR: \033[m\033[31mString stack is empty!\033[m"<<endl;
}

bool strtopn(){
	if(!prs.strempty())
		cout<<prs.strtop()<<endl;
	else
		prs.strtop();
}
