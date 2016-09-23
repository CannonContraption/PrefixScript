#include "Stacky.cpp"
#include "commandregister/commandregister.cc"
#include "commandparser/commandparser.cc"

int main(int argc, char* argv[]){
	commandregister reg;
	commandparser   prs;
	prs.main();
}
