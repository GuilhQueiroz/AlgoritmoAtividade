//
// Created by guilh-queiroz on 19/11/24.
//
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Classe para representar um grafo
class Grafo{
  public:
    int V; // Número de vértices
    vector<list<int>> adj; // Lista de adjacências

    // Construtor
    Grafo(int V){
      this->V = V;
      adj.resize(V); // Inicializa a lista de adjacências
    }

    // Função para adicionar um aresta
    void addEdge(int v, int w){
      adj[v].push_back(w); // Adiciona w à lista de adjacência de v
      adj[w].push_back(v); // Para grafo não direcionado
    }

    // Função para imprimir o grafo
    void printGrafo(){
      for (int v = 0; v < V; v++){
        cout << "Vértice " << v << ":";
        for (int w : adj[v]){
          cout << w << " ";
        }
        cout << endl;
      }
    }
};

int main(){
  Grafo g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);

  g.printGrafo();;

  return 0;
}