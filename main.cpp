// Run the following command to compile the code:
// g++ *.cpp -o main && ./main

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"
#include "DescriptionList.h"
#include "OperationList.h"
#include "AnswerList.h"

int main () {
  // Case 1
  // DoublyLinkedList <string> colorList;

  // colorList.insertNode("Apple", "Red");
  // colorList.insertNode("Banana", "Yellow");
  // colorList.insertNode("Cherry", "Red");
  // colorList.displayList();

  // colorList.editNode("Cherry", "Pink");
  // colorList.displayList();

  // colorList.searchQuestionNode("Banana");
  // colorList.searchNode("Yellow");
  
  // colorList.deleteQuestionNode("Banana");
  // colorList.deleteNode("Red");
  // colorList.displayList();

  // Case 2
  // DescriptionList descriptions;
  // OperationList operations;

  // descriptions.insertNode("5 + 3 = ?", "What is 5 plus 3?");
  // operations.insertNode("5 + 3 = ?", "addition");

  // descriptions.insertNode("5 - 3 = ?", "What is 5 minus 3?");
  // operations.insertNode("5 - 3 = ?", "subtraction");
  // descriptions.insertNode("5 * 3 = ?", "What is 5 times 3?");
  // operations.insertNode("5 * 3 = ?", "multiplication");
  // descriptions.insertNode("5 / 3 = ?", "What is 5 divided by 3?");
  // operations.insertNode("5 / 3 = ?", "division");
  // descriptions.displayList();

  // descriptions.deleteQuestionNode("5 + 3 = ?");
  // operations.deleteNode("5 + 3 = ?");
  // descriptions.deleteNode("What is 5 minus 3?");
  // operations.deleteQuestionNode("5 - 3 = ?");
  // descriptions.displayList();
  // operations.displayList();

  // descriptions.editNode("5 * 3 = ?", "What is 5 multiply 3?");
  // operations.editNode("5 * 3 = ?", "times");

  // descriptions.searchQuestionNode("5 * 3 = ?");
  // operations.searchQuestionNode("5 * 3 = ?");
  // descriptions.searchNode("What is 5 multiply 3?");
  // operations.searchNode("times");

  // Case 3
  AnswerList <string> answers;
  answers.insertNode("5 + 3 = ?", "Eight");
  answers.insertNode("5 - 3 = ?", "Two");
  answers.insertNode("5 * 3 = ?", "Fifteen");
  answers.insertNode("5 / 3 = ?", "One point six seven");

  AnswerList <double> numbers;
  numbers.insertNode("5 + 3 = ?", 8);
  numbers.insertNode("5 - 3 = ?", 2);
  numbers.insertNode("5 * 3 = ?", 15);
  numbers.insertNode("5 / 3 = ?", 1.67);
  numbers.displayList();

  return 0;
}