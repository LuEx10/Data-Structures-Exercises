// Q1.: Implemente uma pilha de inteiros, usandos a técnica de alocação circular com arrays. Use o esqueleto C++ abaixo!
// Q2.: Implemente uma fila de inteiros, usandos a técnica de alocação circular com arrays. Use o esqueleto C++ abaixo!

#include <iostream>

using namespace std;

class Stack {
private:
	int size; // Atributo privado. Pode ser acessado com this->atributo ou só com atributo
	int* pilha;
	int TOP;
	int bot;

public:
	Stack(int size) {
		// Seu construtor. Use para iniciar os atributos.
		this->size = size;
		this->pilha = new int[size];
		this->bot = 0;
		this->TOP = 0;
	}
	void push(int value) {  // TODO: Push deve empilhar um valor.
		if(this->isFull()==false){
            this->pilha[this->TOP] = value;
            this->TOP++;
		}
	}
	void pop() {    // TODO: Pop deve desempilhar um valor.
		if(this->isEmpty()==false){
            this->pilha[(this->TOP)-1] = 0;
            this->TOP--;
		}
	}
	int count() {   // TODO: Deve retornar o total de elementos dentro da pilha.
		return (this->TOP);
	}
	int top() { // TODO: Deve retornar o elemento do TOPo da pilha
        if((this->isEmpty())==false)
            return (this-> pilha[(this->TOP)-1]);
	}
	bool isFull() {
		// TODO
		return((this->TOP)==(this->size));
	}
	bool isEmpty() {
		// TODO
		return(TOP==bot);
	}
	void print() {  // TODO: Esse método deve printar os valores do array!
		cout << "Pilha Atual : (base) ";
		for(int i = 0; i<(this->count()) ;i++){
            cout << "[" << this->pilha[i] << "] ";
		}
		cout << " (topo)" << endl;
	}
	~Stack() {  // Destrutor! Use para desalocar os dados criados com o new
		delete[] this->pilha;
	}
};
class Queue {
private:
	int size; // Atributo privado. Pode ser acessado com this->atributo ou só com atributo
	int* fila;
	int frente;
	int tras;
	int qtd;

public:
	Queue(int size) {
		// Seu construtor. Use para iniciar os atributos.
		this->size = size;
		this->fila = new int[size];
		this->tras = 0;
		this->frente = 0;
	}
	void push(int value) {  // TODO: Push deve empilhar um valor.
	    if(this->isFull()==false){
            this->fila[(this->tras)%(this->size)] = value;
            this->tras++;
            this->qtd++
	    }
	}
	void pop() {    // TODO: Pop deve desempilhar um valor.
	    if(!(this->isEmpty())){
            this->frente++;
            this->qtd--;
	    }
	}
	int count() {   // TODO: Deve retornar o total de elementos dentro da pilha.
            return(qtd);
    }
	int Front() { // TODO: Deve retornar o elemento do frenteo da pilha
        if(!(this->isEmpty()))
            return(this->fila[(this->frente)%(this->size)]);
	}
	bool isFull() {
		// TODO
		return((this->count())==(this->size));
	}
	bool isEmpty() {
		// TODO
		return((this->count())==0);
	}
	void print() {  // TODO: Esse método deve printar os valores do array!
	    cout << "Fila Atual: (front) ";
	    int atual = this->frente;
	    for(int i=0;i<(this->count());i++){
            cout << "[" << this->fila[(atual+i)%(this->size)] << "]";
	    }
        cout << " (back)" << endl;
	}
	~Queue() {  // Destrutor! Use para desalocar os dados criados com o new
		delete[] this->fila;
	}
};

int main() {
	Stack v(20);
	Queue f(10);
	//testes:
	cout<<f.isEmpty()<<endl;
    for(int i = 0; i<11; i++){
        f.push(i*2);
        f.print();
    }
    f.pop();
    f.print();
    f.pop();
    f.print();
    f.push(1);
    f.push(4);
    f.print();
    cout << f.isEmpty() << f.isFull()<<endl;


	return 0;
}
