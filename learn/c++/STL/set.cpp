

#include <iostream>
#include <string>
#include <set>
using namespace std;



int main() {
set<int> s;
s.insert(1);
set<int>::iterator p;
p = s.find(0);
if(p == s.end())
 cout <<"no"<<endl;
else 
 cout <<"yes"<<endl;

}
