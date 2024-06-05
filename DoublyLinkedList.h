#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include <iostream>
#include <string>

using namespace std;

template <class T>
class DoublyLinkedList {
  private:
    struct Node {
      string question;
      T data;
      Node* next;
      Node* prev;
    };
    Node* head;
    Node* tail;
  public:
    DoublyLinkedList();

    void editNode(string question, T data);
    void searchQuestionNode(string question) const;
    void searchNode(T data) const;

    void deleteQuestionNode(string question);
    void deleteNode(T data);

    ~DoublyLinkedList();

    void insertNode(string question, T data);
    
    void displayList() const;
};

template class DoublyLinkedList <string>;
template class DoublyLinkedList <int>;
template class DoublyLinkedList <char>;
template class DoublyLinkedList <double>;
template class DoublyLinkedList <float>;

#endif