#include <string>
#include <iostream>
using namespace std;
class A {
public:
static void  afun(A * obj){A::b=20;  cout<<obj->a<<endl; }  //##静态函数可以访问私有变量 但必须有对象实例
static int   b;
private:
int a=10;
};
int 	A::b=0;
int main() {
A  s;
A::afun(&s);

}
