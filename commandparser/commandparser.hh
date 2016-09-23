#include<stack>
#include<fstream>
class commandparser{
protected:
	string            command;
	bool              isfile;
	string            filename;
	vector<string>    repetitionbuffer;
	stack<double>     storage;
	stack<double>     storage1;
	stack<double>     storage2;
	int               currentstorage;
	int               failcount;
	int               maxfails;
	fstream           scriptfile;
	
	bool              openfile();
public:
	string            read();
	bool              setfilename(string file);
	bool              store(double value);
	double            pop();
	double            top();
};
	
