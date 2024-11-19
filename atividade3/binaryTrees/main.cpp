//
// Created by guilh-queiroz on 19/11/24.
//
#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
  BinaryTree tree;
  int option, value;

  do{
    cout << "Escolha uma opcao:" << endl;
    cout << "1. Inserir valor na árvore" << endl;
    cout << "2. Remover valor da árvore" << endl;
    cout << "3. Exibir valores (In-order)" << endl;
    cout << "4. Exibir valores (Pre-order)" << endl;
    cout << "5. Exibir valores (Post-order)" << endl;
    cout << "0. Sair" << endl;
    cout << "Opcao: ";
    cin >> option;

    switch(option) {
      case 1:
        cout << "Digite um valor para inserir na árvore: ";
      cin >> value;
      tree.insert(value);
      break;
      case 2:
        cout << "Digite um valor para remover da árvore: ";
      cin >> value;
      tree.remove(value);
      break;
      case 3:
        tree.inOrder();
      break;
      case 4:
        tree.preOrder();
      break;
      case 5:
        tree.postOrder();
      break;
      case 0:
        cout << "Saindo..." << endl;
      break;
      default:
        cout << "Opcao invalida! Tente novamente." << endl;
    }
  } while (option != 0);

  return 0;
}