#include"mod_stack.cc"
#include"mod_bmath.cc"
#include"mod_script.cc"
#include"mod_logic.cc"
#include"mod_memory.cc"
#include"mod_strings.cc"
#include"mod_cnf.cc"
#include"mod_math.cc"
#include"stacks.cpp"

/* commands.cpp
 * Includes just the base language portion of the program.
 * It refers to morecommands.cpp to take care of extended language functions,
 * if only just to keep the files small enough for casual browsing. Note that
 * this entire file is JUST ONE FUNCTION, and a buttload of if statements.
 */

void commandparser::runcommand(string command){
    #ifdef MOD_STACK
    if(mod_stack         (command) == false)
    #endif
    #ifdef MOD_BMATH
    if(mod_bmath         (command) == false)
    #endif
    #ifdef MOD_SCRIPT
    if(mod_script        (command) == false)
    #endif
    #ifdef MOD_MATH
    if(mod_math          (command) == false)
    #endif
    #ifdef MOD_LOGIC
    if(mod_logic         (command) == false)
    #endif
    #ifdef MOD_MEMORY
    if(mod_memory        (command) == false)
    #endif
    #ifdef MOD_EXTRA_STACKS
    if(mod_extra_stacks  (command) == false)
    #endif
    #ifdef MOD_STRINGS
    if(mod_strings       (command) == false)
    #endif
    #ifdef MOD_CNF
        mod_cnf           (command); //module command not found
    #endif
}
