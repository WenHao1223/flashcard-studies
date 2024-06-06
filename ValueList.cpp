#include "ValueList.h"

template <class T>
ValueList<T>::ValueList() {}

template <class T>
ValueList<T>::~ValueList() {}

template <class T>
void ValueList<T>::setValue(T answer) {
  this->value = value;
}

template <class T>
T ValueList<T>::getValue() const {
  return value;
}