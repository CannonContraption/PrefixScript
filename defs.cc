#include "defs.hh"
#include "versioninfo.h"

void commandparser::main(){
    a = 0.0;
    b = 0.0;
    c = 0;
    d = 0;
    repeatindex = 0;
    repeatc = 0;
    issx = false;
    int versionmajor = PrefixScript_VERSION_MAJOR;
    double versionminor = PrefixScript_VERSION_MINOR / 1000.0;
    version = versionmajor + versionminor;
    int mincompmajor = PrefixScript_MINCOMP_MAJOR;
    double mincompminor = PrefixScript_MINCOMP_MINOR / 1000.0;
    double mincomp = mincompmajor + mincompminor;
    mincompversion = mincomp;
    failcount = 0;
    maxfails = 10;
    scriptreturn = 99999;
}
