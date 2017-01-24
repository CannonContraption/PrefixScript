#include "commandregister/commandregister.cc"
#include "commandparser/commandparser.cc"
commandregister reg;
commandparser prs (&reg);
#include "corelang/corelang.cc"
#include "corelang/arithmetic.cc"
#include "corelang/stackmanagement.cc"
#include "corelang/stringmanagement.cc"
#include "corelang/math.cc"
#include "corelang/repetition.cc"

/*!
\mainpage PrefixScript Developer Documentation

\section intro Introduction

Welcome to PrefixScript's developer documentation!

This interface will show you the basic API documentation for the PrefixScript interpreter.
In order to change or correct this documentation, please look in the code itself. The comment
above each function or class pertains to the section here in the doc pages.

\section nav Navigation

In order to navigate this interface, select an item in the sidebar or in the toolbar at the
top of the page. In the toolbar, if there is a downward-pointing arrow, that item is a dropdown
and can give you greater control over what is displayed when clicked.

\section versioning Versioning and Code repository

PrefixScript is hosted on [Github](github.com). In order to jump straight to the PrefixScript
repo, click [here](https://github.com/CanonContraption/PrefixScript). In order to contribute to
PrefixScript please fork the repository, make your change and test it, then submit a pull
request.

Please note that at the time of writing, the current development branch is truemodular, not master.

\section userdoc User Documentation

<i>but hold on a moment,</i> you say, *I want user documentation, so I can learn to code in
PrefixScript!*

In order to find complete documentation on PrefixScript, open the doc.html file in the root
directory of the source tree. There each command and its functions are described in great detail.
*/

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
	reg.insertcommand("memstore", memstore);
	reg.insertcommand("memrecall",memrecall);
	reg.insertcommand("math",     advancedmath);
	reg.insertcommand("string",   codestring);
	return prs.listen();
}
