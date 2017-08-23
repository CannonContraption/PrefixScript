#include <stack>
#include <fstream>
#include <sstream>
#include <string>


/*! \brief The command parser
 * 
 * Class built for parsing and interpreting core language functions, such as handling logic
 * and IO for individual commands. It is built as a class in order to allow broader access to
 * its functions, and to potentially allow multiple copies to run simultaniously.
 */
class commandparser{
	commandregister   *cmdreg; //!< Pointer to the global command register object.
public: //Encapsulation is stupid in this context.
	string            command; //!< Current command. Used for recursive parsing.
	/*
	 * File-read stuff
	 * 
	 * stdin vs. file stuff
	 */
	bool              isfile; //!< Tells the program whether we're dealing with stdin or a file
	string            filename; //!< File name should we be using one
	bool              scriptread; //!< tells the program whether we're reading a script.
	fstream           scriptfile; //!< File stream to use instead of std::cin when reading from a file
	bool              openfile();
	/*
	 * Storage commands
	 * 
	 * Used for storing values. Also variables to select which
	 * storage stack to use
	 */
	stack<double>     storage[3]; //!< Our three storage stacks, used for storing all output
	stack<string>     strstorage; //!< String storage stack, same as double one but for strings
	int               currentstorage; //!< Which storage stack we're using right now (1-3)
	//Old fail count code, need to check if this is still used
	int               failcount; //!< Deprecated count of failed commands. Has been succeeded by EOF support
	int               maxfails; //!< Deprecated maximum number of failed commands. Has been succeeded by EOF support
	/*
	 * File-based repetition variables, allowing for 32 nested
	 * loops controlled by start and end line numbers.
	 */
	int               repeatlower[32]; //!< Lower repetition buffer line number
	int               repeatupper[32]; //!< upper repetition buffer line number
  char              repeatmode[32]; //!< Function for each level of the repetition buffer
  vector<int>       repeatindex; //!< What line the buffer is currently executing
  bool              repeatread; //!< representation of whether we're reading from the repeition buffer
  bool              previousrepeat; //!< previous repetition buffer level
  vector<string>    repetitionbuffer; //!< the repetition buffers themselves live here
  int               repeatlevel; //!< current level of repeat. a loop in a loop would have index 1
  string            condition; //!< conditional string used for testing truth
  /*
   * Memory
   * 
   * 32 stack-independant memory slots
   */
  double            memory[32]; //!< 32 double values for memory (like a calculator)
  double            repeatmemory[32]; //!< 32 slot repeition buffer, for testing values
  int               returncode; //!< return code for the script, and possibly the interpreter
  bool              exitnow; //!< tells the command listener whether to exit right now
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
  void              memstore(int pos, double value);
  double            memrecall(int pos);
  /*
   * File io commands
   * 
   * for setting file mode, and for reading from a file
   */
  bool              setfilename(string file);
  /*
   * Loop and Branching Path control
   * 
   * Defines some basic functions for doing repetition and
   * logic.
   */
  bool              testcondition(string first, string condition, string second);
  void              setrepetitionbuff(string buff);
  void              increaserepeatlevel();
  void              decreaserepeatlevel();
  void              execbuff();
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

  bool getScriptRead();
};
