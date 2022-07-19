//
// Created by User on 7/5/2022.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
#include "Node.h"
#include <initializer_list>

template<typename T>
class List{
public:
    List();
    explicit List(int);
    List(int, const T&);
    List(const std::initializer_list<T>&);
    List(T*, int);
    List(const List&);
    ~List();

    void push_front(const T&);
    void push_back(const T&);
    void insert(int, const T&);
    void pop_front();
    void pop_back();
    void erase(int);
    void clear();

    bool empty()const;
    int size()const;

    void print()const;
private:
    Node<T>* first;
    Node<T>* last;
    int length;
};
#include "List.cpp"
#endif //LIST_LIST_H
