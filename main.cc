#include "commandregister/commandregister.cc"
#include "commandparser/commandparser.cc"
commandregister reg;
commandparser prs (&reg);
#include "corelang/corelang.cc"
#include "corelang/arithmetic.cc"
#include "corelang/stackmanagement.cc"
#include "corelang/stringmanagement.cc"

int main(int argc, char* argv[]){
	if(argc>1){
		string file = argv[1];
        prs.setfilename(file);
	}
	reg.insertcommand("+",        add);
	reg.insertcommand("-",        sub);
	reg.insertcommand("*",        mul);
	reg.insertcommand("/",        div);
	reg.insertcommand("pop",      stack_pop);
	reg.insertcommand("popn",     stack_popn);
	reg.insertcommand("silentpop",stack_silentpop);
	reg.insertcommand("top",      stack_top);
	reg.insertcommand("topn",     stack_topn);
	reg.insertcommand("stack",    switchstack);
	reg.insertcommand("c",        commentsearch);
	reg.insertcommand("print",    printtoscreen);
	reg.insertcommand("input",    inputdouble);
	reg.insertcommand("sinput",   inputstring);
	reg.insertcommand("linebreak",newline);
	reg.insertcommand("strpop",   stringpop);
	reg.insertcommand("strpopn",  stringpopn);
	reg.insertcommand("strtop",   strtop);
	reg.insertcommand("strtopn",  strtopn);
	reg.insertcommand("vcheck",   vcheck);
	reg.insertcommand("return",   programreturn);
	reg.insertcommand("if",       ifstatement);
	return prs.listen();
}
