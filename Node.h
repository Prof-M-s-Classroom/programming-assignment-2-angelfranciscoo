#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    // TODO: Implement constructor here
    Node() : left(nullptr), right(nullptr) {}
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
    Node(T value, Node* l, Node* r) : data(value), left(l), right(r) {}
};

#endif // NODE_H