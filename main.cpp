// Run the following command to compile the code:
// g++ *.cpp -o main && ./main

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"

int main () {
  DoublyLinkedList list;

  list.insertNode("Apple");
  list.insertNode("Banana");
  list.insertNode("Cherry");

  list.displayList();
  list.editNode("Banana");
  list.displayList();
  list.searchNode("Banana");
  list.deleteNode("Banana");
  list.displayList();

  return 0;
}