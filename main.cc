#include "commandregister/commandregister.cc"
#include "commandparser/commandparser.cc"
#include "corelang/corelang.cc"

int main(int argc, char* argv[]){
	commandregister reg;
	commandparser   prs (&reg);
	corelang        lng (&prs);
	
	reg.insertcommand("+", corelang::add);
	prs.listen();
}
