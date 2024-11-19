//
// Created by guilh-queiroz on 19/11/24.
//
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree() {
    root = nullptr;
}

Node* BinaryTree::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }

    return node;
}

void BinaryTree::insert(int value) {
    root = insert(root, value);
}

Node* BinaryTree::remove(Node* node, int value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->value) {
        node->left = remove(node->left, value);
    } else if (value > node->value) {
        node->right = remove(node->right, value);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->value = temp->value;
        node->right = remove(node->right, temp->value);
    }

    return node;
}

void BinaryTree::remove(int value) {
    root = remove(root, value);
}


Node* BinaryTree::findMin(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current
    ;
}

void BinaryTree::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }
}

void BinaryTree::preOrder(Node* node) {
    if (node != nullptr) {
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void BinaryTree::postOrder(Node* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
}

void BinaryTree::inOrder() {
    cout << "In-order: ";
    inOrder(root);
    cout << endl;
}

void BinaryTree::preOrder() {
    cout << "Pre-order: ";
    preOrder(root);
    cout << endl;
}

void BinaryTree::postOrder() {
    cout << "Post-order: ";
    postOrder(root);
    cout << endl;
}
