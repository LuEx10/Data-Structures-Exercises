//Q1: Implementar um deque usando listas duplamente encadeadas com as funções push_front, pop_front, push_back, pop_back, size e uma função para printar os valores do deque.

#include <iostream>

using namespace std;

struct Node{
    int Data;
    Node* Next;
    Node* Prev;

    Node(int data){
        this-> Next = 0;
        this-> Prev = 0;
        this-> Data = data;
    }
};

class Deque{
private:
    int dSize;
    Node* Front;
    Node* Back;

public:
	Deque(){//contrutor
	    this->Front = 0;
	    this->Back = 0;
	    this->dSize = 0;
	}
	void Push_front(int data){//adiciona mais um na frente
        Node* node = new Node(data);
        if(this->Front==0){
            this->Front = node;
            this->Back = node;
        }
        else{
            (this->Front)->Prev = node;
            node->Next = this->Front;
            this->Front = node;
        }
        this->dSize++;
	}
	void Push_back(int data){//adiciona mais um atras
        Node* node = new Node(data);
        if(this->Back==0){
            this->Front = node;
            this->Back = node;
        }
        else{
            (this->Back)->Next = node;
            node->Prev = this->Back;
            this->Back = node;
        }
        this->dSize++;
	}
	void Pop_Front(){//tira um da frente//Next aponta para o que H apontava,o prev do node que o h apontava aponta para o novo e o H aponta para o novo node (n.next = H; h.prev= N; h=n)
        if(this->Size()>0){
            Node* Pop = this->Front;
            if(this->Front==this->Back){
                this->Front = 0;
                this-> Back = 0;
                delete Pop;
                this->dSize--;
            }
            else{
                (Pop->Next)->Prev = 0;
                this->Front = Pop->Next;
                Pop->Next = 0;
                delete Pop;
                this->dSize--;
            }
        }
	}
	void Pop_Back(){//tira um de tras
	    if(this->Size()>0){
            Node* Pop = this->Back;
            if(this->Front==this->Back){
                this->Front = 0;
                this-> Back = 0;
                delete Pop;
                this->dSize--;
            }
            else{
                (Pop->Prev)->Next = 0;
                this->Back = Pop->Prev;
                Pop->Prev = 0;
                delete Pop;
                this->dSize--;
            }
        }
	}
	int Size(){//imprime o tamanho
        return(this->dSize);
	}
	void Print(){//imprime o deck intiro
	    cout << "Deck Atual:\n (front)";
	    Node* Atual = this->Front;
	    for(int i = 0; i<this->Size(); i++){
            cout << " ["<< Atual->Data << "] ";
            Atual = Atual->Next;
	    }
	    cout << "(back)" << endl << " tamanho atual: " << this->Size() << endl;
	}
};

int main() {
    Deque* d = new Deque();
    d->Push_front(1);
    d->Print();cout<<endl;
    d->Push_front(2);
    d->Print();cout<<endl;
    d->Push_back(3);
    d->Print();cout<<endl;
    d->Pop_Front();
    d->Print();cout<<endl;
    d->Push_front(4);
    d->Print();cout<<endl;
    d->Pop_Front();
    d->Print();cout<<endl;
    d->Pop_Front();
    d->Print();cout<<endl;
    d->Pop_Front();
    d->Print();cout<<endl;
    d->Pop_Front();
    d->Print();cout<<endl;

	return 0;
}
