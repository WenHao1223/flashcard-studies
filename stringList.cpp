#include "StringList.h"

StringList::StringList() {
  value = "";
}

StringList::~StringList() {}

void StringList::setValue(string value) {
  this->value = value;
}

string StringList::getValue() const {
  return value;
}