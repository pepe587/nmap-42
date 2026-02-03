#include "ft_nmap.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return printf("Invalid arguments\n"), 1;

    char **valided_args = clear_args(argv);
    if (!valided_args)
        return 1;

    if (valided_args[HELP])
        return printf("Help requested\n"), 0; //print_help();

    t_args *args = parse(valided_args);

    (void)args;
    //start_map();
    
    //free_ptrs();
    return 0;
}