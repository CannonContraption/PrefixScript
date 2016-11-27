#include <stack>
#include <fstream>
#include <sstream>

class commandparser{
	//We're using the same command register everywhere, so we want
	//to use a pointer in order to prevent the program from copying
	//the one we already have.
	commandregister   *cmdreg;
protected:
	/*
	 * basic common variables
	 * 
	 * Stuff that's common to most commands and used often
	 */
	string            command;
	/*
	 * File-read stuff
	 * 
	 * stdin vs. file stuff
	 */
	bool              isfile;
	string            filename;
	bool              scriptread;
	fstream           scriptfile;
	bool              openfile();
	/*
	 * Storage commands
	 * 
	 * Used for storing values. Also variables to select which
	 * storage stack to use
	 */
	stack<double>     storage[3];
	stack<string>     strstorage;
	int               currentstorage;
	//Old fail count code, need to check if this is still used
	int               failcount;
	int               maxfails;
	/*
	 * File-based repetition variables, allowing for 32 nested
	 * loops controlled by start and end line numbers.
	 */
	int               repeatlower[32];
	int               repeatupper[32];
	char              repeatmode[32];
	int               repeatindex;
	bool              repeatread;
	vector<string>    repetitionbuffer[32];
	int               repeatlevel; //Stacks, so nested loops work
	/*
	 * Memory
	 * 
	 * 32 stack-independant memory slots
	 */
	double            memory[32];
	int               returncode;
	bool              exitnow;
public:
	/*
	 * Global commands
	 * 
	 * things like reading commands, and stack management
	 */
	string            read();
	string            strtop();
	string            strpop();
	double            pop();
	double            top();
	void              store(double value);
	void              strstore(string value);
	bool              empty();
	bool              strempty();
	int               listen();
	void              setstack(int stacknum);
	double            todouble(const string& s);
	double            todouble_multsafe(const string& s);
	int               toint(const string& s);
	/*
	 * File io commands
	 * 
	 * for setting file mode, and for reading from a file
	 */
	bool              setfilename(string file);
	/*
	 * Constructors and exit commands
	 * 
	 * Defines headers for constructors and exit commands.
	 * This is so we can actually get a hold of our command
	 * register and keep it common with the rest of the 
	 * program.
	 */
	commandparser     (commandregister * r);
	void              exitprogram(int rcd);
};
	
