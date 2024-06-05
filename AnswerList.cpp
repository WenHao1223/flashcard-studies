#include "AnswerList.h"

template <class T>
AnswerList<T>::AnswerList() {}

template <class T>
AnswerList<T>::~AnswerList() {}

template <class T>
void AnswerList<T>::setAnswer(T answer) {
  this->answer = answer;
}

template <class T>
T AnswerList<T>::getAnswer() const {
  return answer;
}