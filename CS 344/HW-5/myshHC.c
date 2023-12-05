#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int process(char *);
int countTokens(char *);
void setArgv(char **, char *);
void freeSpace(char **);
void dump(char **);

int main(int argc, char *argv[]){
    char cmd[256];
    printf("Welcome to our shell!\n");

    do{
        printf("->");
        fgets(cmd, 256, stdin);
        cmd[strlen(cmd) - 1] = '\0';
        if(strcmp("exit", cmd) == 0){
            printf("Goodbye!\n");
        }else{
            int status = process(cmd);
            if(status == -1){
                printf("Error: executing %s\n", cmd);
            }
        }
    }while(strcmp("exit", cmd) != 0);
    return 0;
}
int process(char *cmd){
    char **argv;
    char cmdCopy[256];
    strcpy(cmdCopy, cmd);
    int count = countTokens(cmd);

    if(count == 0){
        return 0;
    }

    strcpy(cmdCopy, cmd);
    argv = (char **)malloc(sizeof(char *) * (count + 1));
    argv[count] = NULL;
    setArgv(argv, cmdCopy);
    dump(argv);

    if(strcmp("ls",argv[0]) == 0){
        int pid = fork();
        if(pid == 0){
            char cpath[256];
            char *path = getenv("PATH");
            strcpy(cpath, path);
            strcat(cpath, argv[0]);
            execv(cpath, argv);
            return -1;
        }
    int status = 0;
    wait(&status);
    }else if(strcmp("cd", argv[0]) == 0){
        int pid = fork();
        if(pid == 0){
            char *cmdPath;
            char line[] = "/";
            cmdPath = (char *)malloc(sizeof(char)* 100);
            getcwd(cmdPath, 100);
            strcat(cmdPath, line);
            strcat(cmdPath, argv[0]);
            execv(cmdPath, argv);
            return -1;
        }
        int status = 0;
        wait(&status);
    }else{
        printf("%s\n is an error", argv[0]);
    }
    freeSpace(argv);
    return 0;
}
int countTokens(char *cmdCpy){
    char *token;
    int count = 0;
    char *s = " ";
    token = strtok(cmdCpy, s);
    while(token != NULL){
        count++;
        token = strtok(NULL, s);
    }
    return count;
}
void setArgv(char **argv, char *cmdCpy){
    char *token;
    int i = 0;
    char *s = " ";
    token = strtok(cmdCpy, s);
    while(token != NULL){
        int strlength = strlen(token);
        argv[i] = (char *)malloc(sizeof(char) * strlen(token) + 1);
        strcpy(argv[i], token);
        token = strtok(NULL, s);
        i++;
    }
}
void freeSpace(char **argv){
    int i = 0;
    while(argv[i] != NULL){
        free(argv[i]);
        i++;
    }
    free(argv);
}
void dump(char **argv){
    int i = 0;
    while(argv[i] != NULL){
        printf("%s\n", argv[i]);
        i++;
    }
}