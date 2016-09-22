#include<stack>
class commandparser{
protected:
	string            command;
	bool              isfile;
	string            filename;
	string            repetitionbuffer;
	stack<double>     storage;
	
	bool              openfile(filename);
public:
	string            read();
	bool              setfilename(string file);
	bool              store(double value);
	double            pop();
	double            top();
};
	
