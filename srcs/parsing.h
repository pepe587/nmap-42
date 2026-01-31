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

typedef struct s_args
{
    char    **parsed_args;
}               t_args;

t_args      *parse_arguments(int argc, char **argv);
int         arevalidsargs(t_args *args);