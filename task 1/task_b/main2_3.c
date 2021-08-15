#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <syslog.h>

#define three_sec_ 3000000

int main()
{

    pid_t pid = fork();//this fork creats a child - Daemon
     if(pid < 0){//Error - something went wrong
        fprintf(stderr, "Fork failed");
        return 1;
    }
    if (pid == 0)
    { 
        //Move the root dir -to not block the file system.
        chdir("/");

        //Move the child to another session.
        setsid();

        printf("Daemon is running\n");

        close(stdout);
        close(stdin);
        close(stderr);
        openlog("Daemon\n", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "Daemon started\n");
        usleep(three_sec_);
        syslog(LOG_NOTICE, "Daemon working...\n");
        usleep(three_sec_);
        syslog(LOG_NOTICE, "Daemon finished\n");
    }
    else
        printf("Daemon PID %d\n", pid);

    return 0;
}
