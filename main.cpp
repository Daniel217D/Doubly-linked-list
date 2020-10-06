#include <iostream>

#include "libraries/DList.h"

using std::cout;
using std::ostream;

class SNode {
public:
    int value;

    friend std::ostream& operator<< (std::ostream& stream, const SNode& matrix) {
        stream << matrix.value;
        return stream;
    }
};



int main() {
    auto *list = new DList<SNode>;

    SNode node{};
    node.value = 1;


    list->add_to_head(node);
    node.value = 2;
    list->add_to_head(node);
    node.value = 3;
    list->add_to_head(node);
    list->print();

    node.value = 4;
    list->add_to_tail(node);
    node.value = 5;
    list->add_to_tail(node);
    node.value = 6;
    list->add_to_tail(node);
    list->print();

    Node<SNode> *n = list->get_node()->get_next()->get_next();
    node.value = 7;
    list->add_after(n, node);
    list->print();

    delete list;
    return 0;
}
