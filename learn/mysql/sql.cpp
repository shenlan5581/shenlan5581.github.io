/*

（如果不存在插入。存在则不插入）
mysql> insert into service_table (service_name,IP,port) 
       select 'web','125','80' from dual where 
       not exists(select * from service_table where   
       service_name = 'web'and IP = '125'and port = '80');
 
dual 相当于一个 虚拟表 
括号中的 select 相当于一个条件表达式  
SELECT 也可以用来检索不参考任何表而计算出的行。

******************函数
mysql 
支持内置函数 
用户定义函数 
和存储函数

















**************变量
session variables 会话变量



用户定义的变量是特定于会话的。由一个客户端定义的用户变量不能被其他客户端看到或使用。当客户端退出时，给定客户端会话的所有变量都会自动释放。
用户名变量不区分大小写

set @var_name = expr  (复制)
（区别）
：=   赋值
=     比较运算
