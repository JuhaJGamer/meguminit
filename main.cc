#include <cstdlib>
#include <sched.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int pid;
    if((pid = fork()) == 0) {
        execl("/bin/cat", "/bin/cat", "/etc/meg.txt", (char*)NULL);
    }
    sleep(2);
    printf("%d\n",getpid());
    char** argv2 = (char**)malloc(sizeof(char)*argc);
    argv2[0] = (char*)malloc(sizeof(char)*10);
    argv2[0] = "/bin/init";
    for(int i = 1; i < argc; i++) {
        argv2[i-1] = argv[i];
        printf("%s\n",argv[i]);
    }
    argv[argc] = NULL;
    execv("/bin/init",argv2);
    printf("crash\n");
    return 0;
}
