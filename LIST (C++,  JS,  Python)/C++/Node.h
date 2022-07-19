//
// Created by User on 7/5/2022.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H

template <typename T>
struct Node{
    T data{};
    Node<T>* next{};

    explicit Node(T, Node<T>* = nullptr);
};


#include "Node.cpp"
#endif //LIST_NODE_H
