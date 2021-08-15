#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define count 100

//The function fork and clone processes are using
void print(const char *text){

   for(int i=0; i<count; i++){
      printf("Hello from %s\n", text);
      usleep(100000); //stop time
   }
}

int main(){
    pid_t pid;
    pid = fork();//Create child 

    if(pid < 0){//Error - something went wrong
        fprintf(stderr, "Fork faild");
        return 1;
    }

    else if (pid == 0){// pid was create

        pid_t pid = fork();//Create grand child 

        if(pid == 0) {//Success in making grand child process 
            print("Grand child");

            char * args[2] = {"./Subtask2.1",NULL};//File name and arguments		
            execvp(args[0],args);
	//The exec type system calls allow a process to run any program files

        } 
        else print("Child");//Done with grand child, now we in child process
    }
    else print("parent");//Done with child, now we in parent process

    
    return 0;
}








