//
// Created by guilh-queiroz on 19/11/24.
//
#include <iostream>
using namespace std;

// Estrutura para resepresentar um nó da árvore binária
struct node{
  int valor;
  node *left;
  node *right;

  node (int val){
    valor = val;
    left = right = nullptr;
  }
};

// Função para inserir um valor na árvore binária

node* insert(node* root, int valor){
  if(root == nullptr){
    return new node(valor);
    }

    if (valor < root->valor){
      root->left = insert(root->left, valor);
    } else {
      root->right = insert(root->right, valor);
    }

    return root;
}

// Função para percorrer a árvore em ordem (in-order)
void inorder(node* root){
  if(root != nullptr){
    inorder(root->left);
    cout << root->valor << " ";
    inorder(root->right);
  }
}

int main(){
  node* root = nullptr;

  root = insert(root, 70);
  insert(root, 20);
  insert(root, 50);
  insert(root, 40);
  insert(root, 30);
  insert(root, 60);
  insert(root, 10);

  cout << "Árvore binária em ordem: ";
  inorder(root);
  cout << endl;

  return 0;
}