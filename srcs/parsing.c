#include "parsing.h"

t_args   *parse_arguments(int argc, char **argv)
{
    t_args *args = malloc(sizeof(t_args));

    args->parsed_args = (char **)malloc(sizeof(char *) * (argc - 1));
    memset(args->parsed_args, 0, sizeof(char *) * (argc - 1));
    for (int y = 1; argv[y]; argv++)
    {
        if (!strcmp(argv[y], "--help") || !strcmp(argv[y], "-h"))
        {
            args->parsed_args[HELP] = malloc(sizeof(char) * 2);
            args->parsed_args[HELP][0] = 'y';
            args->parsed_args[HELP][1] = '\0';
            return args;
        }
        else if (!strcmp(argv[y], "--ports"))
            printf("ports args === true\n"); //args->args[PORTS] = true;
        else if (!strcmp(argv[y], "--ip"))
            printf("ip args === true\n"); //args->args[IP] = true;
        else if (!strcmp(argv[y], "--speedup"))
            printf("speedup args === true\n"); //args->args[SPEEDUP] = true;
        else if (!strcmp(argv[y], "--scan-type"))
            printf("scan-type args === true\n"); //args->args[SCAN_TYPE] = true;
    }
    return args;
}


int arevalidsargs(t_args *args)
{
    int counter = 0;
    for (int i = 0; args->parsed_args[i]; i++)
    {
       if (args->parsed_args[i])
           counter++;
    }
    if (counter > 0)
        return 1;
    return 0;
}