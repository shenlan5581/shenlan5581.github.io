


.c.o:
	gcc -c -g -o $@ $<

src :=main.c
src +=ser.c
src +=tree.c

obj = $(src:.cpp=.o)

run:all
	./main
all:$(obj)
	gcc -g -o main $(obj)
clean:$(obj)
	rm -f *.o
	rm -f main


