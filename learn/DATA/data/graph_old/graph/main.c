/*
图   通过数据 （V,E)构建图 （邻接表）
*/


#include "graph.h"
#include <stdio.h>

int main() {
 char* s = (
        "  mama------------>xingke  \n"
        "   | 0            / 1 ^    \n"
        "   |             v    |    \n"
        "   |      yuxinji     |    \n"
        "   |     ^  2    \\    |    \n"
        "   v 3  /         v 4 |    \n"
        "  yaoao----------->buding  \n"
        );

char *vertex[5];     //V 代表顶点
     vertex[0] = "mama";
     vertex[1] = "xingke";
     vertex[2] = "yuxinji";
     vertex[3] = "yaoao";
     vertex[4] = "buding";   

int edge[] = {0,1,  0,3,
              1,2,
              2,4, 
              3,2,  3,4,
              4,1 };  //E  关系集合 2个为一对
printf("%s",s);

Graph * k=Init(5); 
Insert(k,5,0,1);
Insert(k,5,0,3);
Insert(k,5,1,2);
Insert(k,5,2,4);
Insert(k,5,3,2);
Insert(k,5,3,4);
Insert(k,5,4,1);
Insert(k,5,2,0);


display(k,5,vertex);

}
 //打印邻接表


