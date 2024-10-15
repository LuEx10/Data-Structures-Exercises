#include <iostream>
#include <string>
#include <stdint.h>
using namespace std;

class BitSet {
public:
	
    BitSet(int size) : size(size) { //4000
        data = new unsigned[size]; // 4 bytes = 32 bits
        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    void Insert(int v) {
        int index = v / GetBlockSize();
        int pos = v % GetBlockSize();
        //da um or binario
        data[index] |= (1 << pos); // = data[index] = data[index] | (1 << pos); 
    }

    bool Contains(int v) {
        int index = v /  GetBlockSize();
        int pos = v %  GetBlockSize();
        // and binário
        return data[index] & (1 << pos); // 1 com 1 = true | 1 com 0 = false;
    }

    void Remove(int v) {
        int index = v / GetBlockSize();
        int pos = v % GetBlockSize();
        // xor binário
        if(Contains(v)==true)
        data[index] = data[index] ^ (1 << pos);
        else{
        	cout << "Nao tem esse elemento " << endl;
        	return;
		}
    }

    void Print() {
        int totalBits = size * GetBlockSize();
        for (int i = 0; i < totalBits; i++) {
            if (Contains(i))
                cout  << i << ", ";
        }
        cout << endl;
    }

    int getMaior(BitSet &a,BitSet &b){
        int maior;
        if(a.getSize()>= b.getSize())
            maior = a.getSize();
        else
            maior = b.getSize();
        return maior;
    }
    
    int getMenor(BitSet &a,BitSet &b){
    	int menor;
        if(a.getSize()<= b.getSize())
            menor = a.getSize();
        else
            menor = b.getSize();
        return menor;
	}

    void Uni(BitSet &a,BitSet &b){
        int maior = this->getMaior(a,b);
        for (int i = 0; i < maior; i++){
            this->data[i] = a.data[i] | b.data[i]; // or 
        }
    }
    
    void Inter(BitSet &a,BitSet &b){
         int maior = this->getMaior(a,b);
        for (int i = 0; i < maior; i++){
            this->data[i] = a.data[i] & b.data[i]; // and
        }
    }
    
     void Dif(BitSet &a,BitSet &b){
        int maior = this->getMaior(a,b);
        for (int i = 0; i < maior; i++){
            this->data[i] = a.data[i] & b.data[i];
            this->data[i] = this->data[i] ^ a.data[i]; // xor
        }
    }
    
    void resize(int newsize){
    	BitSet* bitres = new BitSet(newsize);
    	for (int i = 0; i < size; i++){
            bitres->data[i] = bitres->data[i] | this->data[i]; // or 
        }
        delete[] this->data;
        this->data=bitres->data;
        this->size=bitres->size;
	}

    int getSize(){
        return this->size;
    }

    ~BitSet() {
        delete[] data;
    }

private:
    inline const unsigned GetBlockSize() const {
        return sizeof(data)*sizeof(unsigned); // 32 bytes
    }
private:
    int size;
    unsigned* data; // ponteiro = 8 bytes
};

int main()
{
    BitSet bit1(10);
    BitSet bit2(5);
    bit2.Insert(5);
    bit2.Insert(8);
	bit1.Print();
    bit2.Print();
}
