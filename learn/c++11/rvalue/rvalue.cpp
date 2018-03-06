#include <iostream>
#include <string>
using namespace std;
//int &&  c = a;    错误语句 (右值引用左值，必须转换为右值)
class k{
public:
 
    k(){ cout<<"canstruct\n";a =new int(5);    }
    k( const k&x){ cout<<"copy\n";a =new int  (*x.a); }
    k(k&&x){ cout<<"move\n";a=x.a   ;x.a =nullptr;}  //核心
    //k operator =(k a ){ cout<<"==\n";return a;} 
     ~k(){cout<<"delete\n"; delete a;}
    int  * a;
};
 k    fun ( )
{ 
  k   a ;
 
 cout<<a.a;
return    a;  
}
 
int  main() {
  
k c = fun();
 cout<<c.a;
cout<<"end\n";
 
}
 /*  扯淡的右值引用  其核心思想   就是把
      函数内 栈变量 申请的堆内存地址传出来   
      其在  移动构造的时候 把 a 的值 取出 构建右值
       然后 把  a  的值  置空  堆内存就被保留了下来
       右值构建的对象在销毁时调用析构 从而避免了内存泄露
       弄明白这些 需要透彻了解  拷贝构造 和移动构造的触发机制
       尼玛有这功夫为毛不用指针  
 */
       
