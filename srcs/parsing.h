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

typedef struct s_args
{
    bool help;
    int *ports;
    char *ip;
    char *ip;
    int speedup;
    int scan_type;
}               t_args;


char      **parse_arguments(char **argv);
bool         arevalidsargs(char **args, bool ip_or_file);