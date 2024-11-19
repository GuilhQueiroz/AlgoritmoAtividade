//
// Created by guilh-queiroz on 19/11/24.
//
#include <iostream>
#define MAX 100 // Definindo um tamanho máximo para a pilha

class Pilha {
    private:
    int topo;
    int arr[MAX];

    public:
    // Construtor: inicializa a pilha como vazia
    Pilha() {
        topo = -1;
    }

    // Função para verificar se a pilha está vazia
    bool estaVazia() {
        return topo == -1;
    }

    // Função para verificar se a pilha está cheia
    bool estaCheia() {
        return topo == MAX - 1;
    }

    // Função para adicionar um elemento a pilha
    void empilhar(int valor) {
        if(estaCheia()) {
            std::cout << "Erro: Pilha cheia!" << std::endl;
            return;
        }
         arr[++topo] = valor;
    }

    // Função para remover o elemento do topo da pilha
    int desempilhar() {
        if(estaCheia()) {
            std::cout << "Erro: Pilha vazia!" << std::endl;
            return -1;
        }
        return arr[topo--];
    }

    // Função para verificar o elemento no topo da pilha
    int olharTopo() {
        if(estaVazia()) {
            std::cout << "Erro: Pilha vazia!" << std::endl;
            return -1;
        }
        return arr[topo]; // Retorna valor do topo sem remover
    }

    // Função para mostrar todos os elementos da pilha
    void mostrarPilha() {
        if(estaVazia()) {
            std::cout << "Erro: Pilha está vazia." << std::endl;
            return;
        }

        std::cout << "Elementos da Pilha: ";
        for (int i = 0; i <= topo; i++ ) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Pilha pilha;

    // Empilhar alguns elementos
    pilha.empilhar(10);
    pilha.empilhar(20);
    pilha.empilhar(30);

    // Mostrar os elementos da pilha
    pilha.mostrarPilha();
    // Desempilhar e mostrar o topo
    std::cout << "Elementos desempilhado: " << pilha.desempilhar() << std::endl;
    std::cout << "Novo topo da pilha: " << pilha.olharTopo() << std::endl;

    // Mostrar os elementos da pilha após desempilhar
    pilha.mostrarPilha();

    return 0;
}