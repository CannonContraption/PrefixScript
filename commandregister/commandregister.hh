#include <iostream>
#include <vector>
using namespace std;

/*! \brief The command register, responsible for determining what commands are and what they do
 * 
 * The command register is the main guts of the interpreter. It links together a command to a function,
 * allowing for quick access to all commands in use, and quick runtime error checking to make sure there
 * is no overlap. This kind of system effectively allows us to not only check for new commands, but also
 * it allows us to quicky find associated functions without tons of superfluous logic. In the future, it
 * may even be possible to allow the script writer to enable and disable language functions on an individual
 * basis instead of relying on plugins (should they ever exist) to not overlap commands themselves. This
 * also would allow the scripter to possibly rename conflicting commands, and it adds an enormous amount of
 * flexability to the programming language itself.
 * 
 * This is also the whole reason why the interpreter was rewritten.
 */
class commandregister{
protected:
	/*! \brief Commandmodule single link structure
	 * 
	 * The commandmodule struct is the basis of the command
	 * register. It acts as the central object by which
	 * commands are searched for. When a person types a string,
	 * the corresponding function is executed. This model has
	 * the advantage of control, where it is possible to check
	 * to make sure no two commands have the same name. While
	 * this checking happens at runtime, not compile-time, it
	 * still is better than no checking, like before.
	 * 
	 * Note that there is a pointer for next, this is a single-
	 * linked list. The reason is because linked lists allow for
	 * some program commands or features to be disabled and
	 * enabled on-the-fly, allowing for programs to negotiate
	 * between competing libraries for available commands by
	 * disabling conflicting ones before a competing module with
	 * better support is loaded.
	 */
	struct commandmodule{
		bool (*function)(); /*!< Pointer to the function we'll run */
		string command; /*!< What the user types to make function() happen. */
		commandmodule * next; /*!< The next command in our list. */
	};
	commandmodule * head; /*!< the head of the register list */
	
public:
	bool insertcommand(string command, bool(*function)());
	bool checkforcommand(string command);
	bool runcommand(string command);
	void unlink();
};
