#include"csapp.h"
#define MAXNUM 128
char *cmd_argv[MAXNUM];

void parseline(char *cmdline){
    char *tmp = strtok(cmdline," ");
    int i = 0;
    while(tmp){
        cmd_argv[i++] = tmp;
        printf("%s\n",tmp);
        tmp = strtok(NULL, " ");
    }
}

int main(){

    char cmdline[MAXNUM];
    while(1){

        memset(cmdline, '\0', MAXNUM);

        printf("> ");
        fgets(cmdline, MAXNUM, stdin);
        cmdline[strlen(cmdline) - 1] = '\0';
        parseline(cmdline);

        pid_t pid = fork();
        if (pid == 0) {  // 子进程
            execvp(cmd_argv[0], cmd_argv);
            exit(-1);
        }
        int status;
        if(waitpid(pid,&status,0) < 0){
            exit(0);
        }
    }
    exit(0);
}