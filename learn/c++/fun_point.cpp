
#include <string>
#include <iostream>
using namespace std;



void (*fun)(void *); //一个指针

void t(void *) {
 cout <<"T"<<endl;
}

int main(){
fun = &t;    //指针赋值操作
fun = t;     //效果一样
void * s;
fun(s);     //调用





return 0;
}
