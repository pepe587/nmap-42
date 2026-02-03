#include "parsing.h"

bool validate_ip(char *ip)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    if (result == -1 || result == 0)
    {
        printf("Invalid ip provided\n");
        return 0;
    }
    return 1;
}

bool validate_file(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("File not found\n");
        return 0;
    }
    close(fd);
    return 1;
}

bool validate_num_threads(char *num_threads)
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
            return printf("Invalid format for number of threads\n") ,0;       
    }
    int num = atoi(num_threads);
    if (num < 1 || num > 250)
    {
        printf("Invalid number of threads\n");
        return 0;
    
    }
    return 1;
}


static bool is_valid_port_number(int port)
{
	return (port >= 1 && port <= 65535);
}

bool validate_ports(char *ports)
{
	int i = 0;

	if (!ports || !ports[0])
		return false;

	while (ports[i])
	{
		if (!isdigit(ports[i]))
			return false;

		int start = atoi(&ports[i]);
		if (!is_valid_port_number(start))
			return false;

		while (isdigit(ports[i]))
			i++;

		if (ports[i] == '-')
		{
			i++;
			if (!isdigit(ports[i]))
				return false;

			int end = atoi(&ports[i]);
			if (!is_valid_port_number(end) || end < start)
				return false;

			while (isdigit(ports[i]))
				i++;
		}

		if (ports[i] == ',')
			i++;
		else if (ports[i] != '\0')
			return false;
	}
	return true;
}

static bool is_valid_scan(char *scan)
{
	return (!strcmp(scan, "SYN")
		|| !strcmp(scan, "NULL")
		|| !strcmp(scan, "FIN")
		|| !strcmp(scan, "XMAS")
		|| !strcmp(scan, "ACK")
		|| !strcmp(scan, "UDP"));
}

bool validate_scan_type(char *scan_type)
{
	int i = 0;
	int start;

	if (!scan_type || !scan_type[0])
		return false;

	while (scan_type[i])
	{
		start = i;

		while (scan_type[i] && scan_type[i] != ',')
			i++;

		if (i - start == 0)
			return false;

		char tmp[8];
		int len = i - start;

		if (len >= (int)sizeof(tmp))
			return false;

		memcpy(tmp, &scan_type[start], len);
		tmp[len] = '\0';

		if (!is_valid_scan(tmp))
			return false;

		if (scan_type[i] == ',')
			i++;
	}
	return true;
}

bool arevalidsargs(char **args, bool ip_or_file) //ip_or_file if = 1 ip provided if = 0 file provided
{
    if (!args[IP] && !args[HELP])
        return printf("No ip provided\n"), 0;
    if (ip_or_file == 0 && !validate_file(args[IP]))
        return 0;
    if (ip_or_file && !validate_ip(args[IP]))
        return 0;
    if (args[SPEEDUP] && !validate_num_threads(args[SPEEDUP]))
        return 0;
    if (args[PORTS] && !validate_ports(args[PORTS]))
        return 0;
    if (args[SCAN_TYPE] && !validate_scan_type(args[SCAN_TYPE]))
        return 0;
    return 1;
}

char   **parse_arguments(char **argv)
{
    bool ip_or_file = 0;
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
            if (!strcmp(argv[y], "--ip"))
                ip_or_file = 1;
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
    if (arevalidsargs(parsed_args, ip_or_file) == 0)
        return NULL;
    return parsed_args;
}
