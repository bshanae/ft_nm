all: exe64 exe32

exe64:
	gcc main.c -c -o main64.o
	gcc main64.o -o exe64

exe32:
	gcc -m32 main.c -c -o main32.o
	gcc -m32 main32.o -o exe32

clean:
	rm -f *.o

fclean: clean
	rm -f exe*

re: fclean all
