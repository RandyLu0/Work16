all: input.o processor.o
	gcc -o processor processor.o
	gcc -o input input.o
input.o: input.c
	gcc -c input.c 
processor.o: processor.c
	gcc -c processor.c
clean:
	rm *.o