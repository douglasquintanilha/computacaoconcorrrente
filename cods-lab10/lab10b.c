/* Disciplina: Computacao Concorrente */
/* Aluno: Douglas Quintanilha */
/* Laboratório: 10 */
/* Codigo: Comunicação entre threads usando variável compartilhada e sincronização com semáforos */

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>
#include <semaphore.h>

#define NTHREADS  4
#define BUFFER_SIZE 5

#define PRODUTORES 2
#define CONSUMIDORES 2

sem_t em;

int buffer[BUFFER_SIZE];
int in,out,count;


void* produtor (void* arg){
	int* p = (int*) arg;
	int pid = (int) p;
	insere(pid);
	pthread_exit(NULL);
}

void* consumidor (void* arg){
	int item;

	item = remove();
	printf("Item removido: [%d]:\n", item);


	pthread_exit(NULL);
}


int main(int argc, char *argv[]) {
	pthread_t threads[NTHREADS]; 
	int t;
	sem_init(&em, 0, 1);


    /* Cria as threads */



	//--espera todas as threads terminarem
	for (t=0; t<NTHREADS; t++) {
		if (pthread_join(threads[t], NULL)) {
		    printf("--ERRO: pthread_join() \n"); exit(-1); 
		} 
	} 
	pthread_exit(NULL);
	return 0;
}