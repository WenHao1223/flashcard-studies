#ifndef DESCRIPTION_LIST_H
#define DESCRIPTION_LIST_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"

class DescriptionList : public DoublyLinkedList <string> {
  private:
    string description;
  public:
    // constructor
    DescriptionList();
    // destructor
    ~DescriptionList();

    // mutator
    void setDescription(string description);
    // accessor
    string getDescription() const;
};

#endif