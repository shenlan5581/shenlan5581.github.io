// 邢柯公共函数 
#ifndef _FUN_C
#define _FUN_C

#include "k.h"
  char  str[128];

char * k_ntop(struct sockaddr * addr)
{           
    
		struct sockaddr_in * add;

		add  = (struct sockaddr_in *)addr;
  	 
 	
		inet_ntop(AF_INET,&(add->sin_addr.s_addr),&str,sizeof(str));
	//	printf("%s\n", str);
   return(str);
}

struct addrinfo* 
host_serv(char* hostname,char * serv,int  family,int socktype)
{      
	   int n; 
		struct addrinfo hit,*res;
		  hit.ai_flags  = AI_CANONNAME;
		  hit.ai_family = family;
		  hit.ai_socktype = socktype;         
	if((getaddrinfo(hostname,serv,&hit,&res))!=0)
	 {   printf("地址未找到\n");
		 return (NULL); 
		 exit(0);
	}      
	return(res);
}

void cout(char  *str)
{
	printf("%s\n",str);
}
 

void sock_set_port(struct sockaddr *addr , u_short port)
{                
 struct sockaddr_in *addr_in;
   addr_in = (struct sockaddr_in *)addr;
   addr_in->sin_port = htons(port);    
}

 

int sock_cmp_addr(const struct sockaddr *sa1, const struct sockaddr *sa2,
 socklen_t salen)
{
 
if (sa1->sa_family != sa2->sa_family)
    {
		return(-1);
	} 
 
return (memcmp( &((struct sockaddr_in *) sa1)->sin_addr,
   &((struct sockaddr_in *) sa2)->sin_addr,salen));
 
} 

void tv_sub(struct timeval *out,struct timeval *in)
{   
	 if((out->tv_usec -= in->tv_usec)<0)
	 {--out->tv_sec;
	  out->tv_usec+=1000000;
	 }
out->tv_sec -= in->tv_sec;

}
 
#endif