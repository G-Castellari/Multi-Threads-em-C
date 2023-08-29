#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <locale.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

void * tabuada (void *num);
void * fatorial (void *num);
void * parOuImpar (void *num);
void * funcaoDeDobro (void *num);
void * elevarNumero (void *num);
void * jogoDeDados();

int main ()
{
    setlocale(LC_ALL, "");
    pthread_t f1, f2, f3, f4, f5, f6;
    int n1 = 0;

    printf("Digite um valor: ");
    scanf("%d", &n1);
    
    pthread_create(&f1, NULL, tabuada, (void *)(&n1));
    pthread_create(&f2, NULL, fatorial, (void *)(&n1));
    pthread_create(&f3, NULL, parOuImpar, (void *)(&n1));
    pthread_create(&f4, NULL, funcaoDeDobro, (void *)(&n1));
    pthread_create(&f5, NULL, elevarNumero, (void *)(&n1));
    pthread_create(&f6, NULL, (void *) jogoDeDados, NULL);
    

    pthread_join(f1, NULL);
    pthread_join(f2, NULL);
    pthread_join(f3, NULL);
    pthread_join(f4, NULL);
    pthread_join(f5, NULL);
    
}


void * tabuada (void *num)
{
    int valor = *(int *)(num);
    int i ;
    printf ("\nO numero da thread 1 é %lu\n", pthread_self() );
    for (i = 0; i <= 10; i++)
    {
        printf("Tabuada do %d * %d = %d\n", valor, i, valor * i);
        sleep(1);
    }
}

void * fatorial (void *num)
{
    int number = *(int *)num;
    int fatorial;
    int aux = *(int *)num;
    printf ("\nO numero da thread 2 é %lu\n", pthread_self() );
    for(fatorial = 1; number > 1; number--)
    {
        fatorial *= number;
    }
    sleep(1);
    printf("O faltorial de %d é %d\n", aux, fatorial);
}

void * parOuImpar (void *num)
{
   int number = *(int *)num;
   printf ("\nO numero da thread 3 é %lu\n", pthread_self() );
   sleep(1);
   if(number % 2 == 0){
       printf("\nO numero %d é Par\n", number);
   }
   else
   {
       printf("\nO numero %d é Impar\n",number);
   }
}

void * funcaoDeDobro (void *num)
{
    int number = *(int *)num;
    sleep(1);
    printf ("\nO numero da thread 4 é %lu\n", pthread_self() );
    printf("\nO dobro de %d é %d\n", number, number*2);
}

void * elevarNumero (void *num)
{
    int numeber = *(int *)num;
    printf ("\nO numero da thread 5 é %lu\n", pthread_self() );
    int n1;
    sleep(1);
    n1 = pow(numeber, 2);
    printf("\n%d elevado ao quadrado é: %d\n", numeber, n1);
}

void * jogoDeDados()
{
    int num;
    printf ("\nO numero da thread 5 é %lu\n", pthread_self() );
    srand(time(NULL));
    num = rand()%6 + 1;
    printf("Face do dado: %d\n", num);
}
