
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define count 10
#define one_sec_ 1000000
char child_stack[STACK_SIZE+1];

//The function fork and clone processes are using
void print(const char *text){

   for(int i=0; i<count; i++){
      printf("Hello from %s\n", text);
      usleep(one_sec_); //stop time
   }
}

int child(void *params){ //to different between the child and the parent thread
   print("Child thread");
}

int main() {

    int ans1 = clone(child, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    printf("clone results1 = %d\n", ans1);
    int ans2 = clone(child, child_stack + STACK_SIZE, CLONE_PARENT, 0);
    printf("clone results2 = %d\n", ans2);
    print("parent");

    return 0;
}
