#include "commandregister/commandregister.cc"
#include "commandparser/commandparser.cc"
#include "corelang/corelang.cc"
commandregister reg;
commandparser prs (&reg);

bool add(){
	double number;
	double sum = 0;
	string input;
	for(;;){
		cin>>input;
		if(input == "/+"){
			cout<<sum<<endl;
			return true;
		}
		else {
			number = prs.todouble(input);
			sum += number;
		}
	}
}

int main(int argc, char* argv[]){
	corelang        lng (&prs);
	
	reg.insertcommand("+", add);
	prs.listen();
}
