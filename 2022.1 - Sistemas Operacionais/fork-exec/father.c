#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void main(){
     pid_t pid;
     char *argv[] = { NULL};

     if((pid=fork())!=0){

       printf("\n I am the father of %d \n",pid);  
       waitpid(pid, NULL, 0);
       return;
          
     }else {

       printf("\n I am the son, and right now I am like my father\n"); 
       execv("./son",argv); //sobrescreve o código atual do filho (igual ao pai) com o código do programa "son"

     }




}
