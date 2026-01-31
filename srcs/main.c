#include <stdio.h>
#include <unistd.h>
#include "parsing.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
    t_args *args = parse_arguments(argc, argv);
    if (arevalidsargs(args) == 0)
        return printf("Invalid arguments\n"), 1;
    if (!strcmp(args->parsed_args[HELP], "y"))
        printf("Help requested\n");
    //free_ptrs();
    return 0;
}