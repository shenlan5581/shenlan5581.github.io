 #ifndef main_h
 #define main_h

#define  MAXPTHREAD    50
#define  MAXCOMMADN    512
#define  MAXPATH       1024
#define  FILEBUF       4096
#define  MAXFILENAME   256
#define  RESULTLEN     32
#define  MAXDIRLEN     4096
#define  MAXCONFIGLINE 50
 /*******头文件******/
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
#include <netdb.h>
#include <pthread.h>  //线程 
#include <signal.h>
#include <sys/time.h> 
#include <iomanip>  
#include <sys/ioctl.h>

#include "transmission.h"
#include "interaction.h"
#include "fun.h"

using namespace std;
 
#endif
