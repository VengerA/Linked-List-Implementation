#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList
{
    public: // DO NOT CHANGE THIS PART.
        LinkedList();
        LinkedList(const LinkedList &obj);

        ~LinkedList();

        Node<T> *getFirstNode() const; //
        Node<T> *getHead() const;
        Node<T> *getTail() const;
        int getNumberOfNodes();
        bool isEmpty(); //

        void insertAtTheFront(const T &data); //
        void insertAtTheEnd(const T &data); //
        void insertAfterGivenNode(const T &data, Node<T> *prev); //

        void removeNode(Node<T> *node);
        void removeAllNodes();

        Node<T> *findNode(const T &data); //

        void printAllNodes();
        void printReversed();

        LinkedList &operator=(const LinkedList &rhs);

    private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

    private: // DO NOT CHANGE THIS PART.
        Node<T> *head;
        Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    Node<T> *dummy_head = new Node<T>();
    Node<T> *dummy_tail = new Node<T>();
    head = dummy_head;
    tail = dummy_tail;
    head->next = tail; 
    tail->prev = head;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    /* TODO */
    Node<T> *current = obj.head->next;
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    tail->prev = head;

    while(current->next){
        insertAtTheEnd(current->element);
        current = current->next;
    }
}

// BSTNode<T> *min = NULL;
//     BSTNode<T> *newCurrent = NULL;
//     if(current->data == data){
//         if(current->right){
//             newCurrent = current->right;
//             while(newCurrent->left){
//                 newCurrent = newCurrent->left;
//             }
//             min = newCurrent; 

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    removeAllNodes();
    delete head; 
    delete tail;
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if(head->next == tail){
        return NULL;
    }
    return head->next;
}

template<class T>
Node<T> * LinkedList<T>::getHead() const
{
    /* TODO */
    return head;
}

template<class T>
Node<T> * LinkedList<T>::getTail() const
{
    /* TODO */
    return tail;
}

template<class T>
int LinkedList<T>::getNumberOfNodes() 
{
    /* TODO */
    int i = 0; 
    Node<T> *current = head;
    while(current->next){
        i++;
        current = current->next;
    }

    return i-1;
    
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    /* TODO */
    if(head->next == tail){
        return true; 
    }
    return false;
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data)
{
    /* TODO */
    Node <T> *New = new Node<T>();
    Node <T> *oldFirst = head->next;
    New->element = data; 
    New->prev = head; 
    New->next = oldFirst; 
    head->next = New;
    oldFirst->prev = New; 

}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data)
{
    /* TODO */
    Node<T> *new_node = new Node<T> ();
    if(head->next == tail){
        new_node->element = data; 
        new_node->next = tail;
        new_node->prev = head;
        head->next = new_node;
        tail->prev = new_node;
    }
    else{
        Node<T> *last_node= tail->prev; 
        new_node->element = data; 
        new_node->next = tail;
        new_node->prev = last_node;
        last_node->next = new_node;
        tail->prev = new_node; 
    }
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev)
{   
    /* TODO */
    Node<T> *new_node = new Node<T>(data, prev, prev->next);
    prev->next->prev = new_node;
    prev->next = new_node;
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    Node<T> *current = head->next;
    while(current->next){
        if(current == node){
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current; 
            break;
        }
        else {
            current = current->next;
        }
    }
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    Node<T> *current = head->next; 
    while(current->next){
        current = current->next;
        delete current->prev;
    }
    head->next = tail;
    tail->prev = head;
}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data)
{
    /* TODO */
    Node<T> *current = head->next; 
    while(current->next){
        if(current->element == data){
            return current; 
            break;
        }
        else {
            current = current->next;
        }
    }
    return NULL;
}

template<class T>
void LinkedList<T>::printAllNodes()
{
    /* TODO */
    Node<T> *current = head->next; 
    while(current->next){
        std::cout << current->element <<  std::endl;
        current = current->next; 
    }
}

template<class T>
void LinkedList<T>::printReversed()
{
    /* TODO */
    Node <T> *current = tail->prev; 
    while(current->prev){
        std::cout << current->element << std::endl;
        current = current->prev;
    }
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs)
{
    /* TODO */
    removeAllNodes();
    Node<T> *copyNode = rhs.head->next;
    while(copyNode->next){
        insertAtTheEnd(copyNode->element);
        copyNode = copyNode->next;
    }
    return *this;
    
}

#endif //LINKED_LIST_HPP
