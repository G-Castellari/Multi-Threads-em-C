#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <locale.h>
#include <unistd.h>

void * tabuada (void *num);
void * fatorial (void *num);
void * parOuImpar (void *num);
void * funcaoDeDobro (void *num);
void * numerosVizinhos (void *num);

int main ()
{
    setlocale(LC_ALL, "");
    pthread_t f1, f2, f3, f4, f5;
    int n1 = 0, cod, n2 = 0, n3 = 0, n4 = 0, n5 = 0;

    do
    {
        printf("\n---------------- MENU -----------------\n");
        printf("------------ [0] Sair -----------------\n");
        printf("------------ [1] Tabuada --------------\n");
        printf("------------ [2] Fatorial -------------\n");
        printf("------------ [3] Numero Par ou Impar --\n");
        printf("------------ [4] Dobro ----------------\n");
        printf("------------ [5] Numeros vizinhos -----\n");
        printf("\nDigite a opção desejada: ");
        scanf("%d", &cod);

        switch(cod)
        {
        case 0:
            printf("Tenha um otimo dia!!");
            break;

        case 1:
            printf("Digite um valor: ");
            scanf("%d", &n1);

            pthread_create(&f1, NULL, tabuada, (void *)(&n1));

            pthread_join(f1, NULL);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &n2);

            pthread_create(&f2, NULL, fatorial, (void *)(&n2));

            pthread_join(f2, NULL);
            break;
        case 3:
            printf("Digite um valor: ");
            scanf("%d", &n3);

            pthread_create(&f3, NULL, parOuImpar, (void *)(&n3));

            pthread_join(f3, NULL);
            break;
        case 4:
            printf("Digite um numero: ");
            scanf("%d", &n4);

            pthread_create(&f4, NULL, funcaoDeDobro, (void *)(&n4));

            pthread_join(f4, NULL);
            break;
        case 5:
            printf("Digite um numero: ");
            scanf("%d", &n5);

            pthread_create(&f5, NULL, numerosVizinhos, (void *)(&n5));

            pthread_join(f5, NULL);
        default:
            printf("Opção indisponivel!!\n");
    }
    }
    while(cod != 0);
}

void * tabuada (void *num)
{
    int valor = *(int *)(num);
    int i ;
    printf ("\nO numero da thread é %d\n", pthread_self() );
    for (i = 0; i <= 10; i++)
    {
        printf("Tabuada do %d * %d = %d\n", valor, i, valor * i);
        sleep(1);
    }
}

void * fatorial (void *num)
{
    int number = *(int *)(num);
    int fatorial;
    int aux = *(int *)(num);
    int soma = 0;
    printf ("\nO numero da thread é: %d\n", pthread_self() );
    for(fatorial = 1; number > 1; number--)
    {
        fatorial *= number;
    }
    printf("O faltorial de %d é %d\n", aux, fatorial);
}

void * parOuImpar (void *num)
{
   int number = *(int *)(num);
   printf ("\nO numero da thread é %d\n", pthread_self() );
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
    int number = *(int *)(num);
    printf ("\nO numero da thread é %d\n", pthread_self() );
    printf("\nO dobro de %d é %d\n", number, number*2);
}

void * numerosVizinhos (void *num)
{
    int n1 = *(int *)(num);
    printf ("\nO numero da thread é %d\n", pthread_self() );
    printf("\nVizinho da esquera [%d] %d [%d] Vizinho da direita\n", n1 - 1, n1, n1 +1);
}
