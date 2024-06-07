#ifndef FLASH_CARD_H
#define FLASH_CARD_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "DoublyLinkedList.h"

template <class T1, class T2, class T3, class T4, class T5>
class FlashCard {
  private:
    DoublyLinkedList <T1, T1> questions;
    DoublyLinkedList <T1, T2> descriptions;
    DoublyLinkedList <T1, T3> operations;
    DoublyLinkedList <T1, T4> answers;
    DoublyLinkedList <T1, T5> difficulties;
  public:
    FlashCard();

    void editCard(T1 question, T2 description, T3 operation, T4 answer, T5 difficulty);
    void displayDataField(T1 question, string field) const;

    int searchQuestionNode(T1 question) const;
    void searchDescription(T2 data) const;
    void searchOperation(T3 data) const;
    void searchAnswer(T4 data) const;
    void searchDifficulty(T5 data) const;

    void deleteQuestionNode(T1 question);

    ~FlashCard();

    void insertNode(T1 question, T2 description, T3 operation, T4 answer, T5 difficulty);

    void displayAllFlashCard() const;
    void displayQuestionList() const;
    void displayFlashCardNoAnswer(T1 question) const;
    void displayFlashCardWithAnswer(T1 question) const;

    void displayFlashCardOneByOne() const;
    T1 displayRandomFlashCard() const;

    T2 getDescritionValue(T1 question) const;
    T3 getOperationValue(T1 question) const;
    T4 getAnswerValue(T1 question) const;
    T5 getDifficultyValue(T1 question) const;

    void accessQuestions(DoublyLinkedList<T1, T1>& list);
};

#endif