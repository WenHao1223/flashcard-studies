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
#include "Score.h"

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
    } while (choice < '1' || choice > '2');

    Score <string, string, string, double, int> flashCardScoring;
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

          flashCardScoring.insertNode(question, description, operation, answer, difficulty);
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
            cout << "8. Play flashcard game" << endl;
            cout << "9. Exit / Load from different flash card file" << endl;
            cout << "Enter your choice: ";
            cin >> menuChoice;
            cin.ignore();
          } while (menuChoice < '1' || menuChoice > '9');

          switch (menuChoice) {
            case '1': {
              cout << "\nDisplaying all flashcards:"<<endl;
              flashCardScoring.displayAllFlashCard();
              break;
            }
            case '2': {
              cout << "\nDisplaying all flash card questions:"<<endl;
              flashCardScoring.displayQuestionList();
              break;
            }
            case '3': {
              cout << "\nDisplaying flashcards one by one:"<<endl;
              flashCardScoring.displayFlashCardOneByOne();
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
              } while (choice < '1' || choice > '5');

              switch (choice) {
                case '1': {
                  flashCardScoring.displayQuestionList();
                  cout << "Enter the question to search: ";
                  getline(cin, search);
                  flashCardScoring.searchQuestionNode(search);
                  break;
                }
                case '2': {
                  cout << "Enter the description to search: ";
                  getline(cin, search);
                  flashCardScoring.searchDescription(search);
                  break;
                }
                case '3': {
                  cout << "Enter the operation to search: ";
                  getline(cin, search);
                  flashCardScoring.searchOperation(search);
                  break;
                }
                case '4': {
                  cout << "Enter the answer to search: ";
                  cin >> search;
                  cin.ignore();
                  flashCardScoring.searchAnswer(stod(search));
                  break;
                }
                case '5': {
                  cout << "Enter the difficulty to search: ";
                  cin >> search;
                  cin.ignore();
                  flashCardScoring.searchDifficulty(stoi(search));
                  break;
                }
              }
              break;
              }
            case '5': {
              char operationChoice;
              string choice;
              do{
                cout << "Enter the question: ";
                getline(cin, question);
                cout << "Enter the description: ";
                getline(cin, description);

                do {
                  cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\nEnter the operation: ";
                  cin >> operationChoice;
                } while (operationChoice < '1' || operationChoice > '4');

                switch (operationChoice) {
                  case '1':
                    operation = "addition";
                    break;
                  case '2':
                    operation = "subtraction";
                    break;
                  case '3':
                    operation = "multiplication";
                    break;
                  case '4':
                    operation = "division";
                    break;
                }
                
                cout << "Enter the answer: ";
                cin >> answer;
                cin.ignore();
                cout << "Enter the difficulty: ";
                cin >> difficulty;
                cin.ignore();

                flashCardScoring.insertNode(question, description, operation, answer, difficulty);
                cout << "Card added." << endl;
                flashCardScoring.displayFlashCardWithAnswer(question);
                cout << "Do you want to add another card? (Y/N): ";
                cin >> choice;
                cin.ignore();
              } while(choice == "y" || choice == "Y");
              break;
            }
            case '6': {
              flashCardScoring.displayQuestionList();

              string questionToEdit;
              cout << "Enter the question to edit: ";
              getline(cin, questionToEdit);

              // set the old card details
              flashCardScoring.displayFlashCardWithAnswer(questionToEdit);

              description = flashCardScoring.getDescritionValue(questionToEdit);
              operation = flashCardScoring.getOperationValue(questionToEdit);
              answer = flashCardScoring.getAnswerValue(questionToEdit);
              difficulty = flashCardScoring.getDifficultyValue(questionToEdit);

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
              } while (fieldChoice < '1' || fieldChoice > '4');

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

              flashCardScoring.editCard(questionToEdit, description, operation, answer, difficulty);

              break;
            }
            case '7': {
              flashCardScoring.displayQuestionList();
              string questionToDel;
              cout << "Enter the question to delete: ";
              getline(cin, questionToDel);
              do {
                cout << "Are you sure you want to delete the card? (Y/N): ";
                cin >> choice;
                cin.ignore();
              } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');
              if (choice == 'n' || choice == 'N') {
                cout << "Action cancelled." << endl;
                break;
              }
              flashCardScoring.deleteQuestionNode(questionToDel);
              break;
            }
            case '8': {
              string name;
              int age;

              do {
                cout << "Enter your name: ";
                getline(cin, name);
              } while (name == "");

              do {
                cout << "Enter your age: ";
                cin >> age;
                cin.ignore();
              } while (age < 1);

              flashCardScoring.setName(name);
              flashCardScoring.setAge(age);

              int numQuestions;
              do {
                cout << "How many questions do you want to answer? ";
                cin >> numQuestions;
                cin.ignore();
              } while (numQuestions < 1);
              for (int i = 0; i < numQuestions; i++) {
                question = flashCardScoring.displayRandomFlashCard();

                cout << "Enter your answer: ";
                cin >> answer;
                cin.ignore();
                flashCardScoring.updateScore(question, answer);
              }
              flashCardScoring.displayScore();
              break;
            }
            case '9': {
              cout<<"Exiting to main menu...\n"<<endl;
              exit = true;
              break;
            }
          }
        } while (!exit);
        break;
      }
      case '2': {
        char choice;
        do {
          cout << "Are you sure you want to terminate the program? (Y/N): ";
          cin >> choice;
          cin.ignore();
        } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

        if (choice == 'n' || choice == 'N') {
          cout << "Action cancelled." << endl;
          break;
        }
        
        cout << "Terminating program..." << endl;
        terminate = true;
        cout << "Program terminated." << endl;
        break;
      }
    }
  } while (!terminate);

  return 0;
}