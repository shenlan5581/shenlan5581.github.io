
#ifndef CONFIG_H
#define CONFIG_H

#define MAXMSGLEN 256

struct Config{
 int   Listen_port;
 bool  Multi_accept;
 char  Welcome_msg[MAXMSGLE];
 char  GoodBye_Msg[MAXMSGLE];
 };

int   ConfigInit(struct Config * , char*file_name);
char *GetValue(struct Config *,char * name);
int   SetValue(struct Config *,char * name, char * value);
int   ConfigDestory(struct Config*);


#endif
