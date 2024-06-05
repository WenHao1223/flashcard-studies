#include "DoublyLinkedList.h"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
}

template <class T>
void DoublyLinkedList<T>::editNode(T data) {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->data == data) {
      cout << "Enter new data: ";
      cin >> temp->data;
      return;
    }
    temp = temp->next;
  }
  cout << "Data not found." << endl;
}

template <class T>
void DoublyLinkedList<T>::searchNode(T data) const {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->data == data) {
      cout << "Data found." << endl;
      return;
    }
    temp = temp->next;
  }
  cout << "Data not found." << endl;
}

template <class T>
void DoublyLinkedList<T>::deleteNode(T data) {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->data == data) {
      if (temp == head) {
        head = temp->next;
        head->prev = nullptr;
        delete temp;
        return;
      } else if (temp == tail) {
        tail = temp->prev;
        tail->next = nullptr;
        delete temp;
        return;
      } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        return;
      }
    }
    temp = temp->next;
  }
  cout << "Data not found." << endl;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  Node* temp = head;
  while (temp != nullptr) {
    Node* next = temp->next;
    delete temp;
    temp = next;
  }
}

template <class T>
void DoublyLinkedList<T>::insertNode(T data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

template <class T>
void DoublyLinkedList<T>::displayList() const {
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->data << endl;
    temp = temp->next;
  }
}

// @WenHao1223 do in composition
// void DoublyLinkedList<T>::displayListOneByOne() const {
//   Node* temp = tail;
//   while (temp != nullptr) {
//     cout << temp->data << endl;
//     temp = temp->prev;
//   }
// }