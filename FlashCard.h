#ifndef FLASH_CARD_H
#define FLASH_CARD_H

#include <iostream>
#include <string>
#include <iomanip>
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

    void editNode(T1 question, T2 description, T3 operation, T4 answer, T5 difficulty);
    void searchQuestionNode(T1 question) const;
    void searchNode(T1 question, string field) const;

    void deleteQuestionNode(T1 question);

    ~FlashCard();

    void insertNode(T1 question, T2 description, T3 operation, T4 answer, T5 difficulty);

    void displayAllFlashCard() const;

    void displayQuestionList() const;
    void displayFlashCard(T1 question) const;

    void displayFlashCardOneByOne() const;
};

#endif