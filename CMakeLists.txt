cmake_minimum_required(VERSION 3.29)
project(Atal)

set(CMAKE_CXX_STANDARD 14)

add_executable(Atal
        atividade3/binaryTrees/Node.h
        atividade3/binaryTrees/BinaryTree.h
        atividade3/graph/Grafo.cpp
        atividade3/binaryTrees/main.cpp
        atividade3/binaryTrees/BinaryTree.cpp)