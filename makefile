run: all
	./run

all: stat.o
	gcc -o run stat.o 

stat.o: stat.c
	gcc -c stat.c

clean:
	rm -rf *~
	rm -rf *.o
	rm -rf run
