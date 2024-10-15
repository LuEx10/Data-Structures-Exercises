#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <ctype.h>

#define pi 3.14
using namespace std;

void Q1(int &x1, int &x2, int &x3)
{
    cout << "1) Conteudo de maior endereco: ";
    if(&x1>&x2){
        if(&x3>&x1)
            cout << x3 << endl;
        else
            cout << x1 << endl;
    }
    else{
        if(&x3>&x2)
            cout << x3 << endl;
        else
            cout << x2 << endl;
    }
    cout << endl;
}
void calc_esfera(float R, float *area, float *volume)
{
    /*A área da superfície e o volume são dados, respectivamente, por:
    A = 4 ∗ p ∗ R^2
    V = 4/3 ∗ p ∗ R^3*/

    *area = 4*pi*(R*R);
    *volume = (4*pi*R*R*R)/3;
    cout << "2) Raio = " << R << endl << "   Area = " << *area << endl << "   Volume = " << *volume << endl << endl;
}
int negativos(float *vet, int N)
{
    int c;
    for(int i = 0 ; i<N ; i++){
        if(vet[i]<0)
            c++;
    }
    return c;
}
bool contains(const char* str, const char* str2)  // contains verifica se str2 está contida dentro de str1
{
    int c=0;
    while(*str!='\0'){
        if(tolower(*str) == tolower(*str2)){
            str2++;
            c++;
        }
        else{
            if(*str2=='\0'){
                return true;
            }
            else{
                str2-=c;
                c=0;
            }
        }
        str++;
    };
    if(*str2=='\0')
        return true;
    else
        return false;
}
void Q5(int* vet, int v){
    cout << "5) vetor original\t|\tvetor preenchido"<< endl;
    for(int i=0;i<sizeof(*vet);i++){
        cout << *vet<< "\t\t|\t\t";
        *vet = v;
        cout << *vet<<endl;
        vet++;
    }
    cout <<*vet--<< "\t\t|\t\t"<< *vet<<endl;
}
typedef struct{
    string Nome;
    int Telefone;
    string Email;
}Pessoa;
bool equals(Pessoa *p, Pessoa *q){
    //Nome
    int i;
    if(p->Nome!=q->Nome)
        return 0;
    //Telefone
    for(i=0;i<sizeof(p->Telefone);i++){
        if(p->Telefone != q->Telefone)
            return 0;
    }
    //email
    if(p->Email!=q->Email)
        return 0;
    return 1;
};
int add(int a, int b){
    return a+b;
};
int sub(int a, int b){
    return a-b;
};
int mul(int a, int b){
    return a*b;
};
int divi(int a, int b){
    return a/b;
};
typedef int tOp(int a, int b);
int Sum(tOp* operacao[4], int a, int b){
    int S=0;
    for(int i = 0; i<4; i++){
        S+=operacao[i](a,b);
    }
    return S;
}

int main()
{
    int x11 = 12, x12 = 84, x13 = 23, N3 = 10, ar5[5]={0};
    float R2 = 2, a2, v2, vet3[10]{-1, 2, 3, 4, 5, 6, -7, 8, -9, 10};
    const char* str41;
    const char* str42;
    Pessoa P1, P2;

    //questao 1:
    Q1(x11,x12,x13);

    //questao 2:
    calc_esfera(R2, &a2, &v2);

    //questão 3:
    cout << "3) tem "<< negativos(vet3, N3) << " numeros negativos no array" << endl << endl;

    //questao 4:
    str41 ="Essa e a primeira string\0";
    str42 ="essa\0";
    cout << "4) a primeira string ";
    if(!contains(str41, str42)){
        cout << "nao ";
    }
    cout << "contem a segunda."<< endl << endl;

    //questao 5:
    Q5(ar5, 5);

    //questao 6:
    P1.Nome = "Lucas";
    P2.Nome = "Lucas";
    P1.Telefone = 12345678;
    P2.Telefone = 12345678;
    P1.Email = "abc@gmail.com";
    P2.Email = "abc@gmail.com";
    cout << endl << "6) [1 = equals, 0 = different] =>  " << equals(&P1, &P2)<<endl;

    //questao 7:
    tOp* Operacoes[4] = {add, sub, mul, divi};
    cout << endl << "7) resultado com 4 e 2: " << Sum(Operacoes, 4, 2) <<endl;


    return 0;
}
