cmake_minimum_required(VERSION 3.29)
project(Atal)

set(CMAKE_CXX_STANDARD 14)

add_executable(Atal
        Atividade3/binaryTrees/Node.h
        Atividade3/binaryTrees/BinaryTree.h
        Atividade3/graph/Grafo.cpp
        Atividade3/binaryTrees/main.cpp
        Atividade3/binaryTrees/BinaryTree.cpp)