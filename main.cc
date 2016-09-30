#include "commandregister/commandregister.cc"
#include "commandparser/commandparser.cc"
commandregister reg;
commandparser prs (&reg);
#include "corelang/corelang.cc"
#include "corelang/stackmanagement.cc"

int main(int argc, char* argv[]){
	reg.insertcommand("+",     add);
	reg.insertcommand("pop",   stack_pop);
	reg.insertcommand("popn",  stack_popn);
	prs.listen();
}
