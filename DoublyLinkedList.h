#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <class T>
class DoublyLinkedList {
  private:
    struct Node {
      T data;
      Node* next;
      Node* prev;
    };
    Node* head;
    Node* tail;
  public:
    DoublyLinkedList();

    void editNode(T data);
    void searchNode(T data) const;

    void deleteNode(T data);

    ~DoublyLinkedList();

    void insertNode(T data);
    
    void displayList() const;
    // void displayListOneByOne() const;
};

template class DoublyLinkedList <string>;
template class DoublyLinkedList <int>;
template class DoublyLinkedList <char>;
template class DoublyLinkedList <double>;
template class DoublyLinkedList <float>;

#endif