


main:main.o
	echo "1111"  #（默认执行了 g++ -c -o main main.cpp
	
#  ^^^  上面的语言默认执行	g++ -c -o main main.cpp
#  VVV  下面等于重新定义了默认的 编译操作	
.cpp.o:
	g++  -c     -o    $@ $<
	echo "2222"
	
 
# .cpp.o:  =====等价于====  %.o : %.cpp
                     	 
#  .cpp.o:
#这句话的意思就是 %.o : %.c	   (所有依赖 .o 的操作）
