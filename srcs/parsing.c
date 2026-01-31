#include "parsing.h"

int validate_ip(char *ip)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    if (result == -1 || result == 0)
        return 0;
    return 1;
}

int validate_file(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
        return 0;
    close(fd);
    return 1;
}

int validate_num_threads(char *num_threads)
{
    for (int y = 0; num_threads[y]; y++)
    {
        while (num_threads[y] == ' ')
            ++y;
        if (num_threads[y] == '\0')
            break;
        if (num_threads[y] == '-' || num_threads[y] == '+')
            ++y;
        if (!isdigit(num_threads[y]))
            return 0;       
    }
    int num = atoi(num_threads);
    if (num < 1 || num > 250)
        return 0;
    return 1;
}


//falta manejar el tipo de SCAN y los puertos
int arevalidsargs(char **args)
{
    if (!args[IP] && !args[HELP])
        return printf("No ip provided\n"),0;
    if (validate_file(args[IP]) == 0 && validate_ip(args[IP]) == 0)
        return printf("Invalid ip provided\n") ,0;
    if (args[SPEEDUP] && validate_num_threads(args[SPEEDUP]) == 0)
        return printf("Invalid number of threads provided\n"), 0;
    return 1;
}

char   **parse_arguments(char **argv)
{
    char **parsed_args = (char **)malloc(sizeof(char *) * 6);
    memset(parsed_args, 0, sizeof(char *) * 6);
    for (int y = 1; argv[y]; y++)
    {
        if (!strcmp(argv[y], "--help") || !strcmp(argv[y], "-h"))
        {
            parsed_args[HELP] = malloc(sizeof(char) * 2);
            parsed_args[HELP][0] = 'y';
            parsed_args[HELP][1] = '\0';
            return parsed_args;
        }
        else if (!strcmp(argv[y], "--ports"))
        {
            parsed_args[PORTS] = malloc(sizeof(char) * strlen(argv[y + 1]) + 1);
            strcpy(parsed_args[PORTS], argv[y + 1]);
            ++y;
        }
        else if (!strcmp(argv[y], "--ip") || !strcmp(argv[y], "--file"))
        {
            parsed_args[IP] = malloc(sizeof(char) * strlen(argv[y + 1]) + 1);
            strcpy(parsed_args[IP], argv[y + 1]);
            ++y;
        }
        else if (!strcmp(argv[y], "--speedup"))
        {
            parsed_args[SPEEDUP] = malloc(sizeof(char) * strlen(argv[y + 1]) + 1);
            strcpy(parsed_args[SPEEDUP], argv[y + 1]);
            ++y;
        }
        else if (!strcmp(argv[y], "--scan-type"))
        {
            parsed_args[SCAN_TYPE] = malloc(sizeof(char) * strlen(argv[y + 1]) + 1);
            strcpy(parsed_args[SCAN_TYPE], argv[y + 1]);
            ++y;
        }
    }
    if (arevalidsargs(parsed_args) == 0)
        return NULL;
    return parsed_args;
}
