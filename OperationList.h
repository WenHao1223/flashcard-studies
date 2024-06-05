#ifndef OPERATION_LIST_H
#define OPERATION_LIST_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"

class OperationList : public DoublyLinkedList <string> {
  private:
    string operation;
  public:
    // constructor
    OperationList();
    // destructor
    ~OperationList();

    // mutator
    void setOperation(string operation);
    // accessor
    string getOperation() const;
};

#endif