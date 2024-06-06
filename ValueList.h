#ifndef VALUE_LIST_H
#define VALUE_LIST_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"

template <class T1, class T2>
class ValueList : public DoublyLinkedList <T1, T2> {
  private:
    T2 value;
  public:
    // constructor
    ValueList();
    // destructor
    ~ValueList();

    // mutator
    void setValue(T2 value);
    // accessor
    T2 getValue() const;
};

#endif