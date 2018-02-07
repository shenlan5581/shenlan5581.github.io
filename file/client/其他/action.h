



#include <stdio.h>
#include <string.h>
#include <iostream>
#include "interaction.h"
#include "transmission.h"
      
using namespace std;

class action
{   
public:  
    transmission  A_t;      //传输对象
    path          A_path;   //路径更改
    dir           A_dir;    //目录 和路径 对象
    interaction   A_I;      //交互对象
     
    action(int sock);
// action
    void cd(); 


};