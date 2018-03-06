
//************** 熟练用模板以后再回来学习吧 ****************
//template
using namespace std;
#include <iostream>
#include <string>
template <typename T>
void  fun (T a ) { cout<<"template"<<endl;} 
	
template<>
void fun(int a) {  cout<<"int"<<endl;} //特例化
//////////////////////////////////////////////////
 
template <typename T , int N>               //元函数  ？？int含义 这是一个非类型模板参数
struct b{                                   //元数据是编译时常量
 static const int  a = N;                   //编译时期可以操作的数据
};      
// 实例化                                    //非类型模板参数的模板是残必须是常量表达式
template <>
struct b<int,0>{  
 static const int a = 199; // 
};
template <>
struct b<int,'d'>{  
 static const int a = 99;
};

//=============================================
 template <class A1,class A2>
 class c {
public:
     A1  a1;
     A2  a2;
 };
 template <class A1>            //偏特例化 
 class c <int,A1>  {
public:
     A1  a1;
     A1  a2;
 };

c<int,int>   aa;
c<int,char>  bb;
//核心 仍然是通过模板实参  实例出一个具体类或者函数 
/* 思考   ？ 
   代码复用
    类和模板的区别

*/
/*1数值计算
  2类型计算
类型和非类型
*/
int main () {
cout<<b<int,3>::a<<endl;         //调用
cout<<b<int,2>::a<<endl;         //类静态成员访问方式
cout<<b<int,5>::a<<endl;
}

