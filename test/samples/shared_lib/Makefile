all: libtest64.so libtest32.so exe64 exe32

exe64: libtest64.so
	gcc main.c -o main64.o -c
	gcc main64.o -o exe64 -L . -l test64

exe32: libtest32.so
	gcc main.c -o main32.o -c -m32
	gcc main32.o -o exe32 -m32 -L . -l test32

libtest64.so:
	gcc foo.c -o foo64.o -c -fPIC
	gcc bar.c -o bar64.o -c -fPIC
	gcc foo64.o bar64.o -o libtest64.so -shared

libtest32.so:
	gcc foo.c -o foo32.o -c -m32 -fPIC
	gcc bar.c -o bar32.o -c -m32 -fPIC
	gcc foo32.o bar32.o -o libtest32.so -m32 -shared

clean:
	rm -f *.o

fclean: clean
	rm -f exe*
	rm -f *.so

re: fclean all
