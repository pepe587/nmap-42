#include "parsing.h"

char   **parse_arguments(int argc, char **argv)
{
    char **parsed_args = (char **)malloc(sizeof(char *) * (argc - 1));
    memset(parsed_args, 0, sizeof(char *) * (argc - 1));
    for (int y = 1; argv[y]; argv++)
    {
        if (!strcmp(argv[y], "--help") || !strcmp(argv[y], "-h"))
        {
            parsed_args[HELP] = malloc(sizeof(char) * 2);
            parsed_args[HELP][0] = 'y';
            parsed_args[HELP][1] = '\0';
            return parsed_args;
        }
        else if (!strcmp(argv[y], "--ports"))
            printf("ports args === true\n"); //args[PORTS] = true;
        else if (!strcmp(argv[y], "--ip"))
            printf("ip args === true\n"); //args[IP] = true;
        else if (!strcmp(argv[y], "--speedup"))
            printf("speedup args === true\n"); //args[SPEEDUP] = true;
        else if (!strcmp(argv[y], "--scan-type"))
            printf("scan-type args === true\n"); //args[SCAN_TYPE] = true;
    }
    return parsed_args;
}


int arevalidsargs(char **args)
{
    int counter = 0;
    for (int i = 0; args[i]; i++)
    {
       if (args[i])
           counter++;
    }
    if (counter > 0)
        return 1;
    return 0;
}