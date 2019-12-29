all: functions_sort.o sorter.o
	gcc functions_sort.o sorter.o -o sort

functions_sort.o:
	gcc -c functions_sort.c -o functions_sort.o

sorter.o:
		gcc -c sorter.c -o sorter.o

clean:
	rm -rf *.o
	rm sort
