#include<stack>
#include<fstream>
class commandparser{
	commandregister   *cmdreg;
protected:
	string            command;
	bool              isfile;
	string            filename;
	stack<double>     storage[3];
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
	bool              store(double value);
	double            pop();
	double            top();
	commandparser     (commandregister * r) {cmdreg = r;}
};
	
