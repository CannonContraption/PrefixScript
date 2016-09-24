#include<stack>
#include<fstream>
class commandparser{
	commandregister cmdreg;
protected:
	string            command;
	bool              isfile;
	string            filename;
	vector<string>    repetitionbuffer;
	stack<double>     storage[3];
	int               currentstorage;
	int               failcount;
	int               maxfails;
	int               repeatlower;
	int               repeatupper;
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
	commandparser     (commandregister *r) {cmdreg = *r;}
};
	
