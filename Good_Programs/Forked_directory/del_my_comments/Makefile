SRC = state.c readfile.c

all:
	gcc -DDEBUG $(SRC) -o a.out
	gcc $(SRC) -o demo

run:
	./demo test.c 

clean:
	rm -rf *.o *.exe *.out demo
	
