#include "DoublyLinkedList.h"

template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
}

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::editNode(T1 question, T2 data) {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      temp->data = data;
      return;
    }
    temp = temp->next;
  }
  cout << "Data not found." << endl;
}

template <class T1, class T2>
int DoublyLinkedList<T1, T2>::searchQuestionNode(T1 question) const {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      cout << "Question found: " << temp->question << endl;
      return 1;
    }
    temp = temp->next;
  }
  cout << "Question not found." << endl;
  return -1;
}

template <class T1, class T2>
int DoublyLinkedList<T1, T2>::searchNode(T2 data) const {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->data == data) {
      cout << "Data found: " << temp->data << " in " << temp->question << endl;
      return 1;
    }
    temp = temp->next;
  }
  cout << "Data not found." << endl;
  return -1;
}

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::deleteQuestionNode(T1 question) {
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

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::deleteNode(T2 data) {
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

template <class T1, class T2>
DoublyLinkedList<T1, T2>::~DoublyLinkedList() {
  Node* temp = head;
  while (temp != nullptr) {
    Node* next = temp->next;
    delete temp;
    temp = next;
  }
}

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::insertNode(T1 question, T2 data) {
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

template <class T1, class T2>
void DoublyLinkedList<T1, T2>::displayList() const {
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->question << ": " << temp->data << endl;
    temp = temp->next;
  }

  if (head == nullptr) {
    cout << "List is empty." << endl;
  }
}

template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getNodeValue(T1 question) const {
  Node* temp = head;
  while (temp != nullptr) {
    if (temp->question == question) {
      return temp->data;
    }
    temp = temp->next;
  }
  return T2();
}

template class DoublyLinkedList <string, string>;
template class DoublyLinkedList <string, int>;
template class DoublyLinkedList <string, double>;