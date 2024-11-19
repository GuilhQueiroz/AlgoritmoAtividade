//
// Created by guilh-queiroz on 19/11/24.
//
#ifndef NODE_H
#define NODE_H

class Node {
    public:
    int value;
    Node* left;
    Node* right;

    // Construtor do nó
    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

#endif