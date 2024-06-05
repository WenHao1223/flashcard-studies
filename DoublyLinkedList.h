#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class DoublyLinkedList {
  private:
    struct Node {
      string data;
      Node* next;
      Node* prev;
    };
    Node* head;
    Node* tail;
  public:
    DoublyLinkedList();

    void editNode(string data);
    void searchNode(string data) const;

    void deleteNode(string data);

    ~DoublyLinkedList();

    void insertNode(string data);
    
    void displayList() const;
    // void displayListOneByOne() const;
};

#endif