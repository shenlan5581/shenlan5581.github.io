#include <string>
#include <iostream>
#include <regex>
using namespace std;
/*        <<c++ 正则表达式 >>
  总结：  regex_match    整体符合规则
          regex_search   局部符合规则         
          iterator       多个结果
子串和多个结果
1子串  指 符合该规则字符串中的局部字符串
          op        er        a        te  ui do something
        "(op)[a-z]*(er)[a-z]*(a)[a-z]*(te)"
         其中 op er a te 都是其子串
2多个结果 指的是一个字符串中有多个 符合该规则 的 字符串
          operate ui do something
          ".o"
          其中 do so 符合该规则 则是为 多个结果
*/
int main () {
string ss = "/service_finder?operate = register&service_name = web";
string s ="operate ui do something"; 

//************************************************test 1  regex_match 只能完整匹配
regex reg1("^operat. ui do .+") ;//正则
smatch r1;
cout<<regex_match(s,r1,reg1)<<endl; // true
cout<<"1:  "<<r1.str()<<endl;
 
//************************************************test 2  regex_search 部分匹配
regex reg2("er") ;//正则
smatch r2;
cout<<regex_search(s,r2,reg2)<<endl; // true
cout<<"2:  "<<r2.str()<<endl;

//************************************************test 3   返回多个结果
 regex reg3("o") ;//正则
 sregex_iterator it1(s.begin(), s.end(), reg3);
 sregex_iterator end1;
    for(; it1 != end1; ++it1) {
        cout <<"3:  "<< it1->str() << endl;
        //cout << *it << endl; 错误
    }

/****************(最有用的吧)**********************test 4 多个子串(最有用的吧)
//("(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3})");
//"0:11:222:333 4:55:66:7";
regex reg4("(op)[a-z]*(er)[a-z]*(a)[a-z]*(te)") ; 
/*（规则） 括号中间的是子串 几个括号表示几个数组下标（可获取的结果）
    
       (op)[a-z]*(er)[a-z]*(a)[a-z]*(te)
        op   as   er   i    a   a    te

分析    op er a tedef something op as er i a a te
   [a-z]* 匹配0-任意此
   [a-z]+ 最少一次
*/
regex reg4("(op)[a-z]*(er)[a-z]*(a)[a-z]*(te)") ; 
string s1 ="operatedef something opaseriaate"; 
sregex_iterator it2(s1.begin(), s1.end(), reg4);
sregex_iterator end2;
    for(; it2 != end2; ++it2) {
      cout <<"4.1:  "<< it2->str() << endl;   
      cout <<"4.2:  "<< it2->str(1) << endl;   
    } 

 /*************************************************test 5 子表达式(match方式)
 match 必须完整的匹配该表达式就是说 字符串有的 表达式也必须有
 所以不存在多个匹配结果 (只能匹配唯一的字符串)
 */
    string s3 ="operate"; 
    regex reg5("(op)[a-z]*(er)[a-z]*(a)[a-z]*(te)") ;                         
    smatch m; 
    regex_match(s3, m, reg5);
    cout <<"5: "<< m.str() << endl;    //0:11:222:333
    cout <<"5: "<< m.str(1) << endl;   //0
    cout <<"5: "<< m.str(2) << endl;   //11
    cout <<"5: "<< m.str(3) << endl;   //222
    cout <<"5: "<< m.str(4) << endl;   //333 
}
/* 输出结果
1
1:  operate ui do something
1
2:  er
3:  o
3:  o
3:  o
4.1:  operate
4.2:  op
4.1:  opaseriaate
4.2:  op
5: operate
5: op
5: er
5: a
5: te
*/
/*                              正则
======================================================================
{} 大括号描述匹配次数
   {0,}  0-任意次
   {0,1} 0或1此
   {n}   确定的次数
   {n,m} n<=m 次
[] 中括号描述匹配内容
   [xyz]  匹配其中任意一个字符
   [a-z]  匹配a-z
   [0-9]  匹配0-9
() 小括号是子串
|  逻辑或
 
正则表达式由
1 普通字符(大小写字母，数字）
2 元字符
.   通陪符 除了/n
\   转义符号
^ 匹配行首
$ 匹配行尾
* 匹配前面的子表达式任意次 *等价于o{0,}
+ 匹配前面的子表达式一次或多次(大于等于1次）。例如，“zo+”能匹配“zo”以及“zoo”，但不能匹配“z”。+等价于{1,}。
? 匹配前面的子表达式零次或一次。例如，“do(es)?”可以匹配“do”或“does”中的“do”。?等价于{0,1}。
描述匹配次数
{n}  n是一个非负整数。匹配确定的n次。例如，“o{2}”不能匹配“Bob”中的“o”，但是能匹配“food”中的两个o。
{n,} n是一个非负整数。至少匹配n次。例如，“o{2,}”不能匹配“Bob”中的“o”，但能匹配“foooood”中的所有o。“o{1,}”等价于“o+”。“o{0,}”则等价于“o*”。
{n,m}m和n均为非负整数，其中n<=m。最少匹配n次且最多匹配m次。例如，“o{1,3}”将匹配“fooooood”中的前三个o为一组，后三个o为一组。“o{0,1}”等价于“o?”。请注意在逗号和两个数之间不能有空格。
? 当该字符紧跟在任何一个其他限制符（*,+,?，{n}，{n,}，{n,m}）后面时，匹配模式是非贪婪的。非贪婪模式尽可能少的匹配所搜索的字符串，而默认的贪婪模式则尽可能多的匹配所搜索的字符串。例如，对于字符串“oooo”，“o+”将尽可能多的匹配“o”，得到结果[“oooo”]，而“o+?”将尽可能少的匹配“o”，得到结果 ['o', 'o', 'o', 'o']
 

//注意:regex_match是目标字符串和正则表达式要完全匹配时才返回true. 
//注意:regex_search 可以返回部分匹配. 

/*                           c++ 操作示例
匹配结果 
regex_match
regex_search
1 match_results<string::const_iterator> result;  //完全匹配
2 smatch result;                                 //部分匹配
3sregex_iterator it(s2.begin(), s2.end(), reg1); //多个匹配
//=====================================================================基本
string s = "/service_finder?operate = register&service_name = web";
string s1 = "operate";
regex reg("operate") ;//正则
smatch r1;
cout<<regex_match(s1,r1,reg)<<endl; // true
cout<<r1.str()<<endl;

// string   字符串
// regex    表达式
// smatch   结果
// regex_match(1,3,2);
// .str()   获取结果

//=====================================================================1个结果
 regex reg1("\\w+day");
 string s1 = "saturday";
 string s2 = "saturday and sunday";
 smatch rr1;
 smatch rr2;
 cout << boolalpha << regex_search(s1, rr1, reg1) << endl;　　//true
 cout << "s1匹配结果：" << rr1.str() << endl; 　　　　　　　　　　//saturday
 cout << boolalpha << regex_search(s2, rr2, reg1) << endl;　　//true
 cout << "s1匹配结果：" << rr2.str() << endl;　　　　　　　　　　 //saturday
 cout << endl;
//=====================================================================返回多个结果
    cout << "iterator结果：" << endl;
    sregex_iterator it(s2.begin(), s2.end(), reg1);
    sregex_iterator end;
    for(; it != end; ++it)
    {
        cout << it->str() << endl;
        //cout << *it << endl; 错误
    }
    cout << "token_iterator结果：" << endl;
    sregex_token_iterator tit(s2.begin(), s2.end(), reg1);
    sregex_token_iterator tend;
    for(; tit != tend; ++tit)
    {
        cout << tit->str() << endl;
        cout << *tit << endl;
    }

// ====================================================================子表达式匹配
    regex reg2("(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3})");
    string ip = "0:11:222:333";
    smatch m; 
    regex_match(ip, m, reg2);
    cout << "输出：str()" << endl;
    cout << m.str() << endl;　　 //0:11:222:333
    cout << m.str(1) << endl;　　//0
    cout << m.str(2) << endl;　　//11
    cout << m.str(3) << endl;　　//222
    cout << m.str(4) << endl;　　//333

    cout << "输出：[i]" << endl; //结果同上
    cout << m[0] << endl;
    cout << m[1] << endl;
    cout << m[2] << endl;
    cout << m[3] << endl;
    cout << m[4] << endl;
//======================================================================多个匹配结果
    string ip2 = "0:11:222:333 4:55:66:7";
    sregex_iterator ip_it(ip2.begin(), ip2.end(), reg2);
    sregex_iterator ip_end;
    for(; ip_it != ip_end; ++ip_it)
    {
        cout << ip_it->str() << endl;
        cout << ip_it->str(1) << endl;
        cout << ip_it->str(2) << endl;
        cout << ip_it->str(3) << endl;
        cout << ip_it->str(4) << endl;
    }*/

