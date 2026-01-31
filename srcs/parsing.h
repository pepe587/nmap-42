#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

enum args
{
    HELP,
    PORTS,
    IP,
    SPEEDUP,
    SCAN_TYPE
};


char      **parse_arguments(int argc, char **argv);
int         arevalidsargs(char **args);