#include <iostream>
#include <vector>
using namespace std;
class commandregister{
protected:
	struct commandmodule{
		bool (*function)();
		string commandname;
	};
	vector<commandmodule> commands;
public:
	bool insertcommand(string command, bool(*function)());
	bool checkforcommand(string command);
	bool runcommand(string command);
};
