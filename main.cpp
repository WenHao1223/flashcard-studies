// Run the following command to compile the code:
// g++ *.cpp -o main && ./main

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"

int main () {
  // Case 1
  DoublyLinkedList <string> colorList;

  colorList.insertNode("Apple", "Red");
  colorList.insertNode("Banana", "Yellow");
  colorList.insertNode("Cherry", "Red");
  colorList.displayList();

  colorList.editNode("Cherry", "Pink");
  colorList.displayList();

  colorList.searchQuestionNode("Banana");
  colorList.searchNode("Yellow");
  
  colorList.deleteQuestionNode("Banana");
  colorList.deleteNode("Red");
  colorList.displayList();

  return 0;
}