#pragma once

// c_libraries
#include <stdbool.h>     // para bool, true, false (si no lo tienes ya)
#include <sys/types.h>
#include <sys/socket.h>  // sockets
#include <netinet/in.h>  // struct sockaddr_in, AF_INET
#include <arpa/inet.h>   // inet_pton
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
//#include <pcap.h>       //captura de paquetes
#include <ctype.h>
#include <fcntl.h>

// personal_libraries
#include "parsing.h"