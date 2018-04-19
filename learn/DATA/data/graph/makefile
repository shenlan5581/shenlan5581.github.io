
src:= main.c
src+=graph.c
src+=queue.c

.c.o:
	gcc -g -c -o $@ $<

obj :=$(src:.c=.o)
all:main
	./main
main:$(obj)
	gcc -g -o main  $(obj)
clean:
	rm main
	rm *.o

	
