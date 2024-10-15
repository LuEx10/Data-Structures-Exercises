#include <iostream>

using namespace std;

/*Q1: Crie uma rotina recursiva para calcular a soma de todos os valores de um array de inteiros.
Q2: Crie uma rotina recursiva para verificar se uma string é um palíndrome.
Q3: Dado um array de inteiros e o seu número de elementos, inverta a posição dos seus elementos.
Q4: Implemente um método recursivo que receba como entrada um número inteiro positivo N e retorne o seguinte cálculo: 1/1 - 1/2 + 1/3 - 1/4 ... 1/N
Q5. Os números de Pell são definidos pela série 0, 1, 2, 5, 12, 29, 70, 169, 408, 985...
- Onde o próximo número é definido pela fórmula 2*(n) + (n - 1);
- Implemente um método recursivo que receba como entrada um número N e retorne o N-ésimo número de Pell.
Q6: Implemente uma função Sort usando a técnica de Bubble Sort.
  Assinatura: void Sort(int array[], int size);*/

void print_arr_int(int* arr, int Size){ // imprime um array de n posicoes
    for(int i =0; i<Size; i++){
        cout << arr[i];
    }
}

int Q1(int* ar, int n){
    if(n==0)
        return(ar[0]);
    else{
        return(ar[n]+ Q1(ar,(n-1)));
    }
}

char* Q2(char str[], int Size, int cont){
    if(cont >= Size)
        return "sim";
    else{
        if(tolower(str[cont])==tolower(str[Size]))
            return Q2(str, Size-1, cont+1);
        else
            return "nao";
    }
}

void Q3(int* arr, int Size, int cont){
    if(cont<=Size){
        int temp = arr[cont];
        arr[cont] = arr[Size-1];
        arr[Size-1] = temp;
        Q3(arr, --Size, ++cont);
    }
}

float Q4(int n){
    if(n<=1)
        return 1;
    else{
        if(n%2==0)
            return Q4(n-1)-(1.0/n);
        else
            return Q4(n-1)+(1.0/n);
    }
}

int Q5(int n){
    if(n>2)
        return((2*Q5(n-1)) + Q5(n-2));
    else{
        if(n==2)
            return 1;
        else
            return 0;
    }
}

void Q6(int arr[], int Size){
    int temp = 0;
        for(int j = Size-1; j>0; j--){
            for(int i=0;i<j;i++){
                if(arr[i]>arr[i+1]){
                    temp = arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
                //print_arr_int(arr, Size);
                //cout << endl;
            }
        }
}

int main()
{
    int ar_Q1[]={1,2,3,4,5,6,7,8,9,10};
    char* str2 = "Arara";
    int ar3[]={1,2,3,4,5,6,7,8,9};
    int n4 = 5;
    int n5 = 6;
    int seq6[]={9,7,8,4,5,7,2,1};
    int Size6 = sizeof(seq6)/sizeof(int);
    cout << "1)Soma do array = " << Q1(ar_Q1, 9) << endl;
    cout << "2)\"" << str2 << "\" e palindrome?\n  >" << Q2(str2, 5-1, 0) << endl;
    cout << "3) Original: ";print_arr_int(ar3, 9);cout << "\tInvertido: "; Q3(ar3, 9, 0);print_arr_int(ar3, 9);cout << endl;
    cout << "4)A soma dos " << n4 << " numeros da sequencia e igual a " << Q4(n4) << endl;
    cout << "5)O " << n5 << "o numero de Pell e " << Q5(n5) << endl;
    //Q6:
    cout << "6)A sequencia ";
    print_arr_int(seq6, Size6);
    cout << " apos o bubble sort fica: ";
    Q6(seq6, Size6);
    print_arr_int(seq6, Size6);
    cout << endl;
    return 0;
}
