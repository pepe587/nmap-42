#include <stdio.h>
#include <unistd.h>
#include "parsing.h"

int main(int argc, char **argv)
{
    if (argc < 2)
                return printf("Invalid arguments\n"), 1;
    char **parsed_args = parse_arguments(argc, argv);
    if (arevalidsargs(parsed_args) == 0)
        return printf("Invalid arguments\n"), 1;
    if (!strcmp(parsed_args[HELP], "y"))
        printf("Help requested\n");
    //free_ptrs();
    return 0;
}