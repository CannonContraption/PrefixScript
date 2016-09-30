#include "corelang.hh"

corelang(commandparser * par, commandregister * reg){
	cparser = par;
	cregister = reg;
	cregister->insertcommand("+", add);
	cregister->insertcommand("-", sub);
	cregister->insertcommand("*", mul);
	cregister->insertcommand("/", div);
}
