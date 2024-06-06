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

  // Flash Card case
  FlashCard <string, string, string, double, int> flashCard;

  flashCard.insertNode("5 + 3 = ?", "What is 5 plus 3?", "addition", 8, 1);
  flashCard.insertNode("5 - 3 = ?", "What is 5 minus 3?", "subtraction", 2, 2);
  flashCard.insertNode("4 - 3 = ?", "What is 4 minus 3?", "subtraction", 1, 2);
  flashCard.insertNode("5 * 3 = ?", "What is 5 times 3?", "multiplication", 15, 3);
  flashCard.insertNode("8 * 3 = ?", "What is 5 times 3?", "multiplication", 24, 3);
  flashCard.insertNode("5 / 3 = ?", "What is 5 divided by 3?", "division", 1.67, 4);

  // flashCard.displayAllFlashCard();

  // flashCard.displayQuestionList();

  // flashCard.editNode("5 + 3 = ?", "What is 5 plus 3?", "addition", 8, 5);
  // flashCard.displayAllFlashCard();

  // flashCard.searchQuestionNode("5 + 3 = ?");
  flashCard.displayDataField("5 / 3 = ?", "Description");
  cout << endl;
  flashCard.searchDescription("What is 5 divided by 3?");
  cout << endl;
  
  // flashCard.deleteQuestionNode("5 + 3 = ?");
  // flashCard.displayAllFlashCard();
  
  // flashCard.displayQuestionList();
  // flashCard.displayFlashCardNoAnswer("5 - 3 = ?");
  // flashCard.displayFlashCardWithAnswer("5 - 3 = ?");

  flashCard.displayFlashCardOneByOne();

  return 0;
}