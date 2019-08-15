基本表机构
user     id   name  info_id
info      id   addr  tel                 
family   id   member         

[常用SQL]
    设置数据库支持中文 对已经建立的库有效 alter table table_name convert to character set utf8;
    alter table content add title varchar(100) after type;          #添加列
    alter table content add primary key (id);                              #添加主键

    alter table  add <列名> [FIRST | AFTER] <列名>
    alter table  rename <new_table_name>
    alter table  change 
    source <路径> 导入 
                    
                    [ **MySQL 5.6 手册**]
##[用户账户(权限）]
1 通过mysql语句
创建用户  CREATE USER
   ''@'%' (用户名为空，主机为空）表示任何用户从任何主机
   create user 'usename'@'localhost' identified by 'password'; 
授权      GRANT
   GRANT [priv_type]  on  [object-type] priv_level  to  [user]
   grant all  on  service_finder.* to 'k'@'192.168.1.109' 
      权限     库名.*(通配符号)          帐户名         
                 *.*
                 *
mysql> grant update,select on design.* to 'k'@'127.0.0.1';
授权  更新，查询  在 库design的所有表中  给 用k

删除用户帐户  DROP
    DROP USER 'username'@'localhost'

重置密码 SET PASSWORD 
    SET PASSWORD FOR 'username'@'localhost'= PASSWORD('password');
2 通过修改授权表
..............

##[备份恢复]
二进制日志
启动二进制日志 
    service start --log-bin[=base name]
    show binary logs; 显示二进制日志文件

##优化 [索引]
*索引用于快速查找具有特定列值的行索引用于快速查找具有特定列值的行。
#关于实现 有B-tree 和 hash 表

查看
show index from <table name> 

#######注意列名的括号是必须的,括号中可指定 前缀长度及排序规则：wq

(对于字符串 可以创建仅使用列值的前缀部分 并用语法来制定索引前缀长度）
create index of_name on user (name (10));  索引长度为10
(唯一索引 似的该列的所有值必须是不同的)
create unique index of_info on user (name (10));  索引长度为10






##语言结构

##复制(未成功）
1设置复制主配置
    配置my.cnf文件
    添加 log-bin = 'name'
    添加 server-id =1 (任意)
    restart
2设置复制从配置
    server-id =2;
3创建复制用户
    create user 'name'@'localhost' identified by 'password'
    grant replication slave on *.* to 'name'@'localhost';
4获取复制主二进制日志坐标
    show master status 获取当前二进制日志文件名称和位置
*5 如果主服务器上已经有数据并希望使用它来同步从服务器则需要创建数据快照
 (1)  使用mysqldump 创建数据快照 (提示检查版本 语法不正确）
      mysqldump --all-databases --master-data > dbdump.db
      在新的服务器执行
      shell> mysql -h master < fulldb.dump
 (2)  使用原始数据  （仍然失败） 
      shell> mysqladmin shutdown  （关闭主服务器）

6  在从站上设置主站配置

7启动复制
  start slave

一使用新主站和从站设置复制
二使用现有数据设置复制
三将节点添加到现有的复制环境

===============分区==========================
(查询分区内容）
mysql>  SELECT PARTITION_NAME,TABLE_ROWS  （查询分区名，行数）
    ->     FROM INFORMATION_SCHEMA.PARTITIONS  (系统仓库）
    ->     WHERE TABLE_NAME = 'r1'; (r1 是创建时的表名）
============================================
分区类型：
  1范围分区
  2列表分区
  3 hash分区
  4 key 分区

(1)范围分区 
CREATE TABLE  r1 (
    id INT NOT NULL,
    name VARCHAR(30),
    size INT NOT null
)
PARTITION BY RANGE (size) (
    PARTITION r1 VALUES LESS THAN (10),
    PARTITION r2 VALUES LESS THAN  MAXVALUE
);
（根据 size的大小 放入相应分区）
-----------------------------------------------------------
(2) range columns 分区
    列分区 基于元祖之间的比较（列值和表），而不是标量值之间的比较
   create table rcx( 
       a int,
       b int
 )
 partition by range columns(a,b) (
     partition rcx1 values less than (5,10),
     partition rcx2 values less than (10,20)
);
cloumn_list 是一列或多列 


##存储程序(函数）

MySQL支持存储的例程（过程和函数）。
*存储的例程是一组可存储在服务器中的SQL语句。
*完成此操作后，客户端不需要重新发布单个语句，而是可以引用存储的例程。
*存储的例程在某些情况下特别有用：
*当多个客户端应用程序以不同语言编写或在不同平台上工作时，需要执行相同的数据库操作。
*安全至关重要时。例如，银行为所有常见操作使用存储过程和函数。
*这提供了一致且安全的环境，并且例程可以确保每个操作都被正确记录。
*在这样的设置中，应用程序和用户将不能直接访问数据库表，但只能执行特定的存储例程。
  (当数据库被删除时 所有与其关联的存储例程也会被删除)

!!注意 类似于 @name = （sleect * form user) 语句 必须加括号否则报错
!!注意 变量无法直接使用 = 号赋值 必须使用set 或 into 或 select

创建
        delimiter  //   
        create procedure  <例程名称>  (参数名 类型（长度））
            begin
            {复合语句 ;}    
            end
        limiter ;
---------------------------------------------
    delimiter  //   
    create function     < 函数名称> (参数名 类型（长度））
    returns <类型>
        begin
            {复合语句 ;}    
        end
    delimiter ;
删除
drop procedure     <name>
drop function        <name>
查看
show procedure status
show function  status
***例**********************
 create function t(x  char(10))  
       returns int  
       begin   
             declare n int ;                #声明 n 
             set n = (select id from user where name = x );  #引用参数x
       return (n);                     #返回 n
       end//
#(该函 查询 表中名字等于参数的行 并返回 id)
create function t1(n int)  returns char(30) 
    begin   declare c char(30) ; (select name  into c  from user where id = n );
               return (c);  
    end//
-------------------
 create function addd(nm char(30) ,te char(20), a char(20))  
    returns int  
       begin   declare inid int ;
               insert into info  set addr = a ,tel =te ; 
               set inid = (select id from info where addr = a );
               insert into user set name = nm ,info_id = inid;   
               return (inid);   
       end//
#(拿到三个值 分别插入到 两个表中） 
 create procedure addd(nm char(30) ,te char(20), a char(20))  
   begin    
   declare inid int;
    insert into info  set addr = a ,tel =te ;
    set inid = (select id from info where addr = a );
    insert into user set name = nm ,info_id = inid; 
    end//
#(拿到三个值 分别插入到 两个表中） 

##变量
*session variables 会话变量
*用户定义的变量是特定于会话的。由一个客户端定义的用户变量不能被其他客户端看到或使用。
*当客户端退出时，给定客户端会话的所有变量都会自动释放。
*用户名变量不区分大小写

#声明
会话变量   set  @变量名 = 10;
局部变量   declare  变量名  int default 0;
#赋值
set @var_name = expr
：=   赋值
 =     比较运算
#代码块中赋值   形式
 set @x = {select} 
select  name into @x from ...... 

##复合语句

##触发器
create trigger trig before insert on triggners
 FOR EACH ROW 
     begin 
         {复合语句}
     end//

##示例
create trigger trig after insert on info 
for each row begin    
    declare inid int;   
    set inid = (select id from info where addr = "shangjiequ");  
    insert into user set name ='trigger',info_id = inid+1;
    end//


## 视图
create view v as select name from user where id >3 and id<10 //
select * from v; 
只显示该条件的



##备份与恢复
备份  包含用户信息(未知是否能用）
root@ki://home/k# mysqldump -uroot -pxingke  --all-databases >/home/k/dump.sql
   所有的库         转储文件
恢复
mysql  -uroot -pxingke  < dump.sql





************[note]*********************************

（如果不存在插入。存在则不插入）
mysql> insert into service_table (service_name,IP,port) 
       select 'web','125','80' from dual where 
       not exists(select * from service_table where   
       service_name = 'web'and IP = '125'and port = '80');

dual 相当于一个 虚拟表 
括号中的 select 相当于一个条件表达式  
SELECT 也可以用来检索不参考任何表而计算出的行。



6.1 安全
(永远不要给任何人访问数据库中的user表)
show grants for 'usrname'@'localhos'  查看用户权限
revoke      删除哪些不要的权限
shell> tcpdump -l -i eth0 -w - src or dst port 3306 | strings 
（未加密 查看 sql 内容）




