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
        fstream file;
        string fileName = "flashCard.txt";
        
        try {
          flashCardScoring.initialize(fileName);
        } catch (const char* error) {
          cout << "Error: " << error << endl;
          break;
        }

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
              cout << "Searching for a flashcard..." << endl;
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
                  do {
                    cout << "Enter the question to search: ";
                    getline(cin, search);
                  } while (search == "");
                  break;
                }
                case '2': {
                  do {
                    cout << "Enter the description to search: ";
                    getline(cin, search);
                  } while (search == "");
                  break;
                }
                case '3': {
                  char operationChar;
                  do {
                    cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n";
                    cout << "Enter the operation to search (1 - 4): ";
                    cin >> operationChar;
                    cin.ignore();
                  } while (operationChar < '1' || operationChar > '4');

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
                  cout << "Enter the answer to search: ";
                  cin >> search;
                  cin.ignore();

                  try {
                    if (flashCardScoring.searchAnswer(stod(search)) == -1) {
                      throw "Answer not found.";
                    }
                  } catch (const char* error) {
                    cout << "Error: " << error << endl;
                  }

                  do {
                    if (cin.fail()) {
                      cin.clear();
                      cin.ignore(10000, '\n');
                      cout << "Invalid input. Please enter a number." << endl;
                      cout << "Enter the answer to search: ";
                      cin >> search;
                      cin.ignore();
                    }
                  } while (cin.fail());

                  break;
                }
                case '5': {
                  char difficultyChar;
                  do {
                    cout << "Enter the difficulty to search (1 - 5): ";
                    cin >> difficultyChar;
                    cin.ignore();
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
              break;
              }
            case '5': {
              cout << "Adding a flashcard..." << endl;
              char operationChoice;
              string choice;
              do{
                do {
                  cout << "Enter the question: ";
                  getline(cin, question);
                } while (question == "");

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
                  cout << "Enter the description: ";
                  getline(cin, description);
                } while (description == "");

                do {
                  cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\nEnter the operation (1 - 4): ";
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

                do {
                  if(cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                  }
                  cout << "Enter the answer: ";
                  cin >> answer;
                } while (cin.fail());

                char difficultyChoice;
                do {
                  cout << "Enter the difficulty (1 - 5): ";
                  cin >> difficultyChoice;
                } while (difficultyChoice < '1' || difficultyChoice > '5');

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
              } while(choice == "y" || choice == "Y");
              break;
            }
            case '6': {
              cout << "Editing a flashcard..." << endl;
              flashCardScoring.displayQuestionList();

              string questionToEdit;
              do {
                cout << "Enter the question to edit: ";
                getline(cin, questionToEdit);
              } while (questionToEdit == "");

              try {
                if (flashCardScoring.searchQuestionNode(questionToEdit) == -1) {
                  throw "Question not found.";
                }
              } catch (const char* error) {
                cout << "Error: " << error << endl;
                break;
              }

              // set the old card details
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
                cout << "Enter your choice: ";
                cin >> fieldChoice;
                cin.ignore();
              } while (fieldChoice < '1' || fieldChoice > '4');

              switch (fieldChoice) {
                case '1': {
                  do {
                    cout << "Enter the new description: ";
                    getline(cin, description);
                  } while (description == "");
                  break;
                }
                case '2': {
                  cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n";
                  char operationChar;
                  do {
                    cout << "Enter the new operation: ";
                    cin >> operationChar;
                    cin.ignore();
                  } while (operationChar < '1' || operationChar > '4');

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
                  } while (cin.fail());
                  break;
                }
                case '4': {
                  do {
                    cout << "Enter the new difficulty: ";
                    cin >> difficulty;
                    cin.ignore();
                  } while (cin.fail());
                  break;
                }
              }

              flashCardScoring.editCard(fileName, questionToEdit, description, operation, answer, difficulty);

              break;
            }
            case '7': {
              cout << "Deleting a flashcard..." << endl;
              flashCardScoring.displayQuestionList();
              string questionToDel;
              do {
                cout << "Enter the question to delete: ";
                getline(cin, questionToDel);
              } while (questionToDel == "");

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
              } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N');
              if (choice == 'n' || choice == 'N') {
                cout << "Action cancelled." << endl;
                break;
              }
              flashCardScoring.deleteQuestionNode(fileName, questionToDel);
              break;
            }
            case '8': {
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