// Run the following command to compile the code:
// g++ *.cpp -o main && ./main
// g++ *.cpp -o main && main

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"
#include "FlashCard.h"

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
  // ValueList <string, string> descriptions;
  // ValueList <string, string> operations;

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
  // ValueList <string, string> answers;
  // answers.insertNode("5 + 3 = ?", "Eight");
  // answers.insertNode("5 - 3 = ?", "Two");
  // answers.insertNode("5 * 3 = ?", "Fifteen");
  // answers.insertNode("5 / 3 = ?", "One point six seven");

  // ValueList <string, double> numbers;
  // numbers.insertNode("5 + 3 = ?", 8);
  // numbers.insertNode("5 - 3 = ?", 2);
  // numbers.insertNode("5 * 3 = ?", 15);
  // numbers.insertNode("5 / 3 = ?", 1.67);
  // numbers.displayList();

  // Flash Card case
  FlashCard <string, string, string, double, int> flashCard;

  flashCard.insertNode("5 + 3 = ?", "What is 5 plus 3?", "addition", 8, 1);
  flashCard.insertNode("5 - 3 = ?", "What is 5 minus 3?", "subtraction", 2, 2);
  flashCard.insertNode("5 * 3 = ?", "What is 5 times 3?", "multiplication", 15, 3);
  flashCard.insertNode("5 / 3 = ?", "What is 5 divided by 3?", "division", 1.67, 4);

  flashCard.displayAllFlashCard();

  flashCard.editNode("5 + 3 = ?", "What is 5 plus 3?", "addition", 8, 5);
  flashCard.displayAllFlashCard();

  flashCard.searchQuestionNode("5 + 3 = ?");
  flashCard.searchNode("5 / 3 = ?", "description");
  
  flashCard.deleteQuestionNode("5 + 3 = ?");
  flashCard.displayAllFlashCard();
  
  flashCard.displayQuestionList();
  flashCard.displayFlashCard("5 - 3 = ?");

  // flashCard.displayFlashCardOneByOne();

  return 0;
}