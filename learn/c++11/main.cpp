/*     *******可能常用特性*******

final/override控制
快速初始化类成员变量    继承/委派构造函数      右值引用
初始化列表    auto   智能指针   原子操作  线程    默认函数控制 =defaule
nullptr      lambda函数    原声字符串字面量      
 
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <assert.h>
#include <memory>
#include <atomic>
#include <thread>  //线程库
using namespace std;
/*预定义标识符*/
/*
__func__ 
#error	
#pragma once  //只包含一次
_Pragma("noce")
*/
//================================
/*####静态断言
static_assert( ,)实用于编译时期
assert()  使用于运行时期*/

#define assert_static(e) \
           assert(1/(e));

//==================================

/*#### noexcept修饰符noexcept操作符
异常机制

####快速初始化成员变量
类的成员变量声明时初始化 （就地声明）
（这个特性不太符合 规则  是否实用有待考证）
*/
class k {
    public:        
        k(){};         //多个构造函数的好处
        k( int a){};
    private:
     int i =0; //j就地初始化
};

/*=============非静态成员的sizeof==================
    sizeof(类的非静态成员)   c98 中会出错



============= friend ==================
friend class poly   完整生命
friend poly            只有类名
friend P                只有 别名  tpyedef 
优点
模板类的友元  
 template <class T>
   class k{
    friend T    //友元
   }   
============= final /override 控制 ==================
   禁止虚函数重载 
    父类   virtual void fun() = 0;
        子类  void fun() final; 关键字      
         如果不想成员函数被重载 可以直接定义为非虚函数
            fiinal  的用途 在继承关系的中途 终止   
 
   override   重载修饰符  
            void fun()  override  告诉编译器子类的 该函数 要重载父类的虚函数
            而不是重新声明  （要编译器检查）
           这两个关键字 可以声明为 变量标识符 
            变量名应尽量 避免使用这两个关键字

============= 模板函数的默认 模板参数 ==================
 默认的模板参数 
 template <class T = int>   默认类型 int
 */
template<int i = 0, class T>
void  fun1( T a)   // 该函数实际有两个参数  int i =0  和 T a 
{  
  cout<<i;   
}
 // 调用 fun1('s');  输出0;
//输出 0 ;
/*==============外部模板============================
template <class T> void fun(T) { } 
template void fun<int>(int)   显示实例化   （声明）
extern template void fun<int>(int) 外部模板的声明（使用其他文件）


================局部和匿名类型作模板实参=============



================继承构造函数=============*/
struct a {
  a(int i){ cout<< "construct"; }
};
struct  b :public  a {
    using a::a; 
    int d { 10 };
};
// 调用 b  c(2);  //自动匹配 a 的构造 输出 construct
//1多个父类继承时的冲突 （可以显示定义一个构造函数）
//2 子类没有自己的已经继承的构造函数如a()（可以就地初始化）

/*===============委派构造函数============
 class info {    #1
     public: 
           info() :type(1),name('a'){ initrest();} 
           info(int i) :type(i),name('a'){ initrest();} 
           info(char e) :type(1),name(e){ initrest();} 
     private:
          void initrest();
          int type;
           char name;
 };
 class info {      #2
     public: 
           info(){ initrest();}   //基准构造函数
           info(int i) :info(){type = i  ;}    
           info(char e) :info(){ name  =e;} 
     private:// 委派给info() 构造函数  不能同时委派和使用初始化列表
          void initrest();
          int type;
           char name;
 };
  class info {      #3
     public: 
           info() :info(1,'a'){ }    
           info(int i) :info(  i,'a' ){ }    
           info(char e) :info(1,e){ } 
     private: 
          info(int i ,char e):type(i),name(e){ }    
          void initrest();
          int type;
           char name;
 };
 委派构造的一个很实际的应用就是使用构造模板函数产生目标构造函数


*/
/*
==================右值引用==================
     扯淡的右值引用  其核心思想   就是把
       函数内 栈变量 申请的堆内存地址传出来   
       其在  移动构造的时候 把 a 的值 取出 构建右值
       然后 把  a  的值  置空  堆内存就被保留了下来
       右值构建的对象在销毁时调用析构 从而避免了内存泄露
       弄明白这些 需要透彻了解  拷贝构造 和移动构造的触发机制
       有这功夫为毛不用指针  

=====================完美转发*/
void fun(int  &&a ) { cout << a<<endl;}
template  <class T>    
void fun2(T && a){     fun(forward<T>(a));   }  
 /* 折叠点   如  a 的类型为 &  则 && & = & 
                   如  a 的类型为 && 则 && &&  = && 
在带入时 同样进行转换
调用：
int  x1 =1;
int  &x2 =x1;
int  && x3 =move(x1);
fun2 (x3)    //注意 这样的方式调用 x3 仍然是左值  
fun2(  move(x3) )  ;   //这样是正确的
 （思考  利用move 触发 移动构造 ）（右值引用成为了一种新的类型）

=================== 显示转换操作符=============== 
struct a1 {     //默认的参数
  a1(int a) {  cout<<"S";};
   explicit  a1(int a1=1,int a2=2):x1(a1),x2(a2) {cout<<x1<<"/"<<x2; }  //隐式转换
    int x1;  
    int x2;  
};/*
调用：    //没有关键字 的时候  会报错 （不知道调用哪个构造函数）
 a1  k = 5;    


=================== 列表初始化===============*/ 
//自定义类型的初始化
map<int,float> d = {{1,1.0 }, { 2,2.06}, { 2,2.06}, { 2,2.06}, { 2,2.06}};
//新的初始化初始化方式
int d1 = 3+4;                    
int d2 = {3+4};
int d3(3+4);     //新的
int d4{ 3+4};
int * i1 = new int (1);
double * i2 = new double{1.2f};
//对于自定义类   使用容器的列表初始化 
class  init {                  
       init(initializer_list<int> l){    //initializer 为类型
                 auto i = l.begin();
                  for(  ; i = l.end();++i)
                      data.push_back(*i);} 
   vector<int> data;
};
class  init2 {           // 自定义类的初始化类表
public:
          init2(int a, int b){s1 = a;s2 = b; }
  int s1,s2;
};
//  a12  k = 5;       
  init2 w ={1,2};
  init2 w2(1,2);

/*=============POD类型====plain old date  普通的旧数据
普通  和 标准布局       
template <typenmaeT> struct std::is_trivilal  判断是否普通类型
cout << is_trivial<trivial1>:: value<< endl;     使用该模板类的 value 的值 
template <typename T> struct std::is_pod;    判断是否 是 POD


 ============= 非受限联合体=============
并不是所有数据类型都能够成为联合体的数据成员
任何非引用类型都可以成为联合体的数据成员
c11    取消了对数据成员类型的限制 .
# 但是 会默认删除一些非受限联合体的默认构造
 关于联合体的一些使用 意义不大 省多大点空间

============= 用户自定义字面量=============  */
class v1 {
   public :
     int  a =5;
};
 v1 operator "" _C( const char * a ,size_t) {   //自定义字面量
         cout<<a<<endl;
     }    
/*
 字面量为整数        操作函数参数接受  unisigned long long 或 const char * 
 字面量为浮点数     操作函数参数接受  long double 或 const char * 
 字面量为字符串     操作函数参数接受   const char *，size_t  
  字面量为字符        操作函数参数接受  char   
  operator  "" 与用户后缀之间必须有空格
  后缀应该以下划线开始   否则会警告
 调用
 "xddsgsaf"_C;

 =============内联命名空间=============
c98 不允许在不同的命名空间中对模板进行特化
namespace k  父空间
             inline namespace k1  子空间
支持特化模板
   细分命名空间 
     暂搁置


=============模板别名=============
using uint = unsigned int;
typedef unsigned int UINT;
using sint = int    效果一样

=============一般化的SFINEA 规则=============
（匹配失败不是错误）如果展开导致类型不匹配 编译器并不报错


===========右尖括号> 改进==========
template <int i> class X{}
template <class T> class Y{}
98 
Y<X<1>  >  x1;     成功
Y<X<2>>    x2;     失败 需要空一个括号
c11    不再需要空一个括号

===========auto 类型推导==========
int a;
auto i = a ;

===========typeid  decltype==========
class white{};
int  main (){
   white a; 
   1cout<< typeid(a).name() <<endl;
   2 using ptrdiff_t  = decltype((int*)0) - (int *)0);  使用推导的类型
   3 decltype(i)  a; 

==========追踪返回类型==========
返回类型后置
int  func(char *a ,int b); 
auto func (char *a ,int  b)   -> int;
模板推导
template<typename T1 ,typename T2>
auto Sum(T1 &t1,T2 &t2)  ->  decltype(t1+t2){
 return t1+t2;
}
==========基于范围的for循环==========
 int arr[5] = {1,2,3,4,5}; 
 for (int & e: arr)  //1第一部分是范围内用于迭代的变量 2 迭代范围
           e  *=2; 
条件   for 循环迭代范围可确定 
==========强枚举类型==========
暂搁置

==========堆内存管理   ==========
智能指针：
unique_ptr<int> up1(new int(11));     //唯一  
unique_ptr<int> up2 =  move(up1);  //转移
shared_ptr<int> sp1(new int (22));   //共享指针
shared_ptr<int> sp2 = sp1;
 //weak_ptr  他指向 shared_ptr 的 对象地址  
weak_ptr<int> wp = sp1; //  wp  指向了 sp1 的堆内存
shared_ptr<int> sp = wp.lock();  // wp.lock() 返回 shared_ptr 的一个对象
cout<<*sp<<endl;                    // 输出 sp 值 也就是 sp1 的值 22
 up1.reset() ;//释放

 智能指针
 pint fun()
 {
   pint  p (new int(225));
   // return p;
   int * a = new int (225); 
    pint  p (a);
   // return p
 }
int main() { 
pint a =  fun();
cout << *a;
指针在复制传递过程中存在两个指向同一区域的现象 有可能释放两次的问题
auto_ptr 和 unique_ptr 提触类一种建立所有权的概念
shared_ptr 采用引用计数 
******* 垃圾回收分类********
 (当指针没有被引用时则会被回收)
 安全操作   
  int *p = new int ;
 declare_reachable(p);  
 //当不安全操作时告诉垃圾回收器 不要在 此代码期间回收该地址
 int *q = (int * )((long long )p ^2012);
 q = undeclare_reachable<int>((int*)((long long)q ^ 2012)  );//取消
 *q = 10;
 cout<<*q;

===============常量表达式==================
constexpt    

 ===============变长模板==================


===============原子类型与原子操作==========

 
原子类型  
c++  包含了原子类型  原子类型提供了原子操作
以 atomic_  为前缀  在涉及多线程的时候提供互斥保障
更有 原子类模板  std::atomic<T> t; 并行编程
原子类型只能从其模板参数类型中进行构造

封装了 pthread   成为 thread 类
  

 atomic_llong total{0};
 //atomic_llong total2{move(total)}; //不允许的构造方式
atomic<float> af {1.2f};
float f = af;
float f1 {af}; //允许 从原子类型到普通类型的构造

void func(int) {
     for ( long long i = 0; i <10000000;++i)
         total +=i;
 thread t1(func,0);
 thread t2(func,0);
t1.join();
t2.join();
cout<<total <<endl;
 
============顺序一致性===memory_order==========
atomic<int> a{0} ;
a.store(t,memory_order_relaxed);

=============线程的局部存储=========
int thread_local  errcode 全局声明时加 thread_local  属于线程的局部变量 
其值将在线程开始时被初始化 而在线程结束时销毁



=============快速退出=========
 

============指针空值==0  NULL nullptr
新的空值

=============默认函数的控制=========
自定义构造函数将 不再是POD 的 
新机制控制默认版本函数的生成
 class d {
       d()     = default    由编译器提供
       d(int a) {      }  //一旦声明带参则必须 实现不带参版本 
       d(int &a )   = delete   禁止使用拷贝构造 一旦标记删除 重载该函数也是非法的
 }   
 类的成员函数 可以标记 default   调用时可指定 调用该 default

============  lambda 函数=========
（匿名函数）*/
auto funq = [] (int x,int y) -> int{ return x+y;}; 
 // [] (int x,int y) ->int { return x+y;}; (编译不通过  缺少ID before "[ " )
 // []
/*
形式[capture](parameters) mutable->return-type{ statement} ;
1 捕捉列表[  
   var   传递值捕捉变量
    =   所有父作用域的变量 （ 当前代码块）
    [&var] 引用捕捉变量
    [&]      引用捕捉所有
    [this]   当前this
  ##捕捉列表不允许变量重复传递
]
 
2参数列表  可省略
3修饰符      默认情况下 lambda函数总是一个const 函数 mutable 可取消其常量性
4 返回值
5 函数体
*/ 
// lambda 
/*
 void t() {   
int  a=0;
int  b=1; 
 auto fune =  [&]()->int {    cout<<a; return 4; } ;  //内部函数
 fune();         
 a = 15;
 fune();
 }  
//仿函数
//================仿函数============ 
class h{
  public:
         h( int  rate):d(rate){};    // 构造
        int operator ()(int p ){ cout<<"()";  return p+1;} //重载操作符 （）
int d;
};
int main() {
    int  l= 10;
    h  h1(l);
      h1(4);
} 

*/
/* 意义  等同于内部函数 代码复用 避免了构造太多对外无关的函数
    （直观 方便 可读性好）
   对于函数中会有大量的局部变量   并需求一些 “局部” 功能的时候 （代码服用）
   这些代码多次重用  不再需要关心传参问题 以及开销  
   ## 当在一个函数中需求一个小函数 以复用代码的时候


//================对齐支持==========

=================通用属性============

==================unicode 支持=========


//================原生字符串字面量==========
//cout<<  R"(  hello \n woer\0 \r  )";
 
//后置返回值
/*
auto funs(int a) ->int   {
    
    int  c = 110;
    return c;
}
 
 int main () {
 
cout<<  R"(  hello \n woer\0 \r  )";

b  c(2);  
fun1('s');
static_assert(1==1,"dddd");
//assert_static(0);
cout<<__func__;
cout<<__STDC__; 
}
 */
