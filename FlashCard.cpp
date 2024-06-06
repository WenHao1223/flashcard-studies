#include "FlashCard.h"

template <class T1, class T2, class T3, class T4, class T5>
FlashCard<T1, T2, T3, T4, T5>::FlashCard() {}

template <class T1, class T2, class T3, class T4, class T5>
FlashCard<T1, T2, T3, T4, T5>::~FlashCard() {}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::editNode(T1 question, T2 description, T3 operation, T4 answer, T5 difficulty) {
  questions.editNode(question, description);
  descriptions.editNode(question, description);
  operations.editNode(question, operation);
  answers.editNode(question, answer);
  difficulties.editNode(question, difficulty);
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
  questions.insertNode(question, description);
  descriptions.insertNode(question, description);
  operations.insertNode(question, operation);
  answers.insertNode(question, answer);
  difficulties.insertNode(question, difficulty);
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayAllFlashCard() const {
  questions.displayList();
  descriptions.displayList();
  operations.displayList();
  answers.displayList();
  difficulties.displayList();
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayQuestionList() const {
  questions.displayList();
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayFlashCard(T1 question) const {
  questions.searchQuestionNode(question);
  descriptions.searchQuestionNode(question);
  operations.searchQuestionNode(question);
  answers.searchQuestionNode(question);
  difficulties.searchQuestionNode(question);
}

template <class T1, class T2, class T3, class T4, class T5>
void FlashCard<T1, T2, T3, T4, T5>::displayFlashCardOneByOne() const {
  // can press j or k to go forward or next
  // can press q to quit
  
  questions.displayList();
  descriptions.displayList();
  operations.displayList();
  answers.displayList();
  difficulties.displayList();

  cout << "Press j to go forward, k to go back, and q to quit" << endl;
  char key;
  while (key != 'q') {
    cin >> key;
    if (key == 'j') {
      questions.displayList();
      descriptions.displayList();
      operations.displayList();
      answers.displayList();
      difficulties.displayList();
    } else if (key == 'k') {
      questions.displayList();
      descriptions.displayList();
      operations.displayList();
      answers.displayList();
      difficulties.displayList();
    }
  }
}

template class FlashCard<string, string, string, double, int>;