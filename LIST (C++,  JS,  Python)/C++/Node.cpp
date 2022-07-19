#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"
template<typename T>
Node<T>::Node(T data, Node<T> *next) : data(data), next(next) {}

#endif // NODE_CPP