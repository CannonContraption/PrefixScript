#include <stack>
#include <fstream>
#include <sstream>

class commandparser{
	commandregister   *cmdreg;
protected:
	string            command;
	bool              isfile;
	string            filename;
	vector<string>    repetitionbuffer[32];
	int               repeatlevel; //Stacks, so nested loops work
	stack<double>     storage[3];
	stack<string>     strstorage;
	int               currentstorage;
	int               failcount;
	int               maxfails;
	int               repeatlower[32];
	int               repeatupper[32];
	char              repeatmode[32];
	double            memory[32];
	int               repeatindex;
	bool              repeatread;
	bool              scriptread;
	
	fstream           scriptfile;
	
	bool              openfile();
public:
	string            read();
	bool              setfilename(string file);
	void              store(double value);
	void              strstore(string value);
	string            strtop();
	string            strpop();
	double            pop();
	double            top();
	bool              empty();
	bool              strempty();
	bool              listen();
	double            todouble(const string& s);
	double            todouble_multsafe(const string& s);
	commandparser     (commandregister * r);
};
	
