#include "DoublyLinkedList.h"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
}

template <class T>
void DoublyLinkedList<T>::editNode(string question, T data) {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      temp->data = data;
      cout << "Edited data of " << temp->question << ": " << temp->data << endl;
      return;
    }
    temp = temp->next;
  }
  cout << "Data not found." << endl;
}

template <class T>
void DoublyLinkedList<T>::searchQuestionNode(string question) const {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      cout << "Question found: " << temp->question << endl;
      return;
    }
    temp = temp->next;
  }
  cout << "Question not found." << endl;
}

template <class T>
void DoublyLinkedList<T>::searchNode(T data) const {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->data == data) {
      cout << "Data found: " << temp->data << " in " << temp->question << endl;
      return;
    }
    temp = temp->next;
  }
  cout << "Data not found." << endl;
}

template <class T>
void DoublyLinkedList<T>::deleteQuestionNode(string question) {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      if (temp == head) {
        head = temp->next;
        head->prev = nullptr;
        cout << "Question " << question << " deleted." << endl;
        delete temp;
        return;
      } else if (temp == tail) {
        tail = temp->prev;
        tail->next = nullptr;
        cout << "Question " << question << " deleted." << endl;
        delete temp;
        return;
      } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << "Question " << question << " deleted." << endl;
        delete temp;
        return;
      }
    }
    temp = temp->next;
  }
  cout << "Question not found." << endl;
}

template <class T>
void DoublyLinkedList<T>::deleteNode(T data) {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->data == data) {
      if (temp == head) {
        head = temp->next;
        head->prev = nullptr;
        cout << "Data " << data << " deleted." << endl;
        delete temp;
        return;
      } else if (temp == tail) {
        tail = temp->prev;
        tail->next = nullptr;
        cout << "Data " << data << " deleted." << endl;
        delete temp;
        return;
      } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout << "Data " << data << " deleted." << endl;
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
void DoublyLinkedList<T>::insertNode(string question, T data) {
  Node* newNode = new Node;
  newNode->question = question;
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

  cout << "Data inserted to " << question << ": " << data << endl;
}

template <class T>
void DoublyLinkedList<T>::displayList() const {
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->question << ": " << temp->data << endl;
    temp = temp->next;
  }
}