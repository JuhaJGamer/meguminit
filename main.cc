#include <cstdlib>
#include <sched.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char** argv) {
    execl("/bin/cat","/etc/meg.txt");
    sleep(5);
    printf("%d\n",unshare(CLONE_NEWPID));
    int pid = fork();
    printf("%d\n",getpid());
    if(getpid() == 1) {
        char** argv2 = (char**)malloc(sizeof(char)*argc);
        argv2[0] = (char*)malloc(sizeof(char)*5);
        argv2[0] = "init\00";
        for(int i = 1; i < argc; i++) {
            argv2[i-1] = argv[i];
            printf("%s\n",argv[i]);
        }
        argv[argc] = NULL;
        execv("/bin/init",argv2);
    }
    else {
        waitpid(-1,NULL,0);
    }
    return 0;
}
