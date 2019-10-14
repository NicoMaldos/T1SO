#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/wait.h> 
#include <unistd.h>
#include"file_manage.h"

int main(){

    restart();
    startGame();
    turno1();
    restart();
    printf("**********  ****   ****     **  **  **\n");
    printf("***         ****   *****    **  **  **\n");
    printf("*******     ****   *** ***  **  **  **\n");
    printf("***         ****   ***  *** **  **  **\n");
    printf("***         ****   ***   *****        \n");
    printf("***         ****   ***    ****  **  **\n");

    return 0;
}
