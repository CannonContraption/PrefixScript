/* Command-Not-Found module
 * Version 1, original implementation
 * Used for alerting the user when they have typed
 * a command which does not exist.
 */
#ifndef MOD_CNF
#define MOD_CNF 1
bool commandparser::mod_cnf(string command){
    if(command == "setfails"){
        command = read();
        maxfails = toint(command);
        return true;
    } else {
        cerr<<"ERROR: Invalid command: "<<command<<endl;
        failcount++;
        if(failcount > maxfails){
            cerr<<"Number of bad commands is over "<<maxfails<<". Exiting."<<endl;
            command = "exit";
            throw(2);
            return false;
        }
    }
}
#endif