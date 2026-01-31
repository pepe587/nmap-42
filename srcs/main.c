#include "ft_nmap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return printf("Invalid arguments\n"), 1;

    char **parsed_args = parse_arguments(argv);
    if (!parsed_args)
        return 1;

    if (parsed_args[HELP])
        return printf("Help requested\n"), 0; //print_help();

    //start_map();
    
    //free_ptrs();
    return 0;
}