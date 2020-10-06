#pragma once

#include <iostream>

using std::string;

template <class Type>
class Node {
private:
    Type info;

    Node<Type> *next;

    Node<Type> *prev;

    template<Type> friend class DList;

public:
    explicit Node(Type _info, Node<Type> *_prev, Node<Type> *_next);

    ~Node();

    Node *get_next();

    Node *get_prev();

    Type get_info();
};

template <class Type>
class DList {
private:
    Node<Type> *node = nullptr;

public:
    ~DList();

    Node<Type> *get_node();

    bool is_empty();

    void add_to_head(Type info);

    void add_to_tail(Type info);

    void add_after(Node<Type> *&after, Type info);

    void remove(Node<Type> *&del_el);

    void print();
};
