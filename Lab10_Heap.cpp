//q1) Implemente uma Min-Heap de forma iterativa. Use o esqueleto abaixo:

#include <iostream>
#include <vector>

using namespace std;

class Heap{
public:
    Heap(int size) : size(size), count(0) {         ///Cria Heap com tamanho definido
        data = new int[size];
    }
    void teste(){                                   ///Função auxiliar para propósito de teste (imprime data[]);
        for(int i = 0; i<count; i++){
            cout << "[" << data[i] << "] ";
        }
        cout << endl;
    }
    void Insert(int value) {                        /// Insere valor na heap
        if(this->size>this->count){
            bool existe = false; //digraph só aceita uma vez cada valor
            for(int i = 0; i<count; i++){
                if(this->data[i]==value)
                    existe = true;
            }
            if(!existe){
                this->data[this->count] = value;
                int i = this->count;
                while(Father(i)>= 0){ //up heapfy
                    if(this->data[i]<this->data[Father(i)]){
                        int aux = 0;
                        aux = this->data[Father(i)];
                        this->data[Father(i)] = this->data[i];
                        this->data[i] = aux;
                        i = Father(i);
                    }
                    else
                        break;
                }
                count++;
            }
        }
        teste();
    }
    void Remove() {                                  //remove valor do topo
        if(this->count>0){
                int aux = data[0];
                data[0] = data[size-1];
                data[size-1] = aux;
                count--;
                // rever como faz o down heapfy

        }
    }
    void Print() {                                  ///Imprime a Heap no formato do site
        cout << "digraph G {" << endl;
        for (int i = 0; i < count; i++) {
            int l = Left(i);

            if (l < count) {
                cout << "\t" << data[i] <<" -> " << data[l] << endl;

                int r = Right(i);
                if (r < count)
		      cout << "\t" << data[i] <<" -> " << data[r] << endl;
            } else {
                  cout << "\t" << data[i] << ";" << endl;
            }
        }
        cout << "}";
    }
    inline int Left(const int i) const {            ///Retorna a posição do filho da esquerda
        return i * 2 + 1;
    }
    inline int Right(const int i) const {           ///Retorna a posição do filho da direita
        return i * 2 + 2;
    }
    inline int Father(const int i) const {          ///Retorna a posição do pai
        return (i - 1)/ 2;
    }
    ~Heap() {                                       ///destrutor
        delete[] data;
    }
private:
    int *data; //array
    int size;  //numero de nodes disponíveis
    int count; //numero de nodes ocupados
};
int main(){
    Heap teste(10);

    teste.Insert(9);
    teste.Insert(3);
    teste.Insert(4);
    teste.Insert(5);
    teste.Insert(1);
    teste.Insert(2);
    teste.Insert(7);
    teste.Insert(15);
    teste.Insert(22);
    teste.Insert(2);
    teste.Insert(0);
    teste.Insert(400);



    teste.Print();

    return 0;
}
