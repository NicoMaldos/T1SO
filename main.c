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
    /*char input_str[100];
    pid_t p1, p2, p3;
    int fd1[2], fd2[2], fd3[3], fd4[2], seguir = 0,input_int;  // Used to store two ends of first pipe 
    /* printf("Estupido Jeremy, escribe algo ahora por favor.");
    scanf("%s", input_str);
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);
    p1 = fork(); 
    if(p1 > 0){
        p2 = fork();
        if(p2 > 0){
            p3 = fork();

        }
    }
    if(p1 == 0){
        read(fd2[0], input_str, 100);
        //wait(NULL);
        while(seguir == 0){
            printf("Turno de hijo 1, quien quieres que juegue?\n");
            scanf("%s", input_str);
            input_int = atoi(input_str);
            if(input_int == 1){
                write(fd1[1], input_str, 100);    
            }
            else if(input_int == 3){
                write(fd3[1], input_str, 100); 
            }
            else if(input_int == 4){
                write(fd4[1], input_str, 100); 
            }
            read(fd2[0], input_str, 100);
            //wait(NULL);
        }
    }
    else if(p2 == 0){
        read(fd3[0], input_str, 100);
        //wait(NULL);
        while(seguir == 0){
            printf("Turno de hijo 2, quien quieres que juegue?\n");
            scanf("%s", input_str);
            input_int = atoi(input_str);
            if(input_int == 1){
                write(fd1[1], input_str, 100);    
            }
            else if(input_int == 2){
                write(fd2[1], input_str, 100); 
            }
            else if(input_int == 4){
                write(fd4[1], input_str, 100); 
            }
            read(fd3[0], input_str, 100);
            //wait(NULL);
        }
    }
    else if(p3 == 0){
        read(fd4[0], input_str, 100);
        //wait(NULL);
        while(seguir == 0){
            printf("Turno de hijo 3, quien quieres que juegue?\n");
            scanf("%s", input_str);
            input_int = atoi(input_str);
            if(input_int == 1){
                write(fd1[1], input_str, 100);    
            }
            else if(input_int == 3){
                write(fd3[1], input_str, 100); 
            }
            else if(input_int == 2){
                write(fd2[1], input_str, 100); 
            }
            read(fd4[0], input_str, 100);
            //wait(NULL);
        }
    
    }
    else if(p3 > 0){
        while(seguir == 0){
            printf("Turno de padre, quien quieres que juegue?\n");
            scanf("%s", input_str);
            input_int = atoi(input_str);
            if(input_int == 2){
                write(fd2[1], input_str, 100);    
            }
            else if(input_int == 3){
                write(fd3[1], input_str, 100); 
            }
            else if(input_int == 4){
                write(fd4[1], input_str, 100); 
            }
            read(fd1[0], input_str, 100);
            //wait(NULL);
        }


    }
    exit(0);*/

    /*if(p1 == 0){
        close(fd1[1]);
        char concat_str[100];
        read(fd1[0], concat_str, 100);
        close(fd1[0]);
        wait(NULL);
        printf("%s, ¡Tara!",concat_str);
        
    }
    else if(p1 > 0){
        close(fd1[0]);
        printf("Si todo funciona, se deberia escribir lo que pusiste.");
        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);
    }*/
    

    return 0;
}