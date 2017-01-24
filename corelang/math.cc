#include<cmath>

/*! \brief Advanced mathematical functions module

Adds trig functions, powers, sqrt to the main language core by adding a math command
*/
bool advancedmath(){
	double a;
	double b;
	double c;
	double d;
	bool issx;
	string command = prs.read();
	while(command != "/math"){
		if(command == "sqrt"){
			if(prs.empty()){
				cerr<<"ERROR: Stack is empty!"<<endl;
			} else {
				a = prs.pop();
				a = sqrt(a);
				prs.store(a);
			}
		}
		else if(command == "abs"){
			if(!prs.empty()){
				prs.store(abs(prs.pop()));
			}
			else{
				cerr<<"ERROR: Stack is empty!"<<endl;
			}
		}
		else if (command == "pow"){
			if(!prs.empty()){
				command = prs.read();
				if(command == "pop")
					c = prs.pop();
				else if(command =="top")
					c = prs.top();
				else
					c = prs.toint(command);
				b = prs.pop();
				prs.store(pow(b,c));
			}
			else{
				cerr<<"ERROR: Stack is empty!"<<endl;
			}
		}
		else if (command == "loge"){
			if(!prs.empty()){
				a = prs.pop();
				prs.store(log(a));
			} else {
				cerr<<"ERROR: Stack is empty!"<<endl;
			}
		}
		else if (command == "log10"){
			if(!prs.empty()){
				a = prs.pop();
				prs.store(log10(a));
			} else {
				cerr<<"ERROR: Stack is empty!"<<endl;
			}
		}
		else if(command == "cos" || command == "acos" || command == "sin" || command == "asin" || command== "tan" || command=="atan"){
			if(command == "acos" || command == "asin" || command == "atan") issx = true; else issx = false;
			if(command == "cos"  || command=="acos") d=1;
			if(command == "sin"  || command=="asin") d=2;
			if(command == "tan"  || command=="atan") d=3;
			command = prs.read();
			if(!prs.empty()){
				if(command == "rad")
					a = prs.pop();
				else if(command == "deg")
					a = (3.14159265358979/180)*prs.pop();
				if(d == 1)
					b = cos(a);
				if(d == 2)
					b = sin(a);
				if(d == 3)
					b = tan(a);
				if(issx)
					prs.store(1/b);
				else
					prs.store(b);
			} else {
				cerr<<"ERROR: Stack is empty!"<<endl;
			}
		}
		else if (command == "/math");
		else{
			cerr<<"math: ERROR: Command not valid."<<endl;
		}
		command = prs.read();
	}
}
