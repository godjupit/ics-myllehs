#include"csapp.h"
#define MAXNUM 128
char *cmd_argv[MAXNUM];

void parseline(char *cmdline){
    char *tmp = strtok(cmdline," ");
    int i = 0;
    while(tmp){
        cmd_argv[i++] = tmp;
        tmp = strtok(NULL, " ");
    }
}

int main(){

    char cmdline[MAXNUM];
    while(1){
        printf("> ");
        fgets(cmdline, MAXNUM, stdin);
        parseline(cmdline);
    }
}