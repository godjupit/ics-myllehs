#include"csapp.h"
#define MAXNUM 128
char *cmd_argv[MAXNUM];


// 内置命令返回0 外置命令返回0
int parseline(char *cmdline){
    char *tmp = strtok(cmdline," ");
    int i = 0;
    while(tmp){
        cmd_argv[i++] = tmp;
        if(strcmp(cmd_argv[0], "ls") == 0){
            cmd_argv[i++] = "--color=auto";
        }
        tmp = strtok(NULL, " ");
    }
    if(strcmp(cmd_argv[0],"cd") == 0){
        return 1;
    }
    if(strcmp(cmd_argv[0], "quit") == 0){
        return 1;
    }
    return 0;
   
}

int main(){

    char cmdline[MAXNUM];
    while(1){

        memset(cmdline, '\0', MAXNUM);
        memset(cmd_argv, 0, sizeof(cmd_argv));
        printf("> ");
        fgets(cmdline, MAXNUM, stdin);
        cmdline[strlen(cmdline) - 1] = '\0';
        int pd = parseline(cmdline);
        pid_t pid;

        if(pd == 0) {
            pid = fork();
            if (pid == 0) {  // 子进程
                if(execvp(cmd_argv[0], cmd_argv) == -1){
                    printf("command not found\n");
                }
                exit(-1);
            }
            int status;
            if(waitpid(pid,&status,0) < 0){
                exit(0);
            }
        }else{
            if(strcmp(cmd_argv[0], "cd") == 0 && cmd_argv[1] != NULL){
                if(chdir(cmd_argv[1]) == 0){
                    printf("dir changes to %s\n",cmd_argv[1]);
                }else{
                    perror("chdir failed!\n");
                }
            }

            if(strcmp(cmd_argv[0],"quit") == 0){
                exit(0);
            }
        }

    }
    exit(0);
}