#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <locale.h>
#include <unistd.h>
#include <semaphore.h>
#include <math.h>
#include <time.h>

sem_t S;

void *tabuada (void *num)
{
    sem_wait (&S);
    int valor = *(int *)(num);
    int i ;
    printf ("\nThread da função de tabuada: %lu\n", pthread_self() );
    for (i = 0; i <= 10; i++)
    {
        printf("Tabuada do %d * %d = %d\n", valor, i, valor * i);
        sleep(1);
    }
    sem_post (&S);
}

void *fatorial (void *num)
{
    sem_wait (&S);
    int number = *(int *)num;
    int fatorial;
    int aux = *(int *)num;
    sleep(1);
    printf ("\nThread da função fatorial: %lu\n", pthread_self() );
    for(fatorial = 1; number > 1; number--)
    {
        fatorial *= number;
    }
    printf("\nO faltorial de %d é %d\n", aux, fatorial);
    sem_post (&S);
}

void *parOuImpar (void *num)
{
    sem_wait (&S);
   int number = *(int *)num;
   sleep(1);
   printf ("\nThread da função par ou ímpar: %lu\n", pthread_self() );
   
   if(number % 2 == 0){
       printf("\nO numero %d é Par\n", number);
   }
   else
   {
       printf("\nO numero %d é Ímpar\n",number);
   }
   sem_post (&S);
}

void *funcaoDeDobro (void *num)
{
    sem_wait (&S);
    int number = *(int *)num;
    sleep(1);
    printf ("\nThread da função de dobro: %lu\n", pthread_self() );
    printf("\nO dobro de %d = %d\n", number, number*2);
    sem_post (&S);
}

void *elevarNumero (void *num)
{
    sem_wait (&S);
    int numeber = *(int *)num;
    sleep(1);
    printf ("\nThread da função de elevar número ao quadrado: %lu\n", pthread_self() );
    int n1;
    
    n1 = pow(numeber, 2);
    printf("\n%d elevado ao quadrado é: %d\n", numeber, n1);
    sem_post (&S);
}

void *jogoDeDados()
{
    sem_wait (&S);
    int num;
    sleep(1);
    printf ("\nThread da função de jogo do dado: %lu\n", pthread_self() );
    srand(time(NULL));
    num = rand()%6 + 1;
    printf("\nFace do dado: %d\n", num);
    sem_post (&S);
}


int main ()
{
    setlocale(LC_ALL, " ");
    pthread_t tabuadaThread, fatorialThread, parOuImparThread, funcaoDeDobroThread, elevarNumeroThread, jogoDeDadosThread;
    int n1 = 0;
    sem_init (&S, 0, 1);

    printf("Digite um valor para execultar as funções: ");
    scanf("%d", &n1);
    
    pthread_create(&tabuadaThread, NULL, tabuada, (void *)(&n1));
    pthread_create(&fatorialThread, NULL, fatorial, (void *)(&n1));
    pthread_create(&parOuImparThread, NULL, parOuImpar, (void *)(&n1));
    pthread_create(&funcaoDeDobroThread, NULL, funcaoDeDobro, (void *)(&n1));
    pthread_create(&elevarNumeroThread, NULL, elevarNumero, (void *)(&n1));
    pthread_create(&jogoDeDadosThread, NULL, (void *) jogoDeDados, NULL);
    

    pthread_join(tabuadaThread, NULL);
    pthread_join(fatorialThread, NULL);
    pthread_join(parOuImparThread, NULL);
    pthread_join(funcaoDeDobroThread, NULL);
    pthread_join(elevarNumeroThread, NULL);
    pthread_join(jogoDeDadosThread, NULL);
    
    return 0;
}
