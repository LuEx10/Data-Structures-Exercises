//https://dreampuf.github.io/GraphvizOnline/#digraph%20G%20%7B%0D%0Aa%20-%3E%20b%3B%0D%0Aa%20-%3E%20c%3B%0D%0Aa%20-%3E%20d%3B%0D%0Ab%3B%0D%0Ac%3B%0D%0Ad%20-%3E%20a%3B%0D%0Ad%20-%3E%20e%3B%0D%0Ad%20-%3E%20c%3B%0D%0Ae%20-%3E%20a%3B%0D%0Ae%20-%3E%20e%3B%0D%0A%7D
// Example program
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph {
private:
    inline char StrVertice(const int i) {   ///retorna a letra do vertice
        return (char) ('a' + i);
    }
    vector<int>* vertices;
    int Size;
public:
    Graph(int Size) : Size(Size) {          ///cria um vector do tamanho desejado
        vertices = new vector<int>[Size];
    }
    void Connect(int src, int dst) {        ///pushback o destino na lista do source
        vertices[src].push_back(dst);
    }
    void Print() {                          ///imprime o grafo no formato para visualizacao
        cout << "digraph G {" << endl;
        for (int s = 0; s < Size; s++) {
            vector<int> v = vertices[s];
            int totalEdges = v.size();
            if (totalEdges == 0)
                cout << StrVertice(s)  << ";" << endl;

            for (int d = 0; d < totalEdges; d++) {
                cout << StrVertice(s)
                << " -> " <<  StrVertice(v[d])
                << ";" << endl;
            }
        }

        cout << "}" << endl;
    }
    void Disconnect(int src, int dst){      ///deleta uma conecção
        int i=0;
        for(i=0;i<vertices[src].size();i++){
            if(vertices[src][i]==dst){
                int aux = vertices[src][i];
                vertices[src][i] = vertices[src][(vertices[src].size())-1];
                vertices[src][(vertices[src].size())-1] = aux;
                vertices[src].pop_back();
                break;
            }
        }
    }
    bool DFS(int src, int target){          //busca por profundidade
        stack<int> S;
        bool check[Size]={0};
        int aux;

        S.push(src);
        while(S.size()){
            aux = S.top();
            S.pop();
            if(aux==target){
                return true;
            }
            else{
            	check[aux]=true;
                for(int i=vertices[aux].size()-1;i>=0;i--){
                        if(!check[vertices[aux][i]])
                            S.push(vertices[aux][i]);
                }
            }
        }
        return false;
    }
    bool BFS(int src, int target){          ///busca por largura
		queue<int> S;
		bool check[Size]={0};
		int aux;
		
		S.push(src);
		while(S.size()){
			aux = S.front();
			S.pop();
			if(aux==target){
				return true;
			}
			else{
            	check[aux]=true;
				for(int i=vertices[aux].size()-1;i>=0;i--){
					if(!check[vertices[aux][i]])
						S.push(vertices[aux][i]);
				}
			}
		}
		return false;
    }
    ~Graph() {								///destrutor
        delete[] vertices;
    }
};


int main()
{
    Graph g(5);
    g.Connect(0,1);
    g.Connect(0,2);
    g.Connect(0,3);
    g.Connect(3,0);
    g.Connect(3,4);
    g.Connect(3,2);
    g.Connect(4,0);
    g.Connect(4,4);
    g.Print();
    g.Disconnect(3,0);

    cout<< g.DFS(0,3) <<endl;
    cout<< g.DFS(4,1) <<endl;
    cout<< g.DFS(2,3) <<endl;
    cout<< g.DFS(3,0) <<endl;
	cout<<endl;
    cout<< g.BFS(0,3) <<endl;
    cout<< g.BFS(4,1) <<endl;
    cout<< g.BFS(2,3) <<endl;
    cout<< g.BFS(3,0) <<endl;

    return 0;
}
