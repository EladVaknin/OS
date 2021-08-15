
CC = gcc
AR = ar -rcs
OBJECTS_MAIN = main.o
OBJECTS_LIB = hello_ariel.o
FLAGS = -Wall -g -fPIC

all:subtask_1 subtask_2 subtask_3 subtask_4

# main 2_1
main2_1.o: 
	$(CC) $(FLAGS) -c main2_1.c

# main 2_2
main2_2.o:
	$(CC) $(FLAGS) -c main2_2.c

# main 2_3
main2_3.o:
	$(CC) $(FLAGS) -c main2_3.c

# main 2_3
main2_4.o:
	$(CC) $(FLAGS) -c main2_4.c

# subtask 1
subtask_1:main2_1.o
	$(CC) $(FLAGS) -o main2_1 main2_1.o

# subtask 2
subtask_2:main2_2.o
	$(CC) $(FLAGS) -o main2_2 main2_2.o
	
# subtask 3
subtask_3:main2_3.o
	$(CC) $(FLAGS) -o main2_3 main2_3.o

# subtask 4
subtask_4:main2_4.o
	$(CC) $(FLAGS) -o main2_4 main2_4.o
	
.PHONY: clean all hello_ariel_d hello_ariel_s

# clean
clean:
	rm -f *.o *.a *.so main main2_1 main2_2 main2_3 main2_4
