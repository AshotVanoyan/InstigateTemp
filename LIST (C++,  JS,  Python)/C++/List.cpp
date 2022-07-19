#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"
#include <iostream>

template<typename T>
List<T>::List() : first(nullptr), last(nullptr), length(0) {}

template<typename T>
List<T>::List(int count):first(nullptr), last(nullptr), length(count) {
    if (count <= 0) {
        return;
    }

    first = new Node<T>(T{});
    Node<T> *temp = first;

    for (int i = 1; i < count; ++i) {
        first->next = new Node<T>(T{});
        first = first->next;
    }
    first = temp;
}

template<typename T>
List<T>::List(int count, const T &value):first(nullptr), last(nullptr), length(count) {
    if (count <= 0) {
        return;
    }

    first = new Node<T>(value);
    Node<T> *temp = first;

    for (int i = 1; i < count; ++i) {
        first->next = new Node<T>(value);
        first = first->next;
    }
    first = temp;
}

template<typename T>
List<T>::List(const std::initializer_list<T> &list):first(nullptr), last(nullptr), length(list.size()) {
    if (length == 0) {
        return;
    }

    auto it = list.begin();

    first = new Node<T>(*it);
    Node<T> *tempFirst = first;
    ++it;

    for (; it != list.end(); ++it) {
        first->next = new Node<T>(*it);
        first = first->next;
    }
    last = first;
    first = tempFirst;
}

template<typename T>
List<T>::List(T *arr, int size) : first(nullptr), last(nullptr), length(size) {
    if (size == 0) {
        return;
    }

    first = new Node<T>(arr[0]);
    Node<T> *tempFirst = first;

    for (int i = 1; i < length; ++i) {
        first->next = new Node<T>(arr[i]);
        first = first->next;
    }
    last = first;
    first = tempFirst;
}

template<typename T>
List<T>::List(const List<T> &other) : first(nullptr), last(nullptr), length(0) {
    if (other.empty()) {
        return;
    }

    first = new Node<T>(other.first->data);
    Node<T> *temp = first;
    Node<T> *otherTemp = other.first;
    otherTemp = otherTemp->next;

    while (otherTemp) {
        first->next = new Node<T>(otherTemp->data);
        first = first->next;
        otherTemp = otherTemp->next;
    }

    last = first;
    first = temp;
    length = other.length;
}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::push_front(const T &value) {
    auto *newFront = new Node<T>(value, first);
    first = newFront;
    ++length;
}

template<typename T>
void List<T>::push_back(const T &value) {
    auto *newBack = new Node<T>(value);
    last->next = newBack;
    newBack = last;
    ++length;
}

template<typename T>
void List<T>::insert(int index, const T &data) {
    if (index < 0 || index > length) {
        return;
    }
    if (index == 0) {
        push_front(data);
    } else if (index == length) {
        push_back(data);
    } else {
        Node<T> *temp = first;
        for (int i = 0; i < index; ++i) {
            first = first->next;
        }
        auto *newNode = new Node<T>(data, first->next);
        first->next = newNode;
        first = temp;
        ++length;
    }
}

template<typename T>
void List<T>::pop_front() {
    if (empty()) {
        return;
    }
    Node<T> *del = first;
    first = first->next;
    delete del;
    --length;
}

template<typename T>
void List<T>::pop_back() {
    if (empty()) {
        return;
    }
    if (length == 1) {
        delete first;
        first = last = nullptr;

    } else {
        Node<T> *temp = first;
        for (int i = 0; i < length - 2; ++i) {
            first = first->next;
        }

        delete first->next;
        first->next = nullptr;
        last = first;
        first = temp;
    }
    --length;
}

template<typename T>
void List<T>::erase(int index) {
    if (index < 0 || index >= length || length == 0) {
        return;
    }
    if (index == 0) {
        Node<T> *del = first;
        first = first->next;
        delete del;
    } else {
        Node<T> *temp = first;
        for (int i = 0; i < index - 1; ++i) {
            first = first->next;
        }

        Node<T> *del = first->next;
        if (del->next == nullptr) {
            first->next = nullptr;
            delete last;
            last = first;
        } else {
            first->next = del->next;
            delete del;
        }
        first = temp;
    }
    --length;
}

template<typename T>
void List<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
bool List<T>::empty() const {
    return length == 0;
}

template<typename T>
int List<T>::size() const {
    return length;
}

template<typename T>
void List<T>::print() const {
    if (empty()) {
        return;
    }
    Node<T> *temp = first;
    while (temp) {
        std::cout << temp->data << ' ';
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif // LIST_CPP