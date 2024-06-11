// Run the following command to compile the code:
// g++ maintest.cpp DoublyLinkedList.cpp FlashCard.cpp Score.cpp -o main & ./main
// g++ maintest.cpp DoublyLinkedList.cpp FlashCard.cpp Score.cpp -o main & main

// Include libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Include header files
#include "DoublyLinkedList.h"
#include "FlashCard.h"
#include "Score.h"

// Function prototypes
template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardEditChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring, string fileName);
template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardMenu(Score <T1, T2, T3, T4, T5> & flashCardScoring);
void displayFlashCardMenu();
template <class T1, class T2, class T3, class T4, class T5>
void displayFlashCardDisplayChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring);
template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardSearchChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring);
template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardSearchMenu(Score <T1, T2, T3, T4, T5> & flashCardScoring);
template <class T1, class T2, class T3, class T4, class T5>
void displayFlashCardManageChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring);
template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardAddChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring, string fileName);
template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardDeleteChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring, string fileName);
template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardPlayGame(Score <T1, T2, T3, T4, T5> & flashCardScoring);

// Calculate the average difficulty of a flashcard
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

// Calculate the number of questions in a flashcard
template <class U1, class U2, class U3, class U4, class U5>
int numberOfQuestions(const FlashCard<U1, U2, U3, U4, U5> & card) {
  return card.questions.getNumberOfNodes();
}

int main () {
    bool terminate = false;
    Score <string, string, string, double, int> flashCardScoring;  //Object declaration
    char userChoice;
    do {
        cout << "******************************************" << endl;
        cout << "   --- Welcome to Flashcard Studies ---   " << endl;
        cout << "******************************************" << endl;
        cout << "1. Load flashcard" << endl;
        cout << "2. Terminate program" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        cin.ignore();

        switch (userChoice) {
            case '1': {
                cout << endl;
                fstream file;
                string fileName = "flashcard.txt";
                try {
                    flashCardScoring.initialize(fileName);  //Initialize the flashcard
                } catch (const char* error) {
                    cout << "Error: " << error << endl;
                    break;
                }
                processFlashCardMenu(flashCardScoring);  //Process the flashcard menu
                break;
            }
            case '2': {
                char choice;
                do {
                    cout << "Are you sure you want to terminate the program? (Y/N): ";
                    cin >> choice;
                    cin.ignore();
                } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

                if (choice == 'y' || choice == 'Y') {
                    cout << "Terminating program............." << endl;
                    terminate = true;
                    cout << "Program terminated." << endl;
                }

                if (choice == 'n' || choice == 'N') {
                    cout << "Termination canceled.\n" << endl;
                }
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (!terminate);

    return 0;
}

template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardMenu(Score <T1, T2, T3, T4, T5> & flashCardScoring) {
    char userMenuChoice;
    bool exit = false;
    do {
        displayFlashCardMenu();
        do {
            cout << "Enter your choice: ";
            cin >> userMenuChoice;
            if (userMenuChoice < '1' || userMenuChoice > '5') {
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (userMenuChoice < '1' || userMenuChoice > '5');

        switch (userMenuChoice) {
            case '1': {
                cout << "\nDisplaying display flashcard menu......... " << endl;
                displayFlashCardDisplayChoice(flashCardScoring);
                break;
            }
            case '2': {
                cout << "\nInitializing search flashcard menu............" << endl;
                processFlashCardSearchChoice(flashCardScoring);
                break;
            }
            case '3': {
                cout << "\nDisplaying manage flashcard menu............. " << endl;
                displayFlashCardManageChoice(flashCardScoring);
                break;
            }
            case '4': {
                processFlashCardPlayGame(flashCardScoring);
                break;
            }
            case '5': {
                cout << "Exiting to main menu............\n" << endl;
                exit = true;
                break;
            }
        }
    } while (!exit);
}

void displayFlashCardMenu() {
    cout << "*****************************************" << endl;
    cout << "   --- Flashcard Studies Menu ---   " << endl;
    cout << "******************************************" << endl;
    cout << "1. Display flashcard" << endl;
    cout << "2. Search for a flashcard" << endl;
    cout << "3. Manage flashcard" << endl;
    cout << "4. Play flashcard game" << endl;
    cout << "5. Exit" << endl;
}

template <class T1, class T2, class T3, class T4, class T5>
void displayFlashCardDisplayChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring) {
    char displayChoice;
    char choice;
    do {
        do {
            cout << "+------------------------------------------+\n";
            cout << "1. Display all flashcards" << endl;
            cout << "2. Display all flashcards question" << endl;
            cout << "3. Display flashcard one by one" << endl;
            cout << "4. Exit" << endl;
            cout << "+------------------------------------------+\n";
            cout << "Enter your choice: ";
            cin >> displayChoice;
            cin.ignore();
            if (displayChoice < '1' || displayChoice > '4') {
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (displayChoice < '1' || displayChoice > '4');

        switch (displayChoice) {
            case '1': {
                cout << "Displaying all flashcards............\n";
                flashCardScoring.displayAllFlashCard();
                break;
            }
            case '2': {
                cout << "Displaying all flashcards question............\n";
                flashCardScoring.displayQuestionList();
                break;
            }
            case '3': {
                cout << "Displaying flashcard one by one............\n";
                flashCardScoring.displayFlashCardOneByOne();
                break;
            }
            case '4': {
                cout << "Back to Main Menu............" << endl;
                return;
            }
        }
        cout << "Do you want to display again? (Y/N): ";
        cin >> choice;
        cout << "\n";

    } while (choice == 'y' || choice == 'Y');
}

template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardSearchChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring) {
    string search;
    char searchChoice;
    char choice;
    do{
        do {
            processFlashCardSearchMenu(flashCardScoring);
            cout << "Enter your choice: ";
            cin >> searchChoice;
            cin.ignore();
            if (searchChoice < '1' || searchChoice > '6') {
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (searchChoice < '1' || searchChoice > '6');

        switch (searchChoice) {
            case '1': {
                flashCardScoring.displayQuestionList();
                do { 
                    cout << "eg. 5 + 3 = ?\n";
                    cout << "Enter the question to search: ";
                    getline(cin, search);
                } while (search == "" || !flashCardScoring.searchQuestionNode(search));
                break;
            }
            case '2': {
                do {
                    cout << "eg. What is 5 plus 3?\n";
                    cout << "Enter the description to search: ";
                    getline(cin, search);
                } while (search == "" || !flashCardScoring.searchDescription(search));
                break;
            }
            case '3': {
                char operationChar;
                    do {
                        cout << "\n+------------------------------------------+\n";
                        cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - Back to Search Menu\n";
                        cout << "+------------------------------------------+\n";
                        cout << "Enter the operation to search (1 - 4): ";
                        cout << "Enter 5 to go back to search menu\n";
                        cin >> operationChar;
                        cin.ignore();
                        if (operationChar < '1' || operationChar > '5') {
                            cout << "Invalid choice. Please try again." << endl;
                        } 
                    } while (operationChar < '1' || operationChar > '5');

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
                        case '5':
                            cout << "Back to Search Menu............" << endl;
                            return;
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
                string searchAnswer;
                cout << "Enter the answer to search: ";
                cin >> searchAnswer;
                cin.ignore();

                try {
                    if (flashCardScoring.searchAnswer(stod(searchAnswer)) == -1) {
                      throw "Answer not found.";
                    }
                } catch (const char* error) {
                    cout << "Error: " << error << endl;
                }

                do {
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input. Please enter a number:" << endl;
                        cout << "Enter the answer to search: ";
                        cin >> search;
                        cin.ignore();
                    }
                } while (cin.fail());

                break;
            }
            case '5': {
                int difficulty;
                char difficultyChar;
                do {
                    cout << "Enter the difficulty to search (1 - 5): ";
                    cin >> difficultyChar;
                    cin.ignore();
                    if (difficultyChar < '1' || difficultyChar > '5') {
                        cout << "Invalid choice. Please try again." << endl;
                    }

                    difficulty = difficultyChar - '0';

                    try {
                        if (flashCardScoring.searchDifficulty(difficulty) == -1) {  //Error end program after wrong search
                            throw "Difficulty not found.";
                        }
                    } catch (const char* error) {
                        cout << "Error: " << error << endl;
                    }
                    break;
                } while (difficultyChar < '1' || difficultyChar > '5');
            }
            case '6': {
                cout << "Back to Main Menu............" << endl;
                return;
            }
        }
        cout << "Do you want to search again? (Y/N): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardSearchMenu(Score <T1, T2, T3, T4, T5> & flashCardScoring) {
    cout << "+------------------------------------------+\n";
    cout << "1. Search by question" << endl;
    cout << "2. Search by description" << endl;
    cout << "3. Search by operation" << endl;
    cout << "4. Search by answer" << endl;
    cout << "5. Search by difficulty" << endl;
    cout << "6. Back to Main Menu" << endl;
    cout << "+------------------------------------------+\n";
}

template <class T1, class T2, class T3, class T4, class T5>
void displayFlashCardManageChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring) {
    char manageChoice;
    do {
        cout << "+------------------------------------------+\n";
        cout << "1. Add a flashcard" << endl;
        cout << "2. Edit a flashcard" << endl;
        cout << "3. Delete a flashcard" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "+------------------------------------------+\n";
        cout << "Enter your choice: ";
        cin >> manageChoice;
        cin.ignore();
        if (manageChoice < '1' || manageChoice > '4') {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (manageChoice < '1' || manageChoice > '4');

    switch (manageChoice) {
        case '1': {
            processFlashCardAddChoice(flashCardScoring, "flashcard.txt");
            break;
        }
        case '2': {
            processFlashCardEditChoice(flashCardScoring, "flashcard.txt");
            break;
        }
        case '3': {
            processFlashCardDeleteChoice(flashCardScoring, "flashcard.txt");
            break;
        }
        case '4': {
            cout << "Back to Main Menu............" << endl;
            break;
        }
    }
}

template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardAddChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring, string fileName) {
    char operationChoice;
    string choice;
    string question, description, operation;
    double answer;
    int difficulty;
    char difficultyChoice;

    do {
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
            cout << "1 - Addition\n2 - Subtraction\n3 - Multiplication\n4 - Division\nEnter the operation: ";
            cin >> operationChoice;
            if (operationChoice < '1' || operationChoice > '4') {
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (operationChoice < '1' || operationChoice > '4');

        switch (operationChoice) {
            case '1': {
                operation = "Addition";
                break;
            }
            case '2': {
                operation = "Subtraction";
                break;
            }
            case '3': {
                operation = "Multiplication";
                break;
            }
            case '4': {
                operation = "Division";
                break;
            }
        }

        do {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cout << "Enter the answer: ";
            cin >> answer;
        } while (cin.fail());
        
        do {
        cout << "Enter the difficulty: ";
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
    } while (choice == "y" || choice == "Y");
}

template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardEditChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring, string fileName) {
    string description, operation;
    double answer;
    int difficulty;
    string questionToEdit;
    char choice;

    do {
        flashCardScoring.displayQuestionList();

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

        //set the old card details
        flashCardScoring.displayFlashCardWithAnswer(questionToEdit);

        description = flashCardScoring.getDescriptionValue(questionToEdit);
        operation = flashCardScoring.getOperationValue(questionToEdit);
        answer = flashCardScoring.getAnswerValue(questionToEdit);
        difficulty = flashCardScoring.getDifficultyValue(questionToEdit);

        if (description == "") {
            //if question does not exist
            break;
        }

        char fieldChoice;
        do {
            cout << "While field to edit: " << endl;
            cout << "1. Description" << endl;
            cout << "2. Operation" << endl;
            cout << "3. Answer" << endl;
            cout << "4. Difficulty" << endl;
            cout << "Enter your choice: ";
            cin >> fieldChoice;
            cin.ignore();
            if (fieldChoice < '1' || fieldChoice > '4') {
                cout << "Invalid choice. Please try again." << endl;
            }
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

        cout << "Do you want to edit another card? (Y/N): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardDeleteChoice(Score <T1, T2, T3, T4, T5> & flashCardScoring, string fileName) {
    string questionToDelete;
    char confirmationChoice;
    char choice;

    do {
        flashCardScoring.displayQuestionList();
        do {
        cout << "Enter the question to delete: ";  //Error display twice
        getline(cin, questionToDelete);
        } while (questionToDelete == "");

        try {
            if (flashCardScoring.searchQuestionNode(questionToDelete) == -1) {
                throw "Question not found.";
            }
        } catch (const char* error) {
            cout << "Error:  " << error << endl;
            break;
        }

        do {
            cout << "Are you sure you want to delete the card? (Y/N): ";
            cin >> confirmationChoice;
            cin.ignore();
        } while (confirmationChoice != 'y' && confirmationChoice != 'Y' && confirmationChoice != 'n' && confirmationChoice != 'N');
        if (choice == 'n' || choice == 'N') {
            cout << "Delete action canceled." << endl;
            break;
        }
        flashCardScoring.deleteQuestionNode(fileName,questionToDelete);  //Error deleted multiple times

        cout << "Card deleted." << endl;
        cout << "Do you want to delete another card? (Y/N): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

template <class T1, class T2, class T3, class T4, class T5>
void processFlashCardPlayGame(Score <T1, T2, T3, T4, T5> & flashCardScoring) {
    string name;
    int age;
    char choice;
    int numQuestions;
    string question;
    double userAnswer;

    do {
            cout << "Playing flashcard game..." << endl;
            cout << "====================================" << endl;
            cout << setw(28) << left << "|| Number of questions: " << setw(5) << right << numberOfQuestions(flashCardScoring) << " ||" << endl;
            cout << setw(28) << left << "|| Average difficulty: " << setw(5) << right << averageDifficulty(flashCardScoring) << " ||" << endl;
            cout << "====================================" << endl;
            cout << "Enter your name:";
        do {
            getline(cin, name);
        } while (name == "");

        do {
            cout << "Enter your age: ";
            cin >> age;
            if (age < 1) {
                cout << "Invalid input. Please enter a number greater than 0." << endl;
            }
            if(cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (cin.fail() || age < 1);

        flashCardScoring.setName(name);
        flashCardScoring.setAge(age);

        do {
            cout << "How many question do you want to answer? ";
            cin >> numQuestions;
            if (numQuestions < 1) {
                cout << "Invalid input. Please enter a number greater than 0." << endl;
            }
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
                    cout << "Invalid input. Please enter a number:" << endl;
                }
            cout << "Enter your answer: ";
            cin >> userAnswer;
            } while (cin.fail());

            flashCardScoring.updateScore(question, userAnswer);
        }
        flashCardScoring.displayScore();
        flashCardScoring.resetScore();
        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}