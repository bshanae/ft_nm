all: exe

exe: exe64 exe32
	lipo -create -output exe exe64 exe32

exe64:
	gcc main.c -o exe64

exe32:
	gcc -m32 main.c -o exe32

clean:
	rm -f *.o

fclean: clean
	rm -f exe*

re: fclean all
