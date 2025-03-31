#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    // TODO: Implement constructor here

    //default constructor
    Node() : left(nullptr), right(nullptr) {}

    //constructor with only data value
    Node(T value) : data(value), left(nullptr), right(nullptr) {}

    //fully parameterized constructor
    Node(T value, Node* l, Node* r) : data(value), left(l), right(r) {}
};

#endif // NODE_H