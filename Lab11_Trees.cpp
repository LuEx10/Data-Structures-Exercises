
#include <iostream>
#include <string>

using namespace std;

class Tree {
    private:
        struct Node {
            int key;
            Node* left;
            Node* right;
        };
    public:
        Tree() : root(0) {          //construtor: ponteiro raiz = 0

        }
        void Insert(int key) {      //insere seguindo a ordem (a raiz nao muda nunca)
            Node* novo = new Node();
            novo->key = key;
            novo->left = 0;
            novo->right = 0;

            if (root == 0) {
                root = novo;
                //cout << "raiz = " << key <<endl;
            } else {
                Node *p = Parent(key);
                //cout << "pai = " << p->key << endl;
                if (p == 0)
                    return;

                if (p->key > key)
                    p->left = novo;
                else
                    p->right = novo;
            }
        }
        void Print() {              //imprime InOrder(root);
            InOrder(root);
        }

        bool Contains(int key){
            Node* it = root;
            while(it!=0){
                if(it->key == key)
                    return true;
                else{
                    if(it->key > key)
                        it = it->left;
                    else
                        it = it->right;
                }
            }
            return false;
        }

        void Remove(int key){
            if(Contains(key)){
                Node* it = root;
                Node* p;

                while(it->key!=key){                    //encontrar posi��o e pai
                    p = it;
                    if(it->key>key)
                        it = it->left;
                    else
                        it = it->right;
                }
                if(it == root)
                    p = 0;

                if(it->left!=it->right){                //se for ramo ou raiz
                    if(it->left==0 || it->right==0){    //se tiver apenas um filho
                        Rearranja_1filho(p, it);
                    }
                    else{                               //se tiver 2 filhos
                        Rearranja_2filho(p,it);
                    }
                    delete it;
                }
                else{                                   //se for uma folha
                    Remove_folha(p, it);                         //remover
                }
            }
        }
        ~Tree() {                   //destrutor
            Free(root);
            root = 0;
        }
    private:
        void Remove_folha(Node* p, Node* it){                                   //se for uma folha
            if(p!=0){ //se n�o for a raiz
                if(p->key >it->key)                 //ajustar ponteiro pai
                    p->left = 0;
                else
                    p->right = 0;
                delete it;
            }
            else{
                delete it;
                root = 0;
            }
                                      //remover
        }
        void Rearranja_1filho(Node* p, Node* it){
            if(p != 0){
                if(p->key > it->key){
                    if(it->left==0)
                        p->left = it->right;
                    else
                        p->left = it->left;
                }
                else{
                    if(it->left==0)
                        p->right = it->right;
                    else
                        p->right = it->left;
                }
            }
            else{
                if(it->left==0)
                    root = it->right;
                else
                    root = it->left;

            }


        }
        void Rearranja_2filho(Node* p, Node* it){
            //mais � direita da esquerda substit�i it!
            Node* sub = Direita_da_Esquerda(it);
            sub->left = it->left;
            sub->right = it->right;
            if(p!=0){
                if(p->key > it->key){
                    p->left = sub;
                }
                else{
                    p->right = sub;
                }
            }
            else{
                root = sub;
            }
        }
        Node* Direita_da_Esquerda(Node* it){
            Node* dir = it->left;
            Node* pdir = it;

            while(dir->right!=0){   //atualiza auxiliar
                pdir = dir;
                dir = dir->right;
            }
            if(dir != it->left){
                if(dir->left!=0){       //atualiza ponteiro do pai auxiliar
                    pdir->right = dir->left;
                }
                else{
                    pdir->right = 0;
                }
            }
            else{
                if(dir->left!=0){       //atualiza ponteiro do pai auxiliar
                    pdir->left = dir->left;
                }
                else{
                    pdir->left = 0;
                }
            }

            //cout<< "retorno direita: "<<dir->key <<endl;
            //cout<< "Pdir left: "<<pdir->left->key<<endl;
            //cout<< "Pdir right: "<<pdir->right->key<<endl;

            return dir;
        }

        void InOrder(Node* root) {  // imprime tudo na ordem que aparece (crescente)
            if (root == 0)
                return;

            InOrder(root->left);
            cout << root->key << endl;
            InOrder(root->right);
        }
        void Free(Node* root) {     // libera todos os nodes de forma recursiva (aux destrutor)
            if (root == 0)
                return;

            Free(root->left);
            Free(root->right);
            delete root;
        }
        Node* Parent(int key) {     // return parent de uma key (que ainda n�o esteja na �rvore)
            Node* it = root;
            Node *p = root;
            while (it != 0) {
                p = it;
                if (it->key > key) {
                    it = it->left;
                } else if (it->key < key) {
                    it = it->right;
                } else {
                    return 0;
                }
            }
            return p;
        }
    private:
        Node *root;
};


int main()
{
    Tree t;
    t.Insert(20);
    t.Insert(10);
    t.Insert(5);
    t.Insert(15);
    t.Insert(25);
    t.Insert(16);
    t.Insert(50);
    t.Insert(-1);
    t.Print();
    cout<<endl;
    t.Remove(20);
    t.Print();
    return 1;
}
