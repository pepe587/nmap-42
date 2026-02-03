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
    char *file;
    int speedup;
    int scan_type;
}               t_args;

typedef struct s_range
{
    int start;
    int end;
}               t_range;



char      **clear_args(char **argv);
bool         arevalidsargs(char **args, bool ip_or_file);
t_args        *parse(char **clean_args);