
/*extern  和 自定义命名空间中的变量*/


#include <iostream>
#include <string>
#include "t1.h"
                                  // 在k 空间的头文件中声明
using namespace std;
int main()
{
cout<<k::a <<endl;                //2 使用该变量

}
