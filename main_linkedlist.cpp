#include <iostream>

#include "LinkedList.hpp"

int main() {
    LinkedList<int> llist;

    llist.printAllNodes();



    llist.insertAtTheFront(1);
    llist.insertAtTheEnd(2);
    llist.insertAtTheEnd(3);
    llist.insertAtTheEnd(4);
    llist.insertAtTheEnd(5);
    llist.insertAtTheEnd(6);
    llist.insertAtTheEnd(7);
    llist.insertAtTheEnd(8);

    llist.printAllNodes();
    llist.printReversed();

    llist.removeAllNodes();

    llist.printAllNodes();

    return 0;
}