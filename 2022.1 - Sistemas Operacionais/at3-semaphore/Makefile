make: main

main: bad

bad: increment-not-good.c
	gcc -o main2 increment-not-good.c
	
main: increment.c
	gcc -o main increment.c

clean:
	rm -rf *.o *~ main main2