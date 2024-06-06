#include "ValueList.h"

template <class T1, class T2>
ValueList<T1, T2>::ValueList() {}

template <class T1, class T2>
ValueList<T1, T2>::~ValueList() {}

template <class T1, class T2>
void ValueList<T1, T2>::setValue(T2 value) {
  this->value = value;
}

template <class T1, class T2>
T2 ValueList<T1, T2>::getValue() const {
  return value;
}