#pragma once
#include "ft_nmap.h"

enum args
{
    HELP,
    PORTS,
    IP,
    SPEEDUP,
    SCAN_TYPE
};


char      **parse_arguments(char **argv);
int         arevalidsargs(char **args);