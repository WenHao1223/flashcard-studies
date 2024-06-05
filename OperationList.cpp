#include "OperationList.h"

OperationList::OperationList() {
  operation = "";
}

OperationList::~OperationList() {}

void OperationList::setOperation(string operation) {
  this->operation = operation;
}

string OperationList::getOperation() const {
  return operation;
}
