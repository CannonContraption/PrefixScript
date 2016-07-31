#include"mod_stack.cc"

/* commands.cpp
 * Includes just the base language portion of the program.
 * It refers to morecommands.cpp to take care of extended language functions,
 * if only just to keep the files small enough for casual browsing. Note that
 * this entire file is JUST ONE FUNCTION, and a buttload of if statements.
 */

void commandparser::runcommand(string command){
    if(mod_stack         (command) == false)
    if(mod_bmath         (command) == false)
    if(mod_script        (command) == false)
    if(mod_math          (command) == false)
    if(mod_logic         (command) == false)
    if(mod_memory        (command) == false)
    if(mod_extra_stacks  (command) == false)
        mod_cnf           (command); //module command not found
}
