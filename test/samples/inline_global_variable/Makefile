all: exe64 exe32

exe64:
	g++ main.cpp -c -o main64.o
	g++ main64.o -o exe64

exe32:
	g++ -m32 main.cpp -c -o main32.o
	g++ -m32 main32.o -o exe32

clean:
	rm -f *.o

fclean: clean
	rm -f exe*

re: fclean all
