#include "commandregister/commandregister.cc"
#include "commandparser/commandparser.cc"
commandregister reg;
commandparser prs (&reg);
#include "corelang/corelang.cc"
#include "corelang/arithmetic.cc"
#include "corelang/stackmanagement.cc"

int main(int argc, char* argv[]){
	reg.insertcommand("+",     add);
	reg.insertcommand("-",     sub);
	reg.insertcommand("*",     mul);
	reg.insertcommand("/",     div);
	reg.insertcommand("pop",   stack_pop);
	reg.insertcommand("popn",  stack_popn);
	reg.insertcommand("top",   stack_top);
	reg.insertcommand("topn",  stack_topn);
	reg.insertcommand("stack", switchstack);
	reg.insertcommand("c",     commentsearch);
	reg.insertcommand("print", printtoscreen);
	prs.listen();
}
