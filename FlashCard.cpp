#include "FlashCard.h"

template <class T1, class T2, class T3, class T4, class T5>
FlashCard<T1, T2, T3, T4, T5>::FlashCard() {}

template <class T1, class T2, class T3, class T4, class T5>
FlashCard<T1, T2, T3, T4, T5>::~FlashCard() {}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::editNode(T1 question, T2 description, T3 operation, T4 answer, T5 difficulty) {
  cout << "Editing question: " << question << endl;
  if (questions.searchQuestionNode(question) == -1) {
    cout << "Question not found." << endl;
    // exit the function
    return;
  }
  operations.editNode(question, operation);
  answers.editNode(question, answer);
  difficulties.editNode(question, difficulty);

  cout << "Question edited. " << endl;
  displayFlashCardWithAnswer(question);
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::searchQuestionNode(T1 question) const {
  questions.searchQuestionNode(question);
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::searchNode(T1 question, string field) const {
  if (field == "description") {
    descriptions.displayList();
  } else if (field == "operation") {
    operations.displayList();
  } else if (field == "answer") {
    answers.displayList();
  } else if (field == "difficulty") {
    difficulties.displayList();
  }
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::deleteQuestionNode(T1 question) {
  questions.deleteQuestionNode(question);
  descriptions.deleteQuestionNode(question);
  operations.deleteQuestionNode(question);
  answers.deleteQuestionNode(question);
  difficulties.deleteQuestionNode(question);
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
  T1 currentQuestion = questions.getNextNodeValue(T1());
  while (currentQuestion != "") {
    displayFlashCardWithAnswer(currentQuestion);
    currentQuestion = questions.getNextNodeValue(currentQuestion);
  }
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
    cout << "| " << setw(100) << left << "Question reached the end." << " |" << endl;
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

template class FlashCard<string, string, string, double, int>;