#include <iostream>
#include <vector>
using namespace std;
class commandregister{
protected:
	/*
	 * The commandmodule struct is the basis of the command
	 * register. It acts as the central object by which
	 * commands are searched for. When a person types a string,
	 * the corresponding function is executed. This model has
	 * the advantage of control, where it is possible to check
	 * to make sure no two commands have the same name. While
	 * this checking happens at runtime, not compile-time, it
	 * still is better than no checking, like before.
	 */
	struct commandmodule{
		bool (*function)();
		string commandname;
	};
	/*
	 * Because I'm lazy, these commands are put in a vector
	 * instead of something which may be more efficient, like
	 * a linked list.
	 */
	vector<commandmodule> commands;
public:
	/*
	 * The command register, being very basic, requires no more
	 * than a check, run, and insert command. It does no more
	 * than just store the commands we have at our disposal.
	 */
	bool insertcommand(string command, bool(*function)());
	bool checkforcommand(string command);
	bool runcommand(string command);
};
