
obj = main.o transmission.o interaction.o  socket.o fun.o   -lpthread 

sourcefile = main.cpp transmission.cpp interaction.cpp socket.cpp fun.cpp main.h transmission.h interaction.h socket.h fun.h makefile

run  :main
	./main

main :$(obj)
	g++ -o main $(obj)

main.o : main.cpp
	g++ -c -o main.o main.cpp
interaction.o : interaction.cpp
	g++ -c -o interaction.o interaction.cpp
transmission.o : transmission.cpp
	g++ -c -o transmission.o transmission.cpp
socket.o:socket.cpp
	g++ -c -o socket.o socket.cpp
fun.o : fun.cpp
	g++ -c -o fun.o fun.cpp
.PHONY:clean 
clean :
	rm $(obj) 


#debug
debug :file_debug
	gdb    file_debug

file_debug: main.cpp  transmission.cpp interaction.cpp socket.cpp  fun.cpp  
	g++ -g  -o  file_debug main.cpp  transmission.cpp interaction.cpp socket.cpp  fun.cpp -lpthread


# sourcesfile save  to directoy backup 
backup:
	mkdir backup 
save  : backup 
	cp $(sourcefile) ./backup 


