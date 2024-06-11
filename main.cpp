// Run the following command to compile the code:
// g++ *.cpp -o main && ./main
// g++ *.cpp -o main && main
// g++ main.cpp DoublyLinkedList.cpp FlashCard.cpp Score.cpp -o main & ./main
// g++ main.cpp DoublyLinkedList.cpp FlashCard.cpp Score.cpp -o main & main

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

#include "DoublyLinkedList.h"
#include "FlashCard.h"
#include "Score.h"

template <class U1, class U2, class U3, class U4, class U5>
double averageDifficulty(const FlashCard<U1, U2, U3, U4, U5> & card) {
  double sum = 0;
  U1 currentQuestion = card.questions.getHeadValue();
  sum += card.difficulties.getNodeValue(currentQuestion);
  do {
    currentQuestion = card.questions.getNextNodeValue(currentQuestion);
    sum += card.difficulties.getNodeValue(currentQuestion);
  } while (currentQuestion != card.questions.getTailValue());

  return sum / card.questions.getNumberOfNodes();
}

template <class U1, class U2, class U3, class U4, class U5>
int numberOfQuestions(const FlashCard<U1, U2, U3, U4, U5> & card) {
  return card.questions.getNumberOfNodes();
}

int main () {
  bool terminate = false;
  do {
    Score <string, string, string, double, int> flashCardScoring;
    string question, description, operation;
    double answer;
    int difficulty;

    fstream file;
    string fileName = "flashCard.txt";
    
    try {
      flashCardScoring.initialize(fileName);
    } catch (const char* error) {
      cout << "Error: " << error << endl;
      break;
    }

    bool exit = false;
    char menuChoice;
    do {
      cout << "*****************************************" << endl;
      cout << "   --- Flashcard Studies Menu ---   " << endl;
      cout << "******************************************" << endl;
      cout << "1. Display flashcards" << endl;
      cout << "2. Search for a flashcard" << endl;
      cout << "3. Manage flashcard" << endl;
      cout << "4. Play flashcard game" << endl;
      cout << "5. Terminate program" << endl;
      cout << "Enter your choice: ";
      cin >> menuChoice;
      cin.ignore();
    } while (menuChoice < '1' || menuChoice > '5');

    switch (menuChoice) {
      case '1': {
        cout << "\nDisplaying flashcard menu..."<<endl;
        char displayChoice;
        char choice;
        bool mainMenu = false;
        do {
          do {
            cout << "+---------------------------------+" << endl;
            cout << "1. Display all flashcard" << endl;
            cout << "2. Display all flashcard questions" << endl;
            cout << "3. Display flashcard one by one" << endl;
            cout << "4. Back to main menu" << endl;
            cout << "+---------------------------------+\n";
            cout << "Enter your choice: ";
            cin >> displayChoice;
            cin.ignore();
            if (displayChoice < '1' || displayChoice > '4') {
              cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            }
          } while (displayChoice < '1' || displayChoice > '4');

          switch (displayChoice) {
            case '1': {
              cout << "\nDisplaying all flashcards..."<<endl;
              flashCardScoring.displayAllFlashCard();
              break;
            }
            case '2': {
              cout << "\nDisplaying all flashcard questions..."<<endl;
              flashCardScoring.displayQuestionList();
              break;
            }
            case '3': {
              cout << "\nDisplaying flashcards one by one..."<<endl;
              flashCardScoring.displayFlashCardOneByOne();
              break;
            }
            case '4': {
              char choice;
              do {
                cout << "Are you sure you want to go back to the main menu? (Y/N): ";
                cin >> choice;
                if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                  cout << "Invalid input. Please enter Y or N." << endl;
                }
              } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

              if (choice == 'n' || choice == 'N') {
                cout << "Action cancelled." << endl;
                break;
              }

              mainMenu = true;

              cout << "Back to main menu..." << endl;
              break;
            }
          }

          if (!mainMenu && displayChoice != '4') {
            cout << "Would you like to remain in the flashcard sub-menu? (Y/N): ";
            cin >> choice;
            cout << "\n";

            if (choice == 'n' || choice == 'N') {
              mainMenu = true;
            }
          }
        } while (choice == 'y' || choice == 'Y' || !mainMenu);
        break;
      }
      case '2': {
        cout << "Searching for a flashcard..." << endl;
        string search;
        char searchChoice;
        char choice;
        bool searchMenu = true;

        while (searchMenu) {
          bool backToSearchMenu = false;
          do {
            cout << "+---------------------------------+" << endl;
            cout << "1. Search by question" << endl;
            cout << "2. Search by description" << endl;
            cout << "3. Search by operation" << endl;
            cout << "4. Search by answer" << endl;
            cout << "5. Search by difficulty" << endl;
            cout << "6. Back to main menu" << endl;
            cout << "+---------------------------------+\n";
            cout << "Enter your choice: ";
            cin >> searchChoice;
            cin.ignore();
            if (searchChoice < '1' || searchChoice > '6') {
              cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            }
          } while (searchChoice < '1' || searchChoice > '6');

          if (searchChoice == '6') {
            do {
              cout << "Are you sure you want to go back to the main menu? (Y/N): ";
              cin >> choice;
              if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                cout << "Invalid input. Please enter Y or N." << endl;
              }
            } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

            if (choice == 'n' || choice == 'N') {
              cout << "Action cancelled." << endl;
              break;
            }

            cout << "Back to main menu..." << endl;
            searchMenu = false;
            break;
          }

          switch (searchChoice) {
            case '1': {
              flashCardScoring.displayQuestionList();
              do {
                cout << "eg. 5 + 3 = ?\n";
                cout << "Press 0 to go back to search menu...\n";
                cout << "Enter the question to search: ";
                getline(cin, search);

                if (search == "0") {
                  backToSearchMenu = true;
                  break;
                }

              } while (search == "" || !flashCardScoring.searchQuestionNode(search));
              break;
            }
            case '2': {
              do {
                cout << "eg. What is 5 plus 3?\n";
                cout << "Press 0 to go back to search menu...\n";
                cout << "Enter the description to search: ";
                getline(cin, search);

                if (search == "0") {
                  backToSearchMenu = true;
                  break;
                }

              } while (search == "" || !flashCardScoring.searchDescription(search));
              break;
            }
            case '3': {
              char operationChar;
              bool backToSearchMenu = false;
              do {
                cout << "\n+---------------------------------+\n";
                cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Back to search menu\n";
                cout << "+---------------------------------+\n";
                cout << "Enter the operation to search (1 - 5): ";
                cin >> operationChar;
                cin.ignore();
                if (operationChar < '1' || operationChar > '5') {
                  cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                }
              } while (operationChar < '1' || operationChar > '5');

              if (operationChar == '5') {
                char choice;
                do {
                  cout << "Are you sure you want to go back to the search menu? (Y/N): ";
                  cin >> choice;
                  if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                    cout << "Invalid input. Please enter Y or N." << endl;
                  }
                } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');
                
                if (choice == 'n' || choice == 'N') {
                  cout << "Action cancelled." << endl;
                  continue;
                }

                cout << "Back to search menu..." << endl;
                backToSearchMenu = true;
              }

              if (backToSearchMenu) {
                continue;
              }

              switch (operationChar) {
                case '1':
                  search = "addition";
                  break;
                case '2':
                  search = "subtraction";
                  break;
                case '3':
                  search = "multiplication";
                  break;
                case '4':
                  search = "division";
                  break;
              }

              try {
                if (flashCardScoring.searchOperation(search) == -1) {
                  throw "Operation not found.";
                }
              } catch (const char* error) {
                cout << "Error: " << error << endl;
              }
              
              break;
            }
            case '4': {
              double searchAns;
              cout << "Press 0 to go back to search menu...\n";
              cout << "Enter the answer to search: ";
              do {
                cin >> searchAns;
                cin.ignore();

                if(cin.fail()) {
                  cin.clear();
                  cin.ignore(10000, '\n');
                  cout << "Invalid input. Please enter a number." << endl;
                  cout << "Enter the answer to search: ";
                  cin >> searchAns;
                  cin.ignore();
                }
              } while (cin.fail());

              if(searchAns == 0) {
                backToSearchMenu = true;
                break;
              }

              try {
                if (flashCardScoring.searchAnswer(searchAns) == -1) {
                  throw "Answer not found.";
                }
              } catch (const char* error) {
                cout << "Error: " << error << endl;
              }
              break;
            }
            case '5': {
              char difficultyChar;
              do {
                cout << "Press 0 to go back to search menu...\n";
                cout << "Enter the difficulty to search (1 - 5): ";
                cin >> difficultyChar;
                cin.ignore();

                if (difficultyChar == '0') {
                  backToSearchMenu = true;
                  break;
                }

                if (difficultyChar < '1' || difficultyChar > '5') {
                  cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                }
              } while (difficultyChar < '1' || difficultyChar > '5');

              difficulty = difficultyChar - '0';

              try {
                if (flashCardScoring.searchDifficulty(difficulty) == -1) {
                  throw "Difficulty not found.";
                }
              } catch (const char* error) {
                cout << "Error: " << error << endl;
              }
              break;
            }
          }

          if (backToSearchMenu) {
            continue;
          }

          cout << "Do you want to search another flashcard? (Y/N): ";
          cin >> choice;
          if (choice == 'n' || choice == 'N') {
            searchMenu = false;
          }
        }
        break;
      }
      case '3': {
        char manageChoice;
        bool manageMenu = true;
          
          while (manageMenu) {
            bool backToManageMenu = false;
            do {
              cout << "Managing flashcard menu..." << endl;
              cout << "+---------------------------------+" << endl;
              cout << "1. Add a flashcard" << endl;
              cout << "2. Edit a flashcard" << endl;
              cout << "3. Delete a flashcard" << endl;
              cout << "4. Back to main menu" << endl;
              cout << "+---------------------------------+\n";
              cout << "Enter your choice: ";
              cin >> manageChoice;
              cin.ignore();
              if (manageChoice < '1' || manageChoice > '4') {
                cout << "Invalid input. Please enter a number between 1 and 4." << endl;
              }
            } while (manageChoice < '1' || manageChoice > '4');
            
            if (manageChoice == '4') {
              char choice;
              do {
                cout << "Are you sure you want to go back to the main menu? (Y/N): ";
                cin >> choice;
                if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                  cout << "Invalid input. Please enter Y or N." << endl;
                }
              } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

              if (choice == 'n' || choice == 'N') {
                cout << "Action cancelled." << endl;
                break;
              } 
              
              cout << "Back to main menu..." << endl;
              manageMenu = false;
              break;

            }

            switch (manageChoice) {
              case '1': {
                cout << "Adding a flashcard..." << endl;
                char operationChoice;
                char choice;
                do{
                  backToManageMenu = false;
                  do {
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the question: ";
                    getline(cin, question);
                    
                    if (question == "0") {
                      backToManageMenu = true;
                      break;
                    }

                  } while (question == "");

                  if (backToManageMenu) {
                    break;
                  }

                  try {
                    if (flashCardScoring.searchQuestionNode(question) != -1) {
                      throw "Question already exists.";
                    } else {
                      cout << "Question does not exist. You are good to go." << endl;
                    }
                  } catch (const char* error) {
                    cout << "Error: " << error << endl;
                    break;
                  }

                  do {
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the description: ";
                    getline(cin, description);

                    if (description == "0") {
                      backToManageMenu = true;
                      break;
                    }

                  } while (description == "");

                  if (backToManageMenu) {
                    break;
                  }

                  do {
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\nEnter the operation (1 - 4): ";
                    cin >> operationChoice;

                    if (operationChoice == '0') {
                      backToManageMenu = true;
                      break;
                    }

                  } while (operationChoice < '1' || operationChoice > '4');

                  if (backToManageMenu) {
                    break;
                  }

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

                  do {
                    if(cin.fail()) {
                      cin.clear();
                      cin.ignore(10000, '\n');
                    }
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the answer: ";
                    cin >> answer;
                    
                    if (answer == 0) {
                      backToManageMenu = true;
                      break;
                    }

                  } while (cin.fail());

                  if (backToManageMenu) {
                    break;
                  }

                  char difficultyChoice;
                  do {
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the difficulty (1 - 5): ";
                    cin >> difficultyChoice;

                    if (difficultyChoice == '0') {
                      backToManageMenu = true;
                      break;
                    }

                  } while (difficultyChoice < '1' || difficultyChoice > '5');

                  if (backToManageMenu) {
                    break;
                  }

                  difficulty = difficultyChoice - '0';

                  flashCardScoring.insertNode(question, description, operation, answer, difficulty);

                  ofstream file;
                  file.open(fileName, ios::app);
                  file << endl << question << "\t" << description << "\t" << operation << "\t" << answer << "\t" << difficulty;
                  file.close();

                  cout << "Card added." << endl;
                  flashCardScoring.displayFlashCardWithAnswer(question);
                  cout << "Do you want to add another card? (Y/N): ";
                  cin >> choice;
                  cin.ignore();
                } while((choice == 'y' || choice == 'Y') && !backToManageMenu);
                break;
              }
              case '2': {
                char choice;
                cout << "Editing a flashcard..." << endl;
                do {
                  backToManageMenu = false;
                  flashCardScoring.displayQuestionList();

                  string questionToEdit;
                  do {
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the question to edit: ";
                    getline(cin, questionToEdit);

                    if (questionToEdit == "0") {
                      backToManageMenu = true;
                      break;
                    }

                  } while (questionToEdit == "");

                  if (backToManageMenu) {
                    break;
                  }

                  try {
                    if (flashCardScoring.searchQuestionNode(questionToEdit) == -1) {
                      throw "Question not found.";
                    }
                  } catch (const char* error) {
                    cout << "Error: " << error << endl;
                    break;
                  }

                  flashCardScoring.displayFlashCardWithAnswer(questionToEdit);

                  description = flashCardScoring.getDescriptionValue(questionToEdit);
                  operation = flashCardScoring.getOperationValue(questionToEdit);
                  answer = flashCardScoring.getAnswerValue(questionToEdit);
                  difficulty = flashCardScoring.getDifficultyValue(questionToEdit);

                  if (description == "") {
                    // if the question does not exist
                    break;
                  }

                  char fieldChoice;
                  do {
                    cout << "Which field to edit: " << endl;
                    cout << "1. Description" << endl;
                    cout << "2. Operation" << endl;
                    cout << "3. Answer" << endl;
                    cout << "4. Difficulty" << endl;
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter your choice: ";
                    cin >> fieldChoice;
                    cin.ignore();

                    if (fieldChoice == '0') {
                      backToManageMenu = true;
                      break;
                    }

                    if (fieldChoice < '1' || fieldChoice > '4') {
                      cout << "Invalid input. Please enter a number between 1 and 4." << endl;
                    }
                  } while (fieldChoice < '1' || fieldChoice > '4');

                  switch (fieldChoice) {
                    case '1': {
                      do {
                        cout << "Enter the new description: ";
                        getline(cin, description);
                      
                        if (description == "0") {
                          backToManageMenu = true;
                          break;
                        }

                      } while (description == "");

                      if (backToManageMenu) {
                        break;
                      }

                      break;
                    }
                    case '2': {
                      cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n";
                      char operationChar;
                      do {
                        cout << "Enter the new operation: ";
                        cin >> operationChar;
                        cin.ignore();

                        if (operationChar == '0') {
                          backToManageMenu = true;
                          break;
                        }

                        if (operationChar < '1' || operationChar > '4') {
                          cout << "Invalid input. Please enter a number between 1 and 4." << endl;
                        }
                      } while (operationChar < '1' || operationChar > '4');

                      if (backToManageMenu) {
                        break;
                      }

                      switch (operationChar) {
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
                      
                      break;
                    }
                    case '3': {
                      do {
                        cout << "Enter the new answer: ";
                        cin >> answer;
                        cin.ignore();

                        if (answer == 0) {
                          backToManageMenu = true;
                          break;
                        }

                      } while (cin.fail());

                      if (backToManageMenu) {
                        break;
                      }

                      break;
                    }
                    case '4': {
                      do {
                        cout << "Enter the new difficulty: ";
                        cin >> difficulty;
                        cin.ignore();

                        if (difficulty == 0) {
                          backToManageMenu = true;
                          break;
                        }

                      } while (cin.fail());

                      if (backToManageMenu) {
                        break;
                      }

                      break;
                    }
                  }

                  flashCardScoring.editCard(fileName, questionToEdit, description, operation, answer, difficulty);

                  cout << "Card edited." << endl;
                  cout << "Do you want to edit another card? (Y/N): ";
                  cin >> choice;
                  cin.ignore();
                } while ((choice == 'y' || choice == 'Y') && !backToManageMenu);
                break;
              }
              case '3' : {
                char userChoice;
                cout << "Deleting a flashcard..." << endl;
                do {
                  flashCardScoring.displayQuestionList();
                  string questionToDel;
                  char choice;
                  do {
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the question to delete: ";
                    getline(cin, questionToDel);

                    if (questionToDel == "0") {
                      backToManageMenu = true;
                      break;
                    }

                  } while (questionToDel == "");

                  if (backToManageMenu) {
                    break;
                  }

                  try {
                    if (flashCardScoring.searchQuestionNode(questionToDel) == -1) {
                      throw "Question not found.";
                    }
                  } catch (const char* error) {
                    cout << "Error: " << error << endl;
                    break;
                  }

                  do {
                    cout << "Are you sure you want to delete the card? (Y/N): ";
                    cin >> choice;
                    cin.ignore();
                    if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                      cout << "Invalid input. Please enter Y or N." << endl;
                    }
                  } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

                  flashCardScoring.deleteQuestionNode(fileName, questionToDel);
                  cout << "Card deleted." << endl;
                  cout << "Do you want to delete another card? (Y/N): ";
                  cin >> userChoice;
                } while ((userChoice == 'y' || userChoice == 'Y') && !backToManageMenu);
                break;
              }
            }
          }
          break;
      } 
      case '4': {
        char choice;
        do {
          cout << "Playing flashcard game..." << endl;
          cout << "====================================" << endl;
          cout << setw(28) << left << "|| Number of questions: " << setw(5) << right << numberOfQuestions(flashCardScoring) << " ||" << endl;
          cout << setw(28) << left << "|| Average difficulty: " << setw(5) << right << averageDifficulty(flashCardScoring) << " ||" << endl;
          cout << "====================================" << endl;
          string name;
          int age;

          do {
            cout << "Enter your name: ";
            getline(cin, name);
          } while (name == "");

          do {
            cout << "Enter your age: ";
            cin >> age;
            if(cin.fail()) {
              cin.clear();
              cin.ignore(10000, '\n');
            }
          } while (cin.fail() || age < 1);

          flashCardScoring.setName(name);
          flashCardScoring.setAge(age);

          int numQuestions;
          do {
            cin.clear();
            cout << "How many questions do you want to answer? ";
            cin >> numQuestions;
            if(cin.fail()) {
              cin.clear();
              cin.ignore(10000, '\n');
            }
          } while (cin.fail() || numQuestions < 1);
          for (int i = 0; i < numQuestions; i++) {
            question = flashCardScoring.displayRandomFlashCard();

            do {
              if(cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
              }
              cout << "Enter your answer: ";
              cin >> answer;
            } while (cin.fail());

            flashCardScoring.updateScore(question, answer);
          }
          flashCardScoring.displayScore();
          flashCardScoring.resetScore();
          cout << "Do you want to play again? (Y/N): ";
          cin >> choice;
        } while (choice == 'y' || choice == 'Y');
        break;
      }
      case '5': {
        char choice;
        do {
          cout << "Are you sure you want to terminate the program? (Y/N): ";
          cin >> choice;
          if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
            cout << "Invalid input. Please enter Y or N." << endl;
          }
        } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');

        if (choice == 'n' || choice == 'N') {
          cout << "Action cancelled." << endl;
          break;
        }

        cout << "Terminating program...\n" << endl;
        terminate = true;
        break;
      }
    }
  } while (!terminate);

  return 0;
}