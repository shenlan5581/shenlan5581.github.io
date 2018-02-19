
#学习文档
vpath %.h ./include

all:main.cpp 
	 g++  -o main main.cpp -I./include  -L./lib  -ldo  -L./lib -ltest  -Wl,-rpath,./lib  
                                     # -------------  --------------------------------
	 								 #		^			          ^          ^
#使用	     				            	 静态库				 动态库     运行路径
#  静态库使用 方式1  直接写路径   ./lib/do 
#  静态库使用 方式2  -L(太扯淡） 必须库文件名为 lib<名称>.a 形式否则找不到
#  动态库 需要指定 -rpath 运行时目录  Wl 选项(把 选项 option 传递给 连接器.  如果 option 中 含有 逗号, 就在 逗号 处 分割成 多个 选项)
#  -rpath,./lib @@中间不要空格

#<----- -I 路径   选项（源文件中 头文件和源文件不在一个文件夹 头文件查找路径 
#<----- -L 路径   <库名> 使用自定义库   -ltestlib   不在一个路径时 -L 并且加上 -l  在一个路径直接编译 

#  -L，-l指定库时，gcc会在对应的路径搜索有lib前缀的库，所以生成的库必须是libxx.a这样的格式
#  v  静态库制作(注意命名格式）
#-----------------------------------------------------------
libdo.a:do.o
	 ar rv  libdo do.o
do.o:do.cpp
	 g++ -I ./include/ -c -o do.o do.cpp    #.o文件
#-----------------------------------------------------------
#  v  动态库制作（注意命名格式）
libtest.so:test.o
	g++ -shared  -fPIC -o test.so test.o

test.o:test.cpp
	g++ -I ./include/ -fPIC -c -o test.o test.cpp	 #.o文件
 #---------------------------------------------------------------

 clean:do.o
	rm -f *.o   #(*通配符）所有以.o结尾的文件

# @ 符号 表示 不显示命令在终端
debug:main.cpp test.cpp do.cpp
	g++ -g -o $@ $^ -I./include
  
kt:do.o
	echo "mkdo.o"  
.cpp.o:
	g++ -I ./include/ -c -o $@ $<
# 等价于     %.o : %.cpp
                     	 
#.cpp.o:
#这句话的意思就是 %.o : %.c	   (所有依赖 .o 的操作）
	 
  
  
#  $@   --代表目标文件(target)                          即debug 
#  $^   --代表所有的依赖文件(components)                 即maian.cpp test.cpp do.cpp
#  $<   --代表第一个依赖文件(components中最左边的那个)     即main.cpp
#   = 是最基本的赋值
#  := 是覆盖之前的值
#  ?= 是如果没有被赋值过就赋予等号后面的值
#  += 是添加等号后面的值















#变量
#x := foo
#y := $(x) bar
# := later
#其等价于:
#y := foo bar
#x := later
#值得一提的是,这种方法,前面的变量不能使用后面的变量,只能使用前面已定义好了的变
#量。如果是这样:
#y := $(x) bar
#x := foo
#那么,y 的值是“bar”,而不是“foo bar”


#foo := a.o b.o c.o
#bar := $(foo:.o=.c)
#这个示例中,我们先定义了一个“$(foo)”变量,而第二行的意思是把“$(foo)”中所
#有以“.o”字串“结尾”全部替换成“.c”,所以我们的“$(bar)”的值就是“a.c b.c
#c.c”。

#foo := a.o b.o c.o
#bar := $(foo:%.o=%.c)
#这依赖于被替换字串中的有相同的模式,模式中必须包含一个“%”字符,这个例子同
#样让$(bar)变量的值为“a.c b.c c.c”。

#x = y
#y = z
#a := $($(x))
#在这个例子中,$(x)的值是“y”,所以$($(x))就是$(y),于是$(a)的值就是“z”。
#(注意,
#是“x=y”,而不是“x=$(y)”)

#objects = main.o foo.o bar.o utils.o
#objects += another.o
#于是,我们的$(objects)值变成:“main.o foo.o bar.o utils.o another.o”(another.o
#被追加进去了)
#使用“+=”操作符,可以模拟为下面的这种例子:
#objects = main.o foo.o bar.o utils.o
#objects := $(objects) another.o
#所不同的是,用“+=”更为简洁。

#variable := value
#variable += more
#等价于:
#variable := value
#variable := $(variable) more

#foo: $(objects)
#ifeq ($(CC),gcc)
#$(CC) -o foo $(objects) $(libs_for_gcc)
#else
#$(CC) -o foo $(objects) $(normal_libs)
#endif
#可见,在上面示例的这个规则中,目标“foo”可以根据变量“$(CC)”值来选取不同的
#函数库来编译程序。
#我们可以从上面的示例中看到三个关键字:ifeq、else 和 endif。ifeq 的意思表示条
#件语句的开始,并指定一个条件表达式,表达式包含两个参数,以逗号分隔,表达式以圆括
#号括起。else 表示条件表达式为假的情况。endif 表示一个条件语句的结束,任何一个条件
#表达式都应该以 endif 结束。
#当我们的变量$(CC)值是“gcc”时,目标 foo 的规则是:
#foo: $(objects)
#$(CC) -o foo $(objects) $(libs_for_gcc)
#www.linuxidc.com
#而当我们的变量$(CC)值不是“gcc”时(比如“cc”),目标 foo 的规则是:
#foo: $(objects)
#$(CC) -o foo $(objects) $(normal_libs)

#一、函数的调用语法
#函数调用,很像变量的使用,也是以“$”来标识的,其语法如下:
#$(<function> <arguments>)
#或是
#${<function> <arguments>}
#这里,<function>就是函数名,make 支持的函数不多。<arguments>是函数的参数,参数间
#以逗号“,”分隔,而函数名和参数之间以“空格”分隔。函数调用以“$”开头,以圆括号
#或花括号把函数名和参数括起。感觉很像一个变量,是不是?函数中的参数可以使用变量,
#为了风格的统一,函数和变量的括号最好一样,如使用“$(subst a,b,$(x))”这样的形式,
#而不是“$(subst a,b,${x})”的形式。因为统一会更清楚,也会减少一些不必要的麻烦。
#还是来看一个示例:
#comma:= ,
#empty:=
#space:= $(empty) $(empty)
#foo:= a b c
#bar:= $(subst $(space),$(comma),$(foo))
#在这个示例中,$(comma)的值是一个逗号。$(space)使用了$(empty)定义了一个空格,$(foo)
#的值是“a b c”,$(bar)的定义用,调用了函数“subst”,这是一个替换函数,这个函数
#有三个参数,第一个参数是被替换字串,第二个参数是替换字串,第三个参数是替换操作作
#用的字串。这个函数也就是把$(foo)中的空格替换成逗号,所以$(bar)的值是“a,b,c”。
