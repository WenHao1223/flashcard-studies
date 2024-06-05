#ifndef ANSWER_LIST_H
#define ANSWER_LIST_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublyLinkedList.h"

template <class T>
class AnswerList : public DoublyLinkedList <T> {
  private:
    T answer;
  public:
    // constructor
    AnswerList();
    // destructor
    ~AnswerList();

    // mutator
    void setAnswer(T answer);
    // accessor
    T getAnswer() const;
};

template class AnswerList <string>;
template class AnswerList <int>;
template class AnswerList <char>;
template class AnswerList <double>;
template class AnswerList <float>;

#endif