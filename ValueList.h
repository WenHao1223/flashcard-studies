#ifndef VALUE_LIST_H
#define VALUE_LIST_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"

template <class T>
class ValueList : public DoublyLinkedList <T> {
  private:
    T value;
  public:
    // constructor
    ValueList();
    // destructor
    ~ValueList();

    // mutator
    void setValue(T answer);
    // accessor
    T getValue() const;
};

template class ValueList <string>;
template class ValueList <int>;
template class ValueList <double>;

#endif