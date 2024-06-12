#include "FlashCard.h" // preprocessor directive to include the FlashCard header file

/**
 * @file FlashCard.cpp
 * @brief Implementation file for the FlashCard class.
 * @details This file contains the implementation of the FlashCard class, which represents a flashcard.
 * The FlashCard class is a template class that takes five template parameters: T1, T2, T3, T4, and T5.
 * It provides functionality to initialize, edit, search, delete, insert, and display flashcards.
 */

/**
 * @class FlashCard
 * @brief Represents a flashcard.
 * @details The FlashCard class is a template class that takes five template parameters: T1, T2, T3, T4, and T5.
 * It provides functionality to initialize, edit, search, delete, insert, and display flashcards.
 * @tparam T1 The type of the question.
 * @tparam T2 The type of the description.
 * @tparam T3 The type of the operation.
 * @tparam T4 The type of the answer.
 * @tparam T5 The type of the difficulty.
 */

/**
 * @brief Default constructor for the FlashCard class.
 */
template <class T1, class T2, class T3, class T4, class T5>
FlashCard<T1, T2, T3, T4, T5>::FlashCard() {}

/**
 * @brief Initializes the flashcard from a file.
 * @param fileName The name of the file to read from.
 */
template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::initialize(string fileName) {
  // Destruct the current flash card object before initializing a new one
  questions.~DoublyLinkedList(); // call the destructor of the questions.
  descriptions.~DoublyLinkedList(); // call the destructor of the descriptions.
  operations.~DoublyLinkedList(); // call the destructor of the operations.
  answers.~DoublyLinkedList(); // call the destructor of the answers.
  difficulties.~DoublyLinkedList(); // call the destructor of the difficulties.

  ifstream file; // variable to read from the file
  T1 question; // variable to store the question with type T1
  T2 description; // variable to store the description with type T2
  T3 operation; // variable to store the operation with type T3
  T4 answer; // variable to store the answer with type T4
  T5 difficulty; // variable to store the difficulty with type T5

  // try-catch block to handle exceptions
  // open the file and read the data
  // if the file is not found, throw an exception
  try {
    do {
      file.open(fileName, ios::in); // open the file in read mode

      // check if the file is not found
      if(!file) {
        throw "File not found."; // throw an exception
      }
    } while (!file); // repeat the loop until the file is found
  } catch (char const* error) { // catch the exception
    throw error; // throw the error
  }
  
  // read the data from the file
  while (!file.eof()) {
    getline(file, question, '\t'); // read the question from the file

    // check if question only contains '\n' (last line of the file)
    if (question == "") {
      continue;
    }

    // check if question contains '\n'
    if (question.find('\n') != string::npos) {
      question = question.substr(1, question.length()); // remove the first character
    }

    getline(file, description, '\t'); // read the description from the file
    getline(file, operation, '\t'); // read the operation from the file
    file >> answer; // read the answer from the file
    file.ignore(); // ignore the newline character
    file >> difficulty; // read the difficulty from the file
    file.ignore(); // ignore the newline character

    insertNode(question, description, operation, answer, difficulty); // insert the data into the flashcard
  }
  file.close(); // close the file
}

/**
 * @brief Edits a flashcard.
 * @param fileName The name of the file to write to.
 * @param question The new question.
 * @param description The new description.
 * @param operation The new operation.
 * @param answer The new answer.
 * @param difficulty The new difficulty.
 */
template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::editCard(string fileName, T1 question, T2 description, T3 operation, T4 answer, T5 difficulty) {
  cout << "Editing question: " << question << endl;
  // check if the question is not found
  if (questions.searchQuestionNode(question) == -1) {
    cout << "Question not found." << endl;
    return;
  }
  descriptions.editNode(question, description); // edit the description based on the question
  operations.editNode(question, operation); // edit the operation based on the question
  answers.editNode(question, answer); // edit the answer based on the question
  difficulties.editNode(question, difficulty); // edit the difficulty based on the question

  /// file handling
  fstream file; // variable to read and write to the file
  file.open(fileName, ios::in); // open the file in read mode
  string line; // variable to store the line read from the file
  string questionLine = ""; // variable to store the question line read from the file
  string newFileLines = ""; // variable to store the new file lines

  // read the data from the file
  while (!file.eof()) {
    getline(file, questionLine, '\t'); // read the question from the file (separated by '\t')
    getline(file, line); // read the line from the file

    // check if questionLine contains '\n'
    if (questionLine.find('\n') != string::npos) {
      questionLine = questionLine.substr(1, questionLine.length()); // remove the first character
    }

    // check if the question line is the same as the question
    if (questionLine == question) {
      newFileLines += question + "\t" + description + "\t" + operation + "\t" + to_string(answer) + "\t" + to_string(difficulty) + "\n"; // add the new data to the file
    } else { // if the question line is not the same as the question
      newFileLines += questionLine + "\t" + line + "\n"; // add the existing data to the file
    }
  }

  newFileLines = newFileLines.substr(0, newFileLines.length() - 1); // remove the last line
  file.close(); // close the file

  file.open(fileName, ios::out); // open the file in write mode
  file << newFileLines; // write the new data to the file
  file.close(); // close the file

  cout << "Card edited. " << endl;
  displayFlashCardWithAnswer(question); // display the flashcard with the answer
}

/**
 * @brief Displays the value of a specific data field for a given question.
 * @param question The question to search for.
 * @param field The data field to display.
 */
template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayDataField(T1 question, string field) const {
  // check the field to display 
  if (field == "Description") {
    descriptions.displayNode(question, field); // display the description based on the question
  } else if (field == "Operation") {
    operations.displayNode(question, field); // display the operation based on the question
  } else if (field == "Answer") {
    answers.displayNode(question, field); // display the answer based on the question
  } else if (field == "Difficulty") {
    difficulties.displayNode(question, field); // display the difficulty based on the question
  }
}

/**
 * @brief Searches for a question node in the flashcard.
 * @param question The question to search for.
 * @return The index of the question node if found, -1 otherwise.
 */
template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchQuestionNode(T1 question) const {
  cout << "Searching for question: " << question << endl;
  int result = questions.searchQuestionNode(question); // search for the question in the flashcard
  
  // check if the question is found
  if (result)
    displayFlashCardWithAnswer(question); // display the flashcard with the answer
    
  return result; // return the result
}

/**
 * @brief Searches for a description in the flashcard.
 * @param data The description to search for.
 * @return The index of the description if found, -1 otherwise.
 */
template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchDescription(T2 data) const {
  cout << "Searching for description: " << data << endl;
  return descriptions.searchNode(data); // search for the description in the flashcard
}

/**
 * @brief Searches for an operation in the flashcard.
 * @param data The operation to search for.
 * @return The index of the operation if found, -1 otherwise.
 */
template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchOperation(T3 data) const {
  cout << "Searching for operation: " << data << endl;
  return operations.searchNode(data); // search for the operation in the flashcard
}

/**
 * @brief Searches for an answer in the flashcard.
 * @param data The answer to search for.
 * @return The index of the answer if found, -1 otherwise.
 */
template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchAnswer(T4 data) const {
  cout << "Searching for answer: " << data << endl;
  return answers.searchNode(data); // search for the answer in the flashcard
}

/**
 * @brief Searches for a difficulty in the flashcard.
 * @param data The difficulty to search for.
 * @return The index of the difficulty if found, -1 otherwise.
 */
template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchDifficulty(T5 data) const {
  cout << "Searching for difficulty: " << data << endl;
  return difficulties.searchNode(data); // search for the difficulty in the flashcard
}

/**
 * @brief Deletes a question node from the flashcard.
 * @param fileName The name of the file to write to.
 * @param question The question to delete.
 */
template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::deleteQuestionNode(string fileName, T1 question) {
  cout << "Deleting question: " << question << endl;
  questions.deleteQuestionNode(question); // delete the question node
  descriptions.deleteQuestionNode(question); // delete the description node
  operations.deleteQuestionNode(question); // delete the operation node
  answers.deleteQuestionNode(question); // delete the answer node
  difficulties.deleteQuestionNode(question); // delete the difficulty node
  cout << "Question '" << question <<"' deleted." << endl;

  fstream file; // variable to read and write to the file
  file.open(fileName, ios::in); // open the file in read mode
  string line; // variable to store the line read from the file
  string questionLine = ""; // variable to store the question line read from the file
  string newFileLines = ""; // variable to store the new file lines

  // read the data from the file
  while (!file.eof()) {
    getline(file, questionLine, '\t'); // read the question from the file (separated by '\t')
    getline(file, line); // read the line from the file

    // check if questionLine contains '\n'
    if (questionLine.find('\n') != string::npos) {
      questionLine = questionLine.substr(1, questionLine.length()); // remove the first character
    }

    // check if the question line is the same as the question
    if (questionLine != question) {
      newFileLines += questionLine + "\t" + line + "\n"; // add the existing data to the file
    }
  }

  newFileLines = newFileLines.substr(0, newFileLines.length() - 1); // remove the last line
  file.close(); // close the file

  file.open(fileName, ios::out); // open the file in write mode
  file << newFileLines; // write the new data to the file
  file.close(); // close the file
}

/**
 * @brief Destructor for the FlashCard class.
 */
template <class T1, class T2, class T3, class T4, class T5>
FlashCard<T1, T2, T3, T4, T5>::~FlashCard() {}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::insertNode(T1 question, T2 description, T3 operation, T4 answer, T5 difficulty) {
  questions.insertNode(question, question); // insert the question into the flashcard
  descriptions.insertNode(question, description); // insert the description into the flashcard
  operations.insertNode(question, operation); // insert the operation into the flashcard
  answers.insertNode(question, answer); // insert the answer into the flashcard
  difficulties.insertNode(question, difficulty); // insert the difficulty into the flashcard
}

/**
 * @brief Displays all flashcards.
 */
template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayAllFlashCard() const {
  T1 currentQuestion = questions.getHeadValue(); // get the head value of the questions
  displayFlashCardWithAnswer(currentQuestion); // display the flashcard with the answer

  do {
    currentQuestion = questions.getNextNodeValue(currentQuestion); // get the next node value
    displayFlashCardWithAnswer(currentQuestion); // display the flashcard with the answer
  } while (currentQuestion != questions.getTailValue()); // repeat the loop until the current question is the tail value
}

/**
 * @brief Displays the list of questions.
 */
template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayQuestionList() const {
  questions.displayQuestionList(); // display the list of questions
}

/**
 * @brief Displays a flashcard without the answer.
 * @param question The question to display.
 */
template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayFlashCardNoAnswer(T1 question) const {
  const string border = "+------------------------------------------------------------------------------------------------------+"; // Border for the flashcard display

  cout << border << endl;
  cout << "| " << setw(100) << left << "Difficulty: " + to_string(difficulties.getNodeValue(question)) << " |" << endl;
  cout << "| " << setw(100) << left << " " << " |" << endl;
  cout << "| " << setw(100) << left << questions.getNodeValue(question) << " |" << endl;
  cout << "| " << setw(100) << left << descriptions.getNodeValue(question) << " |" << endl;
  cout << "| " << setw(100) << left << ("<" + operations.getNodeValue(question) + ">") << " |" << endl;
  cout << "| " << setw(100) << left << " " << " |" << endl;
  cout << border << endl;
}

/**
 * @brief Displays a flashcard with the answer.
 * @param question The question to display.
 */
template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayFlashCardWithAnswer(T1 question) const {
  const string border = "+------------------------------------------------------------------------------------------------------+"; // Border for the flashcard display

  cout << border << endl;

  // check if the question is found
  if (questions.searchQuestionNode(question) != -1) {
    cout << "| " << setw(100) << left << "Difficulty: " + to_string(difficulties.getNodeValue(question)) << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << questions.getNodeValue(question) << " |" << endl;
    cout << "| " << setw(100) << left << descriptions.getNodeValue(question) << " |" << endl;
    cout << "| " << setw(100) << left << ("<" + operations.getNodeValue(question) + ">") << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << answers.getNodeValue(question) << " |" << endl;
  } else { // if the question is not found
    cout << "| " << setw(100) << left << "Question not found." << " |" << endl;
  }
  cout << border << endl;
}

/**
 * @brief Displays flashcards one by one.
 */
template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayFlashCardOneByOne() const {
  // can press j or k to go forward or next
  // can press q to quit

  T1 question = questions.getHeadValue(); // get the head value of the questions
  displayFlashCardWithAnswer(question); // display the flashcard with the answer

  char key; // variable to store the key pressed

  // repeat the loop until the key is not 'q'
  while (key != 'q') {
    cout << "Press j to go back, k to go next, and q to quit" << endl;
    do {
      cout << "Option: ";
      cin >> key;
      cin.ignore();
    } while (key != 'j' && key != 'k' && key != 'q'); // repeat the loop until the key is not 'j', 'k', or 'q'
    
    const string border = "+------------------------------------------------------------------------------------------------------+"; // Border for the flashcard display
    const string notFoundMesage = "|                                     Flash card reached the end.                                      |"; // Message for the end of the flashcard
    
    // check the key pressed
    // if the key is 'j', go back
    if (key == 'j') {
      // check if the question is the head value
      if (question == questions.getHeadValue()) { 
        cout << border << endl;
        cout << notFoundMesage << endl;
        cout << border << endl;
        displayFlashCardWithAnswer(question); // display the flashcard with the answer
      } else {
        question = questions.getPreviousNodeValue(question); // get the previous node value
        displayFlashCardWithAnswer(question); // display the flashcard with the answer
      }
    // if the key is 'k', go next
    } else if (key == 'k') {
      // check if the question is the tail value
      if (question == questions.getTailValue()) {
        cout << border << endl;
        cout << notFoundMesage << endl;
        cout << border << endl;
        displayFlashCardWithAnswer(question); // display the flashcard with the answer
      // if the question is not the tail value
      } else {
        question = questions.getNextNodeValue(question); // get the next node value
        displayFlashCardWithAnswer(question); // display the flashcard with the answer
      }
    // if the key is 'q', quit
    } else if (key == 'q') {
      cout << "Quitting..." << endl;
    // if the key is not 'j', 'k', or 'q', display an error message
    } else {
      cout << "Invalid option." << endl;
    }
  }
}

/**
 * @brief Displays a random flashcard.
 * @return The question of the random flashcard.
 */
template <class T1, class T2, class T3, class T4, class T5>
T1 FlashCard<T1, T2, T3, T4, T5>::displayRandomFlashCard() const {
  int random = rand() % questions.getNumberOfNodes(); // get a random number
  T1 question = questions.getHeadValue(); // get the head value of the questions

  // repeat the loop until the random number
  for (int i = 0; i < random; i++) {
    // check if the question is the tail value
    if (question == questions.getTailValue()) {
      break;
    }
    question = questions.getNextNodeValue(question); // get the next node value
  }

  displayFlashCardNoAnswer(question); // display the flashcard without the answer

  return question; // return the question
}

/**
 * @brief Gets the description value for a given question.
 * @param question The question to search for.
 * @return The description value if found, an empty string otherwise.
 */
template <class T1, class T2, class T3, class T4, class T5>
T2 FlashCard<T1, T2, T3, T4, T5>::getDescriptionValue(T1 question) const {
  return descriptions.getNodeValue(question); // get the description value based on the question
}


/**
 * @brief Gets the operation value for a given question.
 * @param question The question to search for.
 * @return The operation value if found, an empty string otherwise.
 */
template <class T1, class T2, class T3, class T4, class T5>
T3 FlashCard<T1, T2, T3, T4, T5>::getOperationValue(T1 question) const {
  return operations.getNodeValue(question); // get the operation value based on the question
}

/**
 * @brief Gets the answer value for a given question.
 * @param question The question to search for.
 * @return The answer value if found, an empty string otherwise.
 */
template <class T1, class T2, class T3, class T4, class T5>
T4 FlashCard<T1, T2, T3, T4, T5>::getAnswerValue(T1 question) const {
  return answers.getNodeValue(question); // get the answer value based on the question
}

/**
 * @brief Gets the difficulty value for a given question.
 * @param question The question to search for.
 * @return The difficulty value if found, an empty string otherwise.
 */
template <class T1, class T2, class T3, class T4, class T5>
T5 FlashCard<T1, T2, T3, T4, T5>::getDifficultyValue(T1 question) const {
  return difficulties.getNodeValue(question); // get the difficulty value based on the question
}

// Explicit instantiation of the FlashCard class.
// This is done to avoid linking errors.
// The template class is instantiated for the following types:
// - T1: string
// - T2: string
// - T3: string
// - T4: double
// - T5: int
template class FlashCard<string, string, string, double, int>;