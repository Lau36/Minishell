#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include "leercadena.h"
#include <sys/types.h>
#include <signal.h>

Array procesos;

int lastElement(char ** arr){ //Calcula el ultimo elemento del array dinamico 
    int i=0;
    while(1){
        if(arr[i]==NULL)
            return i;
        i++;
    }
}

char ** returnArr(char ** arr){ //Esta funcion es para el uso del metodo exepcvp, ya que, el ultimo elemento siempre tiene que ser null 

    char **command = arr;
    command[lastElement(arr)-1]= NULL;

    return command;
}

int main(int argc, char* argv[]) {
  char command[256];
  char **comando;

  while (1) {
      pid_t pid;
      printf("> ");
      leer_de_teclado(256, command);
      comando = de_cadena_a_vector(command);

      if (strcmp(comando[0],"salir") == 0) break; //Lee el comando de salir

      int o=0;
      if( strcmp(comando[lastElement(comando)-1],"&")==0 ){
          o=1;
      }
       pid = fork();
      assert(pid >= 0); //asegura que no haya un error, puede ser padre o hijo 
      if( strcmp(comando[lastElement(comando)-1],"&")==0  && pid==0){
          execvp(comando[0], returnArr(comando));

      } else if (pid == 0) { //proceso hijo 
             execvp(comando[0], comando);

      }else if (o == 1 && pid>0){
          insertArray(&procesos, pid);
          continue;
      }
      else{
            if (strcmp(comando[0],"tareas")==0){
            int num_procesos=procesos.used;

             for (int i=0; i<num_procesos; i++){ //Va recorriendo todos los procesos
               printf("%d\n",procesos.array[i]);
                }
            }
            else if(strcmp(comando[0],"detener")==0){
                kill(atoi(comando[1]),9);
            }
          wait(NULL);

      }
    }
        return 0;
}
