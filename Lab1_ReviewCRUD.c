#include <stdio.h>
#include <stdlib.h>
/*
Q1. Calcule a média aritmética das 3 notas de um aluno e mostre, além do valor da média, uma mensagem de "Aprovado", caso a média seja igual ou superior a 6, ou a mensagem "reprovado", caso contrário.
Q2. Elabore um algoritmo que dada a idade de um nadador classifica-o em uma das seguintes categorias:
    infantil A = 5 - 7 anos
    infantil B = 8-10 anos
    juvenil A = 11-13 anos
    juvenil B = 14-17 anos
    adulto = maiores de 18 anos

Q3. Elaborar um algoritmo que lê 3 valores a,b,c e os escreve. A seguir, encontre o maior dos 3 valores e o escreva com a mensagem : "É o maior ".
Q4. Faça um algoritmo que leia um nº inteiro e mostre uma mensagem indicando se este número é par ou ímpar, e se é positivo ou negativo.
Q5. Crie um programa que imprima a soma de todos os números pares 0 até 100; Use a estrutura while.
Q6. Gerar a sequência de fibonacci dos 100 primeiros termos usando while: 0,1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,
Q7. Escreva um programa que leia N do console e calcule o fatorial de N iterativamente.
*/

void Q1(float n1, float n2, float n3){
    float M = (n1+n2+n3)/3;
    printf("Questao 1: \n\tMedia: %.2f\n\t", M);
    if(M >= 6){
        printf("APROVADO!");
    }
    else{
        printf("REPROVADO");
    }
    printf("\n\n");
}
void Q2(int idade){
    printf("\nQuestao 2:");
    if(idade > 17)
        printf("\n\n\tADULTO!\n\n");
    else{
        if(idade > 13)
            printf("\n\n\tJUVENIL B\n\n");
        else{
            if(idade > 10)
                printf("\n\n\tJUVENIL A\n\n");
            else{
                if(idade > 7)
                    printf("\n\n\tINFANTIL B\n\n");
                else{
                    if(idade >= 5)
                        printf("\n\n\tINFANTIL A\n\n");
                    else
                        printf("\n\n\tMENOR QUE 5 ANOS!\n\n");
                }
            }
        }
    }
}
void Q3(){
    float v[3], M = 0;

    printf("Questão 3:\n");
    for(int i = 0; i<=2 ; i++){
        printf("Insira o %do valor: ", i+1);
        scanf("%f", &v[i]);
        if(M < v[i])
            M = v[i];
    }
    printf("\nO Maior Valor e: %f", M);
}
void Q4(){
    int N;

    printf("\n\nQuestao 4:\ninsira um numero: ");
    scanf("%d", &N);
    printf("O numero %d e ", N);
    if(N%2 == 0)
        printf("Par");
    else
        printf("Impar");
    printf(" e ");
    if(N>0)
        printf("Positivo");
    else
        printf("Negativo");
}
void Q5(){
    int i=0;
    printf("\n\nQuestao 5: \n\nNumeros pares: ");
    while(i<=100){
        if(i%2 == 0)
            printf("%d ",i);
        i++;
    }
}
void Q6(){
    int N[100], i = 0;
    printf("\n\n Questao 6:\n Fibonacci: ");
    while(i<100){
        if(i==0||i==1)
            N[i] = i;
        else{
            N[i] = N[i-1] + N[i-2];
        }
        printf("%d ", N[i]);
        i++;
    }
}
void Q7(){
    int N, F;
    printf("\n\nQuestao 7:\n\nInsira um valor: ");
    scanf("%d", &N);
    F = N;
    for(int i = 1; i<N; i++){
        F = F * i;
    }
    printf("Fatorial de %d e igual a %d", N, F);
}
int main()
{
    Q1(1, 10, 9.5);
    Q2(18);
    Q3();
    Q4();
    Q5();
    Q6();
    Q7();
    return 0;
}
