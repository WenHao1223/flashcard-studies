#include "FlashCard.h"

template <class T1, class T2, class T3, class T4, class T5>
FlashCard<T1, T2, T3, T4, T5>::FlashCard() {}

template <class T1, class T2, class T3, class T4, class T5>
FlashCard<T1, T2, T3, T4, T5>::~FlashCard() {}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::initialize(string fileName) {
  // destruct the current flash card object before initializing a new one
  questions.~DoublyLinkedList();
  descriptions.~DoublyLinkedList();
  operations.~DoublyLinkedList();
  answers.~DoublyLinkedList();
  difficulties.~DoublyLinkedList();

  ifstream file;
  T1 question;
  T2 description;
  T3 operation;
  T4 answer;
  T5 difficulty;

  try {
    do {
      file.open(fileName, ios::in);

      if(!file) {
        throw "File not found.";
      }
    } while (!file);
  } catch (char const* error) {
    throw error;
  }
  
  while (!file.eof()) {
    getline(file, question, '\t');

    // check if question only contains '\n' (last line of the file)
    if (question == "") {
      continue;
    }

    // check if question contains '\n'
    if (question.find('\n') != string::npos) {
      question = question.substr(1, question.length());
    }

    getline(file, description, '\t');
    getline(file, operation, '\t');
    file >> answer;
    file.ignore();
    file >> difficulty;
    file.ignore();

    insertNode(question, description, operation, answer, difficulty);
  }
  file.close();
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::editCard(string fileName, T1 question, T2 description, T3 operation, T4 answer, T5 difficulty) {
  cout << "Editing question: " << question << endl;
  if (questions.searchQuestionNode(question) == -1) {
    cout << "Question not found." << endl;
    // exit the function
    return;
  }
  descriptions.editNode(question, description);
  operations.editNode(question, operation);
  answers.editNode(question, answer);
  difficulties.editNode(question, difficulty);

  /// file handling
  fstream file;
  file.open(fileName, ios::in);
  string line;
  string questionLine = "";
  string newFileLines = "";

  while (!file.eof()) {
    getline(file, questionLine, '\t');
    getline(file, line);

    // check if questionLine contains '\n'
    if (questionLine.find('\n') != string::npos) {
      questionLine = questionLine.substr(1, questionLine.length());
    }

    if (questionLine == question) {
      newFileLines += question + "\t" + description + "\t" + operation + "\t" + to_string(answer) + "\t" + to_string(difficulty) + "\n";
    } else {
      newFileLines += questionLine + "\t" + line + "\n";
    }
  }

  // Remove last line
  newFileLines = newFileLines.substr(0, newFileLines.length()-1);
  file.close();

  file.open(fileName, ios::out);
  file << newFileLines;
  file.close();

  cout << "Card edited. " << endl;
  displayFlashCardWithAnswer(question);
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayDataField(T1 question, string field) const {
  if (field == "Description") {
    descriptions.displayNode(question, field);
  } else if (field == "Operation") {
    operations.displayNode(question, field);
  } else if (field == "Answer") {
    answers.displayNode(question, field);
  } else if (field == "Difficulty") {
    difficulties.displayNode(question, field);
  }
}

template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchQuestionNode(T1 question) const {
  cout << "Searching for question: " << question << endl;
  int result = questions.searchQuestionNode(question);
  
  if (result)
    displayFlashCardWithAnswer(question);
    
  return result;
}

template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchDescription(T2 data) const {
  cout << "Searching for description: " << data << endl;
  return descriptions.searchNode(data);
}

template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchOperation(T3 data) const {
  cout << "Searching for operation: " << data << endl;
  return operations.searchNode(data);
}

template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchAnswer(T4 data) const {
  cout << "Searching for answer: " << data << endl;
  return answers.searchNode(data);
}

template <class T1, class T2, class T3, class T4, class T5>
int FlashCard<T1, T2, T3, T4, T5>::searchDifficulty(T5 data) const {
  cout << "Searching for difficulty: " << data << endl;
  return difficulties.searchNode(data);
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::deleteQuestionNode(string fileName, T1 question) {
  cout << "Deleting question: " << question << endl;
  questions.deleteQuestionNode(question);
  descriptions.deleteNode(descriptions.getNodeValue(question));
  operations.deleteNode(operations.getNodeValue(question));
  answers.deleteNode(answers.getNodeValue(question));
  difficulties.deleteNode(difficulties.getNodeValue(question));

  fstream file;
  file.open(fileName, ios::in);
  string line;
  string questionLine = "";
  string newFileLines = "";

  while (!file.eof()) {
    getline(file, questionLine, '\t');
    getline(file, line);

    // check if questionLine contains '\n'
    if (questionLine.find('\n') != string::npos) {
      questionLine = questionLine.substr(1, questionLine.length());
    }

    if (questionLine != question) {
      newFileLines += questionLine + "\t" + line + "\n";
    }
  }

  // Remove last line
  newFileLines = newFileLines.substr(0, newFileLines.length()-1);
  file.close();

  file.open(fileName, ios::out);
  file << newFileLines;
  file.close();
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::insertNode(T1 question, T2 description, T3 operation, T4 answer, T5 difficulty) {
  // cout << "Inserting question: " << question << endl;

  questions.insertNode(question, question);
  descriptions.insertNode(question, description);
  operations.insertNode(question, operation);
  answers.insertNode(question, answer);
  difficulties.insertNode(question, difficulty);

  // cout << "Inserted question: " << question << endl;
  // displayFlashCardWithAnswer(question);
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayAllFlashCard() const {
  T1 currentQuestion = questions.getHeadValue();
  displayFlashCardWithAnswer(currentQuestion);
  do {
    currentQuestion = questions.getNextNodeValue(currentQuestion);
    displayFlashCardWithAnswer(currentQuestion);
  } while (currentQuestion != questions.getTailValue());
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayQuestionList() const {
  questions.displayQuestionList();
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayFlashCardNoAnswer(T1 question) const {
  const string border = "+------------------------------------------------------------------------------------------------------+";

  cout << border << endl;
  cout << "| " << setw(100) << left << "Difficulty: " + to_string(difficulties.getNodeValue(question)) << " |" << endl;
  cout << "| " << setw(100) << left << " " << " |" << endl;
  cout << "| " << setw(100) << left << questions.getNodeValue(question) << " |" << endl;
  cout << "| " << setw(100) << left << descriptions.getNodeValue(question) << " |" << endl;
  cout << "| " << setw(100) << left << ("<" + operations.getNodeValue(question) + ">") << " |" << endl;
  cout << "| " << setw(100) << left << " " << " |" << endl;
  cout << border << endl;
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayFlashCardWithAnswer(T1 question) const {
  const string border = "+------------------------------------------------------------------------------------------------------+";

  cout << border << endl;
  if (questions.searchQuestionNode(question) != -1) {
    cout << "| " << setw(100) << left << "Difficulty: " + to_string(difficulties.getNodeValue(question)) << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << questions.getNodeValue(question) << " |" << endl;
    cout << "| " << setw(100) << left << descriptions.getNodeValue(question) << " |" << endl;
    cout << "| " << setw(100) << left << ("<" + operations.getNodeValue(question) + ">") << " |" << endl;
    cout << "| " << setw(100) << left << " " << " |" << endl;
    cout << "| " << setw(100) << left << answers.getNodeValue(question) << " |" << endl;
  } else {
    cout << "| " << setw(100) << left << "Question not found." << " |" << endl;
  }
  cout << border << endl;
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayFlashCardOneByOne() const {
  // can press j or k to go forward or next
  // can press q to quit

  T1 question = questions.getHeadValue();
  displayFlashCardWithAnswer(question);

  char key;
  while (key != 'q') {
    cout << "Press j to go back, k to go next, and q to quit" << endl;
    do {
      cout << "Option: ";
      cin >> key;
      cin.ignore();
    } while (key != 'j' && key != 'k' && key != 'q');
    
    const string border = "+------------------------------------------------------------------------------------------------------+";
    const string notFoundMesage = "|                                     Flash card reached the end.                                      |";
    if (key == 'j') {
      if (question == questions.getHeadValue()) {
        cout << border << endl;
        cout << notFoundMesage << endl;
        cout << border << endl;
        displayFlashCardWithAnswer(question);
      } else {
        question = questions.getPreviousNodeValue(question);
        displayFlashCardWithAnswer(question);
      }
    } else if (key == 'k') {
      if (question == questions.getTailValue()) {
        cout << border << endl;
        cout << notFoundMesage << endl;
        cout << border << endl;
        displayFlashCardWithAnswer(question);
      } else {
        question = questions.getNextNodeValue(question);
        displayFlashCardWithAnswer(question);
      }
    } else if (key == 'q') {
      cout << "Quitting..." << endl;
    } else {
      cout << "Invalid option." << endl;
    }
  }
}

template <class T1, class T2, class T3, class T4, class T5>
T1 FlashCard<T1, T2, T3, T4, T5>::displayRandomFlashCard() const {
  int random = rand() % questions.getNumberOfNodes();
  // cout << "Random index: " << random << endl;
  T1 question = questions.getHeadValue();
  for (int i = 0; i < random; i++) {
    if (question == questions.getTailValue()) {
      break;
    }
    question = questions.getNextNodeValue(question);
  }

  displayFlashCardNoAnswer(question);

  return question;
}

template <class T1, class T2, class T3, class T4, class T5>
T2 FlashCard<T1, T2, T3, T4, T5>::getDescriptionValue(T1 question) const {
  return descriptions.getNodeValue(question);
}

template <class T1, class T2, class T3, class T4, class T5>
T3 FlashCard<T1, T2, T3, T4, T5>::getOperationValue(T1 question) const {
  return operations.getNodeValue(question);
}

template <class T1, class T2, class T3, class T4, class T5>
T4 FlashCard<T1, T2, T3, T4, T5>::getAnswerValue(T1 question) const {
  return answers.getNodeValue(question);
}

template <class T1, class T2, class T3, class T4, class T5>
T5 FlashCard<T1, T2, T3, T4, T5>::getDifficultyValue(T1 question) const {
  return difficulties.getNodeValue(question);
}

template class FlashCard<string, string, string, double, int>;