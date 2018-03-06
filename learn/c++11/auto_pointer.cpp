

#include <memory>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
typedef map<string,string> m;
typedef vector<m>      n;
typedef unique_ptr<n> str;

//str a = new m ; 语法错误

str fun() 
{
str i(new n);
return i;    //必须有返回值 否则段错误
}


int main() {
str a (new n);
str b;
if(a)                      //不为空
cout<<"empty1"<<endl;      //输出
if(b)
cout<<"empty2"<<endl;      //未输出  为空

m i;
i["name"] = "xingke";
a->push_back(i);

n x = *a;                  //取值
m::iterator p;
p = x[0].find("name");
cout  << p->second;

//set empty
a.reset();                 //######free
if(a)                      // 可以做判断
cout<<"empty3"<<endl;      //未输出 a 为空

 fun();
}
