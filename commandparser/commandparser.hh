#include<stack>
#include<fstream>
class commandparser{
protected:
	string            command;
	bool              isfile;
	string            filename;
	vector<string>    repetitionbuffer;
	stack<double>[3]  storage;
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
	
