#ifndef DESCRIPTION_LIST_H
#define DESCRIPTION_LIST_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"

class StringList : public DoublyLinkedList <string> {
  private:
    string value;
  public:
    // constructor
    StringList();
    // destructor
    ~StringList();

    // mutator
    void setValue(string value);
    // accessor
    string getValue() const;
};

#endif