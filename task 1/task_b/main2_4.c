#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 30
//run all
char child_stack[STACK_SIZE+1]; 


int main2_1(){
    char * args[2] = {"./main2_1",NULL};
    execvp(args[0], args);
    return 0;
}

int main2_2(){
    char * args[2] = {"./main2_2",NULL};
    execvp(args[0], args);
    return 0;
}

int main2_3(){
    char * args[2] = {"./main2_3",NULL};
    execvp(args[0], args);
    return 0;
}


int main() {
    int clone1 = clone(main2_1, child_stack+STACK_SIZE, 0, 0);
    int clone2 = clone(main2_2, child_stack+STACK_SIZE, 0, 0);
    int clone3 = clone(main2_3, child_stack+STACK_SIZE, 0, 0);
    
    printf("clone id = %d\n", clone1);
    printf("clone id = %d\n", clone2);
    printf("clone id = %d\n", clone3);
    printf("parent id %d\n", getpid());
    sleep(10);
    return 0;
}
