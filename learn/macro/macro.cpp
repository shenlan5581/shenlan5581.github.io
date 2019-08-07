#include <stdio.h>
//#include <iostream>
//#include <string>
//using namespace std;

#define   NAME "xingke"
#define   NAME2  xingke 
#define   SHOW1 NAME;  
#define   SHOW2(name)    std::cout< <#name;      //cout< <"dd"
#define   SHOW3(name)    std::cout< <name;       //cout< <server_name
#define   SHOW4(X)       server_##X;            //server_+name
#define   SHOW5(X)       10*X;                  //  10*5

#define   A(M,arg...)     printf(M,arg);
#define   B(N,...)        printf(N,##__VA_ARGS__);  //同上
 // 1   无符号时 直接语句     替换
 // 2#  将参数转化为字符串    替换
 // 3## 连接标识符号后       替换
 //   (可尝试先  写出需要的语句 然后再转换为宏） 
 
int main()  
{  
    /*   int  server_name=10;  

       std::cout << SHOW1;      //  输出‘xingke’ 
       
       SHOW2(dd);               //  输出/’dd; 
       
       SHOW3(server_name);      //  输出 10;
       std::cout<<SHOW4(name);  //  输出 10;
       std::cout<<SHOW5(5);     //  输出 50;
                                                 */

    char v='k';
    char b='y';
    A("%c%c",v,b)  //输出 ky
    B("xingke, %s\n","yuxinji"); //输出 xingke yuxinji
    printf(__FILE__);
    printf(__TIME__);

}


