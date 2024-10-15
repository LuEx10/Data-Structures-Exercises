// Q1.: Implemente os métodos Set, HasKey e Get de HashTable e o destrutor
#include <iostream>

using namespace std;

class HashTable {
private:
	struct Node {
		Node *next;
		string text;
		int key;
	};

private:
	int Size;
	Node** data;
	Node* Key_Node(int key){
        Node* Atual = this->data[key%(this->Size)];
	    while(Atual != 0){
            if(Atual->key == key)
                return Atual;
            Atual = Atual->next;
	    }
	    return 0;
	};

public:
	HashTable(int Size) : Size(Size) {  //construtor
		data = new Node*[Size];         //cria o vetor de Nodes
		for (int i = 0; i < Size; i++)
			data[i] = 0;                //inicializa o ponteiro de cada posição apontando para 0
	}
	void Set(int key, string text) {    //Set e usado para inserir um valor em data (HashTable).
	    int index = key%(this->Size);
	    Node* Destino = Key_Node(key);
	    if(Destino==0){
            Node* Novo = new Node;
            Novo->key = key;
            Novo->text = text;
            Novo->next = this->data[index];
            this->data[index] = Novo;
	    }
	    else
            Destino->text = text;
	}
	bool HasKey(int key) {              //HasKey verifica se existe um valor em data (HashTable).
        int index = key%(this->Size);
        Node* atual = this->data[index];
        while(atual!=0){
            if (atual->key == key)
                return true;
            atual = atual->next;
        }
		return false;
	}
	string Get(int key) {               //Get retorna um valor com base em Key
        Node* Atual = this->data[key%(this->Size)];
        while(Atual!=0){
            if(Atual->key == key)
                return Atual->text;
            Atual = Atual->next;
        }
		return "A chave nao existe!";
	}
	~HashTable() {                      //destrutor
		for (int i = 0; i < Size; i++) {
			if (data[i]){
                Node* Atual = data[i];
                while(Atual!=0){
                    Node* Proximo = Atual;
                    Proximo = Atual->next;
                    delete Atual;
                    Atual = Proximo;
                }
			}
		}
		delete data;
	}
};


int main() {
	HashTable table(97);                        //cria tabela de 97 lugares

	cout << table.HasKey(123456) << endl;       //testa se tem uma key (não vai ter)

	table.Set(123456, "Joao Pedro");            //seta a chave 123456
	cout << table.HasKey(123456) << endl;       //testa se tem a key (vai ter)
	cout << table.Get(123456) << endl;          //imprime "Joao Pedro"

	table.Set(123456, "Maria");                 //seta a chave 123456 como maria (lugar ocupado)
	cout << table.Get(123456) << endl;          //imprime

	for (int i = 0; i < 300; i++)
		table.Set(i, "Key = " + to_string(i));  //seta 300 keys para a mesma tabela

	for (int i = 0; i < 300; i++)
		cout << table.Get(i) << endl;           //imprime a tabela inteira

	return 0;
}
