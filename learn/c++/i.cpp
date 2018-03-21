
#include <string>
#include <iostream>
using namespace std;
int main()
{
int i=0;
for(i=0;i<3;i++)   //比较 执行 求值 
cout<<i<<" ";
cout<<"\n"<<i<<endl;
i=0;
for(i=0;i<3;++i)
cout<<i<<" ";
cout<<"\n"<<i<<endl;
cout<<"------------------------"<<endl;
i=0;
int a[] ={ 1,2,3};
cout<<a[++i]<<endl;
cout<<a[i++]<<endl;

cout<<"------------------------"<<endl;
int x=0;
for( ;x<3;x++)
   if(x == 2)
   break;
cout<<"x:"<<x<<endl;

int y=0;
for( ;y<3;++y)
   if(y == 2)
   break;
cout<<"x:"<<y<<endl;

cout<<"------------------------"<<endl;
int j=0;
while(++j<5) //求值 比较 执行
cout<<j;
cout<<endl;
int z=0;
while((z+=1)<5) //求值 比较 执行
cout<<z;
cout<<endl;
z=0;
while(z++<5) //比较 求值 执行
cout<<z;
cout<<endl;

}
