#include"DList.h"

#include<iostream>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

template<class Type>
Node<Type>::Node(Type _info, Node<Type> *_prev, Node<Type> *_next) : info(_info), prev(_prev), next(_next) {}
template<class Type>
Node<Type>::~Node() {
    delete next;
}

template<class Type>
Node<Type> *Node<Type>::get_next() {
    return next;
}

template<class Type>
Node<Type> *Node<Type>::get_prev() {
    return prev;
}

template<class Type>
Type Node<Type>::get_info() {
    return info;
}

template<class Type>
DList<Type>::~DList() {
    delete node;
}

template<class Type>
Node<Type> *DList<Type>::get_node() {
    return node;
}

template<class Type>
bool DList<Type>::is_empty() {
    return node == nullptr;
}

template<class Type>
void DList<Type>::add_to_head(Type info) {
    node = new Node<Type>(info, nullptr, node);

    if (node->next) {
        node->next->prev = node;
    }
}

template<class Type>
void DList<Type>::add_to_tail(Type info) {
    if (!is_empty()) {
        Node <Type>*current = node;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new Node<Type>(info, current);
        current->next->prev = current;
    } else {
        add_to_head(info);
    }
}

template<class Type>
void DList<Type>::add_after(Node <Type>*&after, Type info) {
    if (after == nullptr) {
        return;
    }

    if (!is_empty()) {
        Node<Type> *current = node;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new Node<Type>(info, current, current->next);

        if (current->next->next) {
            current->next->next->prev = current->next;
        }
    }
}

template<class Type>
void DList<Type>::remove(Node<Type> *&del_el) {
    if (del_el == nullptr) {
        return;
    }

    if (node == del_el) {
        Node <Type>*temp = del_el->next;

        if (temp == nullptr) {
            delete node;
            node = nullptr;
        } else {
            del_el->next = nullptr;
            delete del_el;
            node = temp;
            node->prev = nullptr;
        }
    } else {
        Node <Type>*current = node;

        while (current && current->next != del_el) {
            current = current->next;
        }

        if (current != nullptr) {
            Node <Type>*temp = del_el->next;

            del_el->next = nullptr;
            del_el->prev = nullptr;
            delete del_el;

            current->next = temp;
            if (temp) {
                temp->prev = current;
            }
        }
    }
}

template<class Type>
void DList<Type>::print() {
    Node<Type> *current = node;

    while (current != nullptr) {
        cout << current->info << " ";
        current = current->next;
    }

    cout << "\n";
}