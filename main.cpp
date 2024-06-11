// Run the following command to compile the code:
// g++ *.cpp -o main && ./main
// g++ *.cpp -o main && main

#include <iostream> // for input / output stream
#include <string> // for string manipulation
#include <iomanip> // for input / output manipulation
#include <fstream> // for file input / output
using namespace std;

#include "DoublyLinkedList.h" // preprocessor directive to include the DoublyLinkedList header file
#include "FlashCard.h" // preprocessor directive to include the FlashCard header file
#include "Score.h" // preprocessor directive to include the Score header file

/**
 * Calculates the average difficulty of a flashcard.
 * 
 * friend function declaring in main.cpp
 *
 * @tparam U1 The type of the flashcard's question.
 * @tparam U2 The type of the flashcard's answer.
 * @tparam U3 The type of the flashcard's category.
 * @tparam U4 The type of the flashcard's subcategory.
 * @tparam U5 The type of the flashcard's difficulty.
 * @param card The flashcard object.
 * @return The average difficulty of the flashcard.
 */
template <class U1, class U2, class U3, class U4, class U5>
double averageDifficulty(const FlashCard<U1, U2, U3, U4, U5> & card) {
  double sum = 0; // sum of all difficulties
  U1 currentQuestion = card.questions.getHeadValue(); // get the first question
  sum += card.difficulties.getNodeValue(currentQuestion); // add the difficulty of the first question
  do {
    currentQuestion = card.questions.getNextNodeValue(currentQuestion); // get the next question
    sum += card.difficulties.getNodeValue(currentQuestion); // add the difficulty of the next question
  } while (currentQuestion != card.questions.getTailValue()); // loop until the last question

  return sum / card.questions.getNumberOfNodes(); // return the average difficulty
}

/**
 * @brief Calculates the number of questions in a flashcard.
 * 
 * This function takes a FlashCard object as input and returns the number of questions
 * stored in the flashcard.
 * 
 * friend function declaring in main.cpp
 * 
 * @tparam U1 The type of the first field in the FlashCard object.
 * @tparam U2 The type of the second field in the FlashCard object.
 * @tparam U3 The type of the third field in the FlashCard object.
 * @tparam U4 The type of the fourth field in the FlashCard object.
 * @tparam U5 The type of the fifth field in the FlashCard object.
 * 
 * @param card The FlashCard object to calculate the number of questions from.
 * 
 * @return The number of questions in the flashcard.
 */
template <class U1, class U2, class U3, class U4, class U5>
int numberOfQuestions(const FlashCard<U1, U2, U3, U4, U5> & card) {
  return card.questions.getNumberOfNodes(); // return the number of questions in the flashcard
}

/**
 * The main function is the entry point of the program.
 * It initializes the necessary variables and objects, and presents a menu to the user.
 * The user can choose various options such as displaying flashcards, searching for flashcards, managing flashcards, playing a flashcard game, or terminating the program.
 * Based on the user's choice, the program performs the corresponding actions.
 * The main function uses the Score class to manage and display flashcards.
 *
 * @return 0 indicating successful program execution.
 */

int main () {
  bool terminate = false; // variable to determine if the program should terminate
  do {
    Score <string, string, string, double, int> flashCardScoring; // create a Score object to manage flashcards
    string question, description, operation; // variables to store the question, description, and operation of a flashcard
    double answer; // variable to store the answer of a flashcard
    int difficulty; // variable to store the difficulty of a flashcard

    fstream file; // file stream object to read the flashcard file
    string fileName = "flashCard.txt"; // name of the flashcard file
    
    // try-catch block to handle exceptions when initializing the flashcard file
    // if the file does not exist, an exception is thrown
    try {
      flashCardScoring.initialize(fileName); // initialize the flashcard file
    } catch (const char* error) { // catch the exception
      cout << "Error: " << error << endl; // display the error message
      break;
    }

    bool exit = false; // variable to determine if the user wants to exit the program
    char menuChoice; // variable to store the user's menu choice

    // do-while loop to display the main menu
    do {
      // display the main menu
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
    } while (menuChoice < '1' || menuChoice > '5'); // loop until the user enters a valid choice

    // switch statement to perform the corresponding action based on the user's choice
    switch (menuChoice) {
      // case 1: Display flashcards 
      case '1': { 
        cout << "\nDisplaying flashcard menu..."<<endl;
        char displayChoice; // variable to store the user's display choice
        char choice; // variable to store the user's choice
        bool mainMenu = false; // variable to determine if the user wants to return to the main menu
        do {
          mainMenu = false; // set mainMenu to false
          do {
            // display the flashcard sub-menu
            cout << "+---------------------------------+" << endl;
            cout << "1. Display all flashcard" << endl;
            cout << "2. Display all flashcard questions" << endl;
            cout << "3. Display flashcard one by one" << endl;
            cout << "0. Back to main menu" << endl;
            cout << "+---------------------------------+\n";
            cout << "Enter your choice: ";
            cin >> displayChoice; // get the user's display choice
            cin.ignore();
            // input validation
            if (displayChoice < '0' || displayChoice > '3') {
              cout << "Invalid input. Please enter a number between 0 and 3." << endl;
            }
          } while (displayChoice < '0' || displayChoice > '3'); // loop until the user enters a valid choice

          // switch statement to perform the corresponding action based on the user's display choice
          switch (displayChoice) {
            // case 1: Display all flashcards
            case '1': {
              cout << "\nDisplaying all flashcards..."<<endl;
              flashCardScoring.displayAllFlashCard(); // display all flashcards
              break;
            }
            // case 2: Display all flashcard questions
            case '2': {
              cout << "\nDisplaying all flashcard questions..."<<endl;
              flashCardScoring.displayQuestionList(); // display all flashcard questions
              break;
            }
            // case 3: Display flashcards one by one
            case '3': {
              cout << "\nDisplaying flashcards one by one..."<<endl;
              flashCardScoring.displayFlashCardOneByOne(); // display flashcards one by one
              break;
            }
            // case 0: Back to main menu
            case '0': {
              char choice; // variable to store the user's choice
              // do-while loop to confirm if the user wants to go back to the main menu
              do {
                cout << "Are you sure you want to go back to the main menu? (Y/N): ";
                cin >> choice;
                // input validation
                if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                  cout << "Invalid input. Please enter Y or N." << endl;
                }
              } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'); // loop until the user enters a valid choice

              // if the user chooses not to go back to the main menu
              if (choice == 'n' || choice == 'N') {
                cout << "Action cancelled." << endl;
                mainMenu = false; // set mainMenu to false to remain in the flashcard sub-menu
                break;
              }

              // if the user chooses to go back to the main menu
              if (choice == 'y' || choice == 'Y') {
                mainMenu = true; // set mainMenu to true to return to the main menu
              }

              cout << "Back to main menu..." << endl;
              break;
            }
          }

          // do-while loop to confirm if the user wants to remain in the flashcard sub-menu
          if (!mainMenu && displayChoice != '4') {
            cout << "Would you like to remain in the flashcard sub-menu? (Y/N): ";
            cin >> choice;
            cout << "\n";

            // if the user chooses not to remain in the flashcard sub-menu
            if (choice == 'n' || choice == 'N') {
              mainMenu = true; // set mainMenu to true to return to the main menu
            }
          }
        } while (!mainMenu); // loop until the user chooses to return to the main menu
        break;
      }
      // case 2: Search for a flashcard
      case '2': {
        cout << "Searching for a flashcard..." << endl;
        string search; // variable to store the user's search query
        char searchChoice; // variable to store the user's search choice
        char choice; // variable to store the user's choice
        bool searchMenu = true; // variable to determine if the user wants to remain in the search menu

        // do-while loop to display the search menu
        while (searchMenu) {
          bool backToSearchMenu = false; // variable to determine if the user wants to return to the search menu
          do {
            // display the search menu
            cout << "+---------------------------------+" << endl;
            cout << "1. Search by question" << endl;
            cout << "2. Search by description" << endl;
            cout << "3. Search by operation" << endl;
            cout << "4. Search by answer" << endl;
            cout << "5. Search by difficulty" << endl;
            cout << "0. Back to main menu" << endl;
            cout << "+---------------------------------+\n";
            cout << "Enter your choice: ";
            cin >> searchChoice;
            cin.ignore();
            // input validation
            if (searchChoice < '0' || searchChoice > '5') {
              cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            }
          } while (searchChoice < '0' || searchChoice > '5'); // loop until the user enters a valid choice

          // if the user chooses to go back to the main menu
          if (searchChoice == '0') {
            // do-while loop to confirm if the user wants to go back to the main menu
            do {
              cout << "Are you sure you want to go back to the main menu? (Y/N): ";
              cin >> choice;
              // input validation
              if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                cout << "Invalid input. Please enter Y or N." << endl;
              }
            } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'); // loop until the user enters a valid choice

            // if the user chooses not to go back to the main menu
            if (choice == 'n' || choice == 'N') {
              cout << "Action cancelled." << endl;
              break;
            }

            // if the user chooses to go back to the main menu
            cout << "Back to main menu..." << endl;
            searchMenu = false; // set searchMenu to false to exit the search menu
            break;
          }

          switch (searchChoice) {
            // case 1: Search by question
            case '1': {
              flashCardScoring.displayQuestionList(); // display the list of questions
              // do-while loop to get the user's search query
              do {
                cout << "eg. 5 + 3 = ?\n";
                cout << "Press 0 to go back to search menu...\n";
                cout << "Enter the question to search: ";
                getline(cin, search);

                // if the user chooses to go back to the search menu
                if (search == "0") {
                  backToSearchMenu = true; // set backToSearchMenu to true to return to the search menu
                  break;
                }

              } while (search == "" || !flashCardScoring.searchQuestionNode(search)); // loop until the user enters a valid search query
              break;
            }
            // case 2: Search by description
            case '2': {
              // do-while loop to get the user's search query
              do {
                cout << "eg. What is 5 plus 3?\n";
                cout << "Press 0 to go back to search menu...\n";
                cout << "Enter the description to search: ";
                getline(cin, search);

                // if the user chooses to go back to the search menu
                if (search == "0") {
                  backToSearchMenu = true; // set backToSearchMenu to true to return to the search menu
                  break;
                }

              } while (search == "" || !flashCardScoring.searchDescription(search)); // loop until the user enters a valid search query
              break;
            }
            // case 3: Search by operation
            case '3': {
              char operationChar; // variable to store the user's operation choice
              bool backToSearchMenu = false; // variable to determine if the user wants to return to the search menu
              // do-while loop to get the user's operation choice
              do {
                // display the operation menu
                cout << "\n+---------------------------------+\n";
                cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n0 - Back to search menu\n";
                cout << "+---------------------------------+\n";
                cout << "Enter the operation to search (0 - 4): ";
                cin >> operationChar;
                cin.ignore();
                // input validation
                if (operationChar < '0' || operationChar > '4') {
                  cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                }
              } while (operationChar < '0' || operationChar > '4'); // loop until the user enters a valid choice

              // if the user chooses to go back to the search menu
              if (operationChar == '0') {
                char choice;
                // do-while loop to confirm if the user wants to go back to the search menu
                do {
                  cout << "Are you sure you want to go back to the search menu? (Y/N): ";
                  cin >> choice;
                  // input validation
                  if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                    cout << "Invalid input. Please enter Y or N." << endl;
                  }
                } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'); // loop until the user enters a valid choice
                
                // if the user chooses not to go back to the search menu
                if (choice == 'n' || choice == 'N') {
                  cout << "Action cancelled." << endl;
                  continue;
                }

                cout << "Back to search menu..." << endl;
                backToSearchMenu = true; // set backToSearchMenu to true to return to the search menu
              }

              // if the user chooses to return to the search menu
              if (backToSearchMenu) {
                continue;
              }

              // convert the operation choice to a string that is used to search for the operation
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

              // try-catch block to handle exceptions when searching for the operation
              // if the operation is not found, an exception is thrown
              try {
                // search for the operation
                if (flashCardScoring.searchOperation(search) == -1) {
                  throw "Operation not found."; // throw an exception if the operation is not found
                }
              } catch (const char* error) { // catch the exception
                cout << "Error: " << error << endl; // display the error message
              }
              
              break;
            }
            // case 4: Search by answer
            case '4': {
              double searchAns; // variable to store the user's answer choice
              cout << "Press 0 to go back to search menu...\n";
              cout << "eg. 8\n";
              cout << "Enter the answer to search: ";
              // do-while loop to get the user's answer choice
              do {
                cin >> searchAns; // get the user's answer choice
                cin.ignore();

                if(cin.fail()) {
                  cin.clear();
                  cin.ignore(10000, '\n'); // clear the input buffer
                  cout << "Invalid input. Please enter a number." << endl;
                  cout << "Enter the answer to search: ";
                  cin >> searchAns;
                  cin.ignore();
                }
              } while (cin.fail()); // loop until the user enters a valid answer

              // if the user chooses to go back to the search menu
              if(searchAns == 0) {
                backToSearchMenu = true; // set backToSearchMenu to true to return to the search menu
                break;
              }

              // try-catch block to handle exceptions when searching for the answer
              // if the answer is not found, an exception is thrown
              try {
                // search for the answer
                if (flashCardScoring.searchAnswer(searchAns) == -1) { // if the answer is not found
                  throw "Answer not found."; // throw an exception
                }
              } catch (const char* error) { // catch the exception
                cout << "Error: " << error << endl; // display the error message
              }
              break;
            }
            // case 5: Search by difficulty
            case '5': {
              char difficultyChar; // variable to store the user's difficulty choice
              do {
                cout << "Press 0 to go back to search menu...\n";
                cout << "Enter the difficulty to search (1 - 5): ";
                cin >> difficultyChar;
                cin.ignore();

                // if the user chooses to go back to the search menu
                if (difficultyChar == '0') {
                  backToSearchMenu = true; // set backToSearchMenu to true to return to the search menu
                  break;
                }

                // input validation
                if (difficultyChar < '1' || difficultyChar > '5') {
                  cout << "Invalid input. Please enter a number between 1 and 5." << endl;
                }
              } while (difficultyChar < '1' || difficultyChar > '5'); // loop until the user enters a valid choice

              difficulty = difficultyChar - '0'; // convert the difficulty choice to an integer

              // try-catch block to handle exceptions when searching for the difficulty
              // if the difficulty is not found, an exception is thrown
              try {
                // search for the difficulty
                if (flashCardScoring.searchDifficulty(difficulty) == -1) { // if the difficulty is not found
                  throw "Difficulty not found."; // throw an exception
                }
              } catch (const char* error) { // catch the exception
                cout << "Error: " << error << endl; // display the error message
              }
              break;
            }
          }

          // do-while loop to confirm if the user wants to return to the search menu
          if (backToSearchMenu) {
            continue;
          }

          // do-while loop to confirm if the user wants to search another flashcard
          cout << "Do you want to search another flashcard? (Y/N): ";
          cin >> choice;
          // input validation
          if (choice == 'n' || choice == 'N') {
            searchMenu = false; // set searchMenu to false to exit the search menu
          }
        }
        break;
      }
      // case 3: Manage flashcard
      case '3': {
        char manageChoice; // variable to store the user's manage choice
        bool manageMenu = true; // variable to determine if the user wants to remain in the manage menu
          
          while (manageMenu) { // while loop to display the manage menu
            bool backToManageMenu = false; // variable to determine if the user wants to return to the manage menu
            // do-while loop to get the user's manage choice
            do {
              // display the manage menu
              cout << "Managing flashcard menu..." << endl;
              cout << "+---------------------------------+" << endl;
              cout << "0. Back to main menu" << endl;
              cout << "1. Add a flashcard" << endl;
              cout << "2. Edit a flashcard" << endl;
              cout << "3. Delete a flashcard" << endl;
              cout << "+---------------------------------+\n";
              cout << "Enter your choice: ";
              cin >> manageChoice;
              cin.ignore();
              // input validation
              if (manageChoice < '0' || manageChoice > '3') {
                cout << "Invalid input. Please enter a number between 0 and 3." << endl;
              }
            } while (manageChoice < '0' || manageChoice > '3'); // loop until the user enters a valid choice
            
            // if the user chooses to go back to the main menu
            if (manageChoice == '0') {
              char choice; // variable to store the user's choice
              // do-while loop to confirm if the user wants to go back to the main menu
              do {
                cout << "Are you sure you want to go back to the main menu? (Y/N): ";
                cin >> choice;
                // input validation
                if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                  cout << "Invalid input. Please enter Y or N." << endl;
                }
              } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'); // loop until the user enters a valid choice

              // if the user chooses not to go back to the main menu
              if (choice == 'n' || choice == 'N') {
                cout << "Action cancelled." << endl;
                break;
              } 
              
              cout << "Back to main menu..." << endl;
              manageMenu = false; // set manageMenu to false to exit the manage menu
              break;
            }

            // Switch statement to perform the corresponding action based on the user's manage choice
            switch (manageChoice) {
              // case 1: Add a flashcard
              case '1': {
                cout << "Adding a flashcard..." << endl;
                char operationChoice; // variable to store the user's operation choice
                char choice; // variable to store the user's choice
                // do-while loop to add a flashcard
                do{
                  backToManageMenu = false; // set backToManageMenu to false
                  // do-while loop to get the user's question
                  do {
                    cout << "eg. 5 + 3 = ?\n";
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the question: ";
                    getline(cin, question);
                    
                    // if the user chooses to go back to the manage menu
                    if (question == "0") {
                      backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                      break;
                    }

                  } while (question == ""); // loop until the user enters a valid question

                  // if the user chooses to go back to the manage menu
                  if (backToManageMenu) {
                    break;
                  }

                  // try-catch block to handle exceptions when adding a flashcard
                  // if the question already exists, an exception is thrown
                  try {
                    // search for the question
                    if (flashCardScoring.searchQuestionNode(question) != -1) { // if the question already exists
                      throw "Question already exists."; // throw an exception
                    } else {
                      cout << "Question does not exist. You are good to go." << endl; // display a message if the question does not exist
                    }
                  } catch (const char* error) { // catch the exception
                    cout << "Error: " << error << endl; // display the error message
                    break;
                  }

                  // do-while loop to get the user's description
                  do {
                    cout << "eg. What is 5 plus 3?\n";
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the description: ";
                    getline(cin, description);

                    // if the user chooses to go back to the manage menu
                    if (description == "0") {
                      backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                      break;
                    }

                  } while (description == ""); // loop until the user enters a valid description

                  // if the user chooses to go back to the manage menu
                  if (backToManageMenu) {
                    break;
                  }

                  // do-while loop to get the user's operation choice
                  do {
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\nEnter the operation (1 - 4): ";
                    cin >> operationChoice;

                    // if the user chooses to go back to the manage menu
                    if (operationChoice == '0') {
                      backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                      break;
                    }

                  } while (operationChoice < '1' || operationChoice > '4'); // loop until the user enters a valid operation choice

                  // if the user chooses to go back to the manage menu
                  if (backToManageMenu) {
                    break;
                  }

                  // convert the operation choice to a string
                  // this string is used to store the operation of the flashcard
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

                  // do-while loop to get the user's answer
                  do {
                    // get the user's answer
                    if(cin.fail()) {
                      cin.clear();
                      cin.ignore(10000, '\n'); // clear the input buffer
                    }
                    cout << "eg. 8\n";
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the answer: ";
                    cin >> answer;
                    
                    // if the user chooses to go back to the manage menu
                    if (answer == 0) {
                      backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                      break;
                    }

                  } while (cin.fail()); // loop until the user enters a valid answer

                  // if the user chooses to go back to the manage menu
                  if (backToManageMenu) {
                    break;
                  }

                  char difficultyChoice; // variable to store the user's difficulty choice
                  // do-while loop to get the user's difficulty choice
                  do {
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the difficulty (1 - 5): ";
                    cin >> difficultyChoice;

                    // if the user chooses to go back to the manage menu
                    if (difficultyChoice == '0') {
                      backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                      break;
                    }

                  } while (difficultyChoice < '1' || difficultyChoice > '5'); // loop until the user enters a valid difficulty choice

                  // if the user chooses to go back to the manage menu
                  if (backToManageMenu) {
                    break;
                  }

                  difficulty = difficultyChoice - '0'; // convert the difficulty choice to an integer

                  flashCardScoring.insertNode(question, description, operation, answer, difficulty); // insert the flashcard into the flashcard list

                  ofstream file; // file stream object to write to the flashcard file
                  file.open(fileName, ios::app); // open the flashcard file in append mode
                  file << endl << question << "\t" << description << "\t" << operation << "\t" << answer << "\t" << difficulty; // write the flashcard to the file
                  file.close(); // close the file

                  cout << "Card added." << endl;
                  flashCardScoring.displayFlashCardWithAnswer(question); // display the flashcard with the answer
                  cout << "Do you want to add another card? (Y/N): ";
                  cin >> choice;
                  cin.ignore();
                } while((choice == 'y' || choice == 'Y') && !backToManageMenu); // loop until the user chooses not to add another card
                break;
              }
              // case 2: Edit a flashcard
              case '2': {
                char choice; // variable to store the user's choice
                cout << "Editing a flashcard..." << endl;
                do {
                  backToManageMenu = false; // set backToManageMenu to false
                  flashCardScoring.displayQuestionList(); // display the list of questions

                  string questionToEdit; // variable to store the user's question to edit
                  // do-while loop to get the user's question to edit
                  do {
                    cout << "eg. 5 + 3 = ?\n";
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the question to edit: ";
                    getline(cin, questionToEdit);

                    // if the user chooses to go back to the manage menu
                    if (questionToEdit == "0") {
                      backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                      break;
                    }

                  } while (questionToEdit == ""); // loop until the user enters a valid question to edit

                  // if the user chooses to go back to the manage menu
                  if (backToManageMenu) {
                    break;
                  }

                  // try-catch block to handle exceptions when editing a flashcard
                  // if the question is not found, an exception is thrown
                  try {
                    // search for the question
                    if (flashCardScoring.searchQuestionNode(questionToEdit) == -1) { // if the question is not found
                      throw "Question not found."; // throw an exception
                    }
                  } catch (const char* error) { // catch the exception
                    cout << "Error: " << error << endl; // display the error message
                    break;
                  }

                  // get the description, operation, answer, and difficulty of the flashcard to edit
                  description = flashCardScoring.getDescriptionValue(questionToEdit); // get the description
                  operation = flashCardScoring.getOperationValue(questionToEdit); // get the operation
                  answer = flashCardScoring.getAnswerValue(questionToEdit); // get the answer
                  difficulty = flashCardScoring.getDifficultyValue(questionToEdit); // get the difficulty

                  // if the description is empty
                  if (description == "") {
                    break;
                  }

                  char fieldChoice; // variable to store the user's field choice
                  // do-while loop to get the user's field choice
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

                    // if the user chooses to go back to the manage menu
                    if (fieldChoice == '0') {
                      backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                      break;
                    }

                    // input validation
                    if (fieldChoice < '1' || fieldChoice > '4') {
                      cout << "Invalid input. Please enter a number between 1 and 4." << endl;
                    }
                  } while (fieldChoice < '1' || fieldChoice > '4'); // loop until the user enters a valid field choice

                  // switch statement to perform the corresponding action based on the user's field choice
                  switch (fieldChoice) {
                    // case 1: Edit the description
                    case '1': {
                      do {
                        cout << "Enter the new description: ";
                        getline(cin, description);
                        
                        // if the user chooses to go back to the manage menu
                        if (description == "0") {
                          backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                          break;
                        }

                      } while (description == ""); // loop until the user enters a valid description

                      // if the user chooses to go back to the manage menu
                      if (backToManageMenu) {
                        break;
                      }

                      break;
                    }
                    // case 2: Edit the operation
                    case '2': {
                      cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n";
                      char operationChar; // variable to store the user's operation choice
                      // do-while loop to get the user's operation choice
                      do {
                        cout << "Enter the new operation: ";
                        cin >> operationChar;
                        cin.ignore();

                        // if the user chooses to go back to the manage menu
                        if (operationChar == '0') {
                          backToManageMenu = true;
                          break;
                        }

                        // input validation
                        if (operationChar < '1' || operationChar > '4') {
                          cout << "Invalid input. Please enter a number between 1 and 4." << endl;
                        }
                      } while (operationChar < '1' || operationChar > '4'); // loop until the user enters a valid operation choice

                      // if the user chooses to go back to the manage menu
                      if (backToManageMenu) {
                        break;
                      }

                      // convert the operation choice to a string
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
                    // case 3: Edit the answer
                    case '3': {
                      // do-while loop to get the user's answer
                      do {
                        cout << "Enter the new answer: ";
                        cin >> answer;
                        cin.ignore();

                        while (cin.fail()) {
                          cin.clear();
                          cin.ignore(10000, '\n'); // clear the input buffer
                          cout << "Invalid input. Please enter a number." << endl << endl;
                          cout << "Enter the new answer: ";
                          cin >> answer;
                          cin.ignore();
                        }
                      } while (cin.fail()); // loop until the user enters a valid answer

                      // if the user chooses to go back to the manage menu
                      if (answer == 0) {
                        backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                        break;
                      }

                      break;
                    }
                    // case 4: Edit the difficulty
                    case '4': {
                      // do-while loop to get the user's difficulty
                      do {
                        cout << "Enter the new difficulty: ";
                        cin >> difficulty;
                        cin.ignore();

                        // if the user chooses to go back to the manage menu
                        if (difficulty == 0) {
                          backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                          break;
                        }

                      } while (cin.fail()); // loop until the user enters a valid difficulty

                      // if the user chooses to go back to the manage menu
                      if (backToManageMenu) {
                        break;
                      }

                      break;
                    }
                  }

                  flashCardScoring.editCard(fileName, questionToEdit, description, operation, answer, difficulty); // edit the flashcard

                  cout << "Card edited." << endl;
                  cout << "Do you want to edit another card? (Y/N): ";
                  cin >> choice;
                  cin.ignore();
                } while ((choice == 'y' || choice == 'Y') && !backToManageMenu); // loop until the user chooses not to edit another card
                break;
              }
              // case 3: Delete a flashcard
              case '3' : {
                char userChoice; // variable to store the user's choice
                cout << "Deleting a flashcard..." << endl;
                // do-while loop to delete a flashcard
                do {
                  flashCardScoring.displayQuestionList(); // display the list of questions
                  string questionToDel; // variable to store the user's question to delete
                  char choice; // variable to store the user's choice
                  do {
                    cout << "eg. 5 + 3 = ?\n";
                    cout << "Press 0 to go back to the manage menu...\n";
                    cout << "Enter the question to delete: ";
                    getline(cin, questionToDel);

                    // if the user chooses to go back to the manage menu
                    if (questionToDel == "0") {
                      backToManageMenu = true; // set backToManageMenu to true to return to the manage menu
                      break;
                    }

                  } while (questionToDel == ""); // loop until the user enters a valid question to delete

                  // if the user chooses to go back to the manage menu
                  if (backToManageMenu) {
                    break;
                  }

                  // try-catch block to handle exceptions when deleting a flashcard
                  // if the question is not found, an exception is thrown
                  try {
                    // search for the question
                    if (flashCardScoring.searchQuestionNode(questionToDel) == -1) { // if the question is not found
                      throw "Question not found."; // throw an exception
                    }
                  } catch (const char* error) { // catch the exception
                    cout << "Error: " << error << endl; // display the error message
                    break;
                  }

                  // do-while loop to confirm if the user wants to delete the flashcard
                  do {
                    cout << "Are you sure you want to delete the card? (Y/N): ";
                    cin >> choice;
                    cin.ignore();
                    // input validation
                    if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                      cout << "Invalid input. Please enter Y or N." << endl;
                    }
                  } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'); // loop until the user enters a valid choice

                  flashCardScoring.deleteQuestionNode(fileName, questionToDel); // delete the flashcard
                  cout << "Card deleted." << endl;
                  cout << "Do you want to delete another card? (Y/N): ";
                  cin >> userChoice;
                } while ((userChoice == 'y' || userChoice == 'Y') && !backToManageMenu); // loop until the user chooses not to delete another card
                break;
              }
            }
          }
          break;
      } 
      // case 4: Play flashcard game
      case '4': {
        char choice; // variable to store the user's choice
        do {
          // display the flashcard game
          cout << "Playing flashcard game..." << endl;
          cout << "====================================" << endl;
          cout << setw(28) << left << "|| Number of questions: " << setw(5) << right << numberOfQuestions(flashCardScoring) << " ||" << endl;
          cout << setw(28) << left << "|| Average difficulty: " << setw(5) << right << averageDifficulty(flashCardScoring) << " ||" << endl;
          cout << "====================================" << endl;
          string name; // variable to store the user's name
          int age; // variable to store the user's age

          // do-while loop to get the user's name
          do {
            cout << "Enter your name: ";
            getline(cin, name);
          } while (name == ""); // loop until the user enters a valid name

          // do-while loop to get the user's age
          do {
            cout << "Enter your age: ";
            cin >> age;
            // if the input is invalid
            if(cin.fail()) {
              cin.clear();
              cin.ignore(10000, '\n'); // clear the input buffer
            }
          } while (cin.fail() || age < 1); // loop until the user enters a valid age

          flashCardScoring.setName(name); // set the user's name
          flashCardScoring.setAge(age); // set the user's name and age

          int numQuestions; // variable to store the number of questions the user wants to answer
          // do-while loop to get the number of questions the user wants to answer
          do {
            cin.clear(); // clear the input buffer
            cout << "How many questions do you want to answer? ";
            cin >> numQuestions;
            // if the input is invalid
            if(cin.fail()) {
              cin.clear();
              cin.ignore(10000, '\n'); // clear the input buffer
            }
          } while (cin.fail() || numQuestions < 1); // loop until the user enters a valid number of questions

          // display the flashcard game instructions
          for (int i = 0; i < numQuestions; i++) {
            question = flashCardScoring.displayRandomFlashCard(); // display a random flashcard

            // do-while loop to get the user's answer
            do {
              // if the input is invalid
              if(cin.fail()) { 
                cin.clear();
                cin.ignore(10000, '\n'); // clear the input buffer
              }
              cout << "Enter your answer: ";
              cin >> answer;
            } while (cin.fail()); // loop until the user enters a valid answer

            flashCardScoring.updateScore(question, answer); // update the user's score
          }
          flashCardScoring.displayScore(); // display the user's score
          flashCardScoring.resetScore(); // reset the user's score
          cout << "Do you want to play again? (Y/N): ";
          cin >> choice;
        } while (choice == 'y' || choice == 'Y'); // loop until the user chooses not to play again
        break;
      }
      // case 5: Exit the program
      case '5': {
        char choice; // variable to store the user's choice
        // do-while loop to confirm if the user wants to terminate the program
        do {
          cout << "Are you sure you want to terminate the program? (Y/N): ";
          cin >> choice;
          // input validation
          if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
            cout << "Invalid input. Please enter Y or N." << endl;
          }
        } while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N'); // loop until the user enters a valid choice

        // if the user chooses not to terminate the program
        if (choice == 'n' || choice == 'N') {
          cout << "Action cancelled." << endl;
          break;
        }

        cout << "Terminating program...\n" << endl;
        terminate = true; // set terminate to true to exit the program
        break;
      }
    }
  } while (!terminate); // loop until the user chooses to terminate the program

  return 0;
}