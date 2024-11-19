//
// Created by guilh-queiroz on 19/11/24.
//
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"
#include <iostream>

class BinaryTree {
  private:
    Node* root;

    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value);
    Node* findMin(Node* node);

    void inOrder(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);

    public:
      BinaryTree();
      void insert(int value);
      void remove(int value);
      void inOrder();
      void preOrder();
      void postOrder();
};

#endif