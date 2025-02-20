#include"csapp.h"

int main(int argc, char *argv[], char *envp[]){
    printf("Command-line arguments:\n");
    printf("    argc[ :0]: %s\n",argv[0]);
    printf("    argv[ :1]: %s\n",argv[1]);
    printf("    argv[ :2]: %s\n",argv[2]);
    printf("Environment variables: \n");
    int i = 0;
    while(envp[i] != NULL){
        printf("    envp[ %d]: %s\n",i++,envp[i]);
    }
    exit(0);
}