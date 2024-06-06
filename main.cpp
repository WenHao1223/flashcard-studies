// Run the following command to compile the code:
// g++ *.cpp -o main && ./main
// g++ *.cpp -o main && main

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#include "DoublyLinkedList.h"
#include "FlashCard.h"

int main () {

  // Flash Card case
  // FlashCard <string, string, string, double, int> flashCard;

  // flashCard.insertNode("5 + 3 = ?", "What is 5 plus 3?", "addition", 8, 1);
  // flashCard.insertNode("5 - 3 = ?", "What is 5 minus 3?", "subtraction", 2, 2);
  // flashCard.insertNode("4 - 3 = ?", "What is 4 minus 3?", "subtraction", 1, 2);
  // flashCard.insertNode("5 * 3 = ?", "What is 5 times 3?", "multiplication", 15, 3);
  // flashCard.insertNode("8 * 3 = ?", "What is 5 times 3?", "multiplication", 24, 3);
  // flashCard.insertNode("5 / 3 = ?", "What is 5 divided by 3?", "division", 1.67, 4);

  // flashCard.displayAllFlashCard();

  // flashCard.displayQuestionList();

  // flashCard.editNode("5 + 3 = ?", "What is 5 plus 3?", "addition", 8, 5);
  // flashCard.displayAllFlashCard();

  // flashCard.searchQuestionNode("5 + 3 = ?");
  // flashCard.displayDataField("5 / 3 = ?", "Description");
  // cout << endl;
  // flashCard.searchDescription("What is 5 divided by 3?");
  // cout << endl;
  
  // flashCard.deleteQuestionNode("5 + 3 = ?");
  // flashCard.displayAllFlashCard();
  
  // flashCard.displayQuestionList();
  // flashCard.displayFlashCardNoAnswer("5 - 3 = ?");
  // flashCard.displayFlashCardWithAnswer("5 - 3 = ?");

  // flashCard.displayFlashCardOneByOne();

  bool terminate = false;
  do {
    // break;
    char choice;
    do {
      cout << "******************************************" << endl;
      cout << "   --- Welcome to Flashcard Studies ---   " << endl;
      cout << "******************************************" << endl;
      cout << "1. Load flashcard" << endl;
      cout << "2. Terminate program" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      cin.ignore();
    } while (choice != '1' && choice != '2');

    FlashCard <string, string, string, double, int> flashCard;
    string question, description, operation;
    double answer;
    int difficulty;

    switch (choice) {
      case '1': {

        ifstream file;
        string fileName;

        try {
          do {
            file.open("flashCard.txt");

            if(!file) {
              cout << "Error: File not found." << endl;
            }
          } while (!file);
        } catch (string const exceptionString) {
          cout << "Error: " << exceptionString << endl;
        }
        
        // 5 + 3 = ?	What is 5 plus 3?	addition	8	1
        while (!file.eof()) {
          getline(file, question, '\t');
          getline(file, description, '\t');
          getline(file, operation, '\t');
          file >> answer;
          file.ignore();
          file >> difficulty;
          file.ignore();

          flashCard.insertNode(question, description, operation, answer, difficulty);
        }
        file.close();

        bool exit = false;
        do {
          char menuChoice;
          do {
            cout << "\n*****************************************" << endl;
            cout << "   --- Flashcard Studies Menu ---   " << endl;
            cout << "******************************************" << endl;
            cout << "1. Display all flashcards" << endl;
            cout << "2. Display all flash card question" << endl;
            cout << "3. Display flash card one by one" << endl;
            cout << "4. Search for a flashcard" << endl;
            cout << "5. Add a flashcard" << endl;
            cout << "6. Edit a flashcard" << endl;
            cout << "7. Delete a flashcard" << endl;
            cout << "8. Exit / Load from different flash card file" << endl;
            cout << "Enter your choice: ";
            cin >> menuChoice;
            cin.ignore();
          } while (menuChoice != '1' && menuChoice != '2' && menuChoice != '3' && menuChoice != '4' && menuChoice != '5' && menuChoice != '6' && menuChoice != '7' && menuChoice != '8');

          switch (menuChoice) {
            case '1': {
              cout << "\nDisplaying all flashcards:"<<endl;
              flashCard.displayAllFlashCard();
              break;
            }
            case '2': {
              cout << "\nDisplaying all flash card questions:"<<endl;
              flashCard.displayQuestionList();
              break;
            }
            case '3': {
              cout << "\nDisplaying flashcards one by one:"<<endl;
              flashCard.displayFlashCardOneByOne();
              break;
            }
            case '4': {
              string search;
              char choice;
              do {
                cout << "1. Search by question" << endl;
                cout << "2. Search by description" << endl;
                cout << "3. Search by operation" << endl;
                cout << "4. Search by answer" << endl;
                cout << "5. Search by difficulty" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();
              } while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5');

              switch (choice) {
                case '1': {
                  flashCard.displayQuestionList();
                  cout << "Enter the question to search: ";
                  cin.ignore();
                  getline(cin, search);
                  flashCard.searchQuestionNode(search);
                  break;
                }
                case '2': {
                  cout << "Enter the description to search: ";
                  cin.ignore();
                  getline(cin, search);
                  flashCard.searchDescription(search);
                  break;
                }
                case '3': {
                  cout << "Enter the operation to search: ";
                  cin.ignore();
                  getline(cin, search);
                  flashCard.searchOperation(search);
                  break;
                }
                case '4': {
                  cout << "Enter the answer to search: ";
                  cin >> search;
                  flashCard.searchAnswer(stod(search));
                  break;
                }
                case '5': {
                  cout << "Enter the difficulty to search: ";
                  cin >> search;
                  flashCard.searchDifficulty(stoi(search));
                  break;
                }
              }
              break;
              }
            case '5': {
              int operationChoice;
              string choice;
              do{
                cout << "Enter the question: ";
                cin.ignore();
                getline(cin, question);
                cout << "Enter the description: ";
                getline(cin, description);

                do {
                  cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\nEnter the operation: ";
                  cin >> operationChoice;
                } while (operationChoice != 1 && operationChoice != 2 && operationChoice != 3 && operationChoice != 4);

                switch (operationChoice) {
                  case 1:
                    operation = "addition";
                    break;
                  case 2:
                    operation = "subtraction";
                    break;
                  case 3:
                    operation = "multiplication";
                    break;
                  case 4:
                    operation = "division";
                    break;
                }
                
                cout << "Enter the answer: ";
                cin >> answer;
                cout << "Enter the difficulty: ";
                cin >> difficulty;

                flashCard.insertNode(question, description, operation, answer, difficulty);
                cout << "Card added." << endl;
                flashCard.displayFlashCardWithAnswer(question);
                cout << "Do you want to add another card? (y/n): ";
                cin >> choice;
              } while(choice == "y" || choice == "Y");
              break;
            }
            case '6': {
              flashCard.displayQuestionList();

              string questionToEdit;
              cout << "Enter the question to edit: ";
              getline(cin, questionToEdit);

              // set the old card details
              flashCard.displayFlashCardWithAnswer(questionToEdit);

              description = flashCard.getDescritionValue(questionToEdit);
              operation = flashCard.getOperationValue(questionToEdit);
              answer = flashCard.getAnswerValue(questionToEdit);
              difficulty = flashCard.getDifficultyValue(questionToEdit);

              char fieldChoice;
              do {
                cout << "Which field to edit: " << endl;
                cout << "1. Description" << endl;
                cout << "2. Operation" << endl;
                cout << "3. Answer" << endl;
                cout << "4. Difficulty" << endl;
                cout << "Enter your choice: ";
                cin >> fieldChoice;
                cin.ignore();
              } while (fieldChoice != '1' && fieldChoice != '2' && fieldChoice != '3' && fieldChoice != '4');

              switch (fieldChoice) {
                case '1': {
                  cout << "Enter the new description: ";
                  getline(cin, description);
                  break;
                }
                case '2': {
                  cout << "Enter the new operation: ";
                  getline(cin, operation);
                  break;
                }
                case '3': {
                  cout << "Enter the new answer: ";
                  cin >> answer;
                  cin.ignore();
                  break;
                }
                case '4': {
                  cout << "Enter the new difficulty: ";
                  cin >> difficulty;
                  cin.ignore();
                  break;
                }
              }

              flashCard.editCard(questionToEdit, description, operation, answer, difficulty);

              break;
            }
            case '7': {
              flashCard.displayQuestionList();
              string questionToDel;
              cout << "Enter the question to delete: ";
              getline(cin, questionToDel);
              do {
                cout << "Are you sure you want to delete the card? (Y/N): ";
                cin >> choice;
              } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');
              if (choice == 'n' || choice == 'N') {
                cout << "Action cancelled." << endl;
                break;
              }
              flashCard.deleteQuestionNode(questionToDel);
              break;
            }
            case '8': {
              cout<<"Exiting to main menu...\n"<<endl;
              exit = true;
              break;
            }
          }
        } while (!exit);
        break;
      }
      case '2': {
        cout << "Terminating program..." << endl;
        terminate = true;
        cout << "Program terminated." << endl;
        break;
      }
    }
  } while (!terminate);

  return 0;
}