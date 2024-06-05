#include "DescriptionList.h"

DescriptionList::DescriptionList() {
  description = "";
}

DescriptionList::~DescriptionList() {}

void DescriptionList::setDescription(string description) {
  this->description = description;
}

string DescriptionList::getDescription() const {
  return description;
}