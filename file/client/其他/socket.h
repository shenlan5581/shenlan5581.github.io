
#ifndef _sock_h
#define _sock_h


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string>
#include <string.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;

class _socket
{
public:
  int sockfd;
   _socket(char *addr, int port);
};


#endif 