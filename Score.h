#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "FlashCard.h"

template <class T1, class T2, class T3, class T4, class T5>
class Score : public FlashCard<T1, T2, T3, T4, T5> {
  private:
    string name;
    int age;

    int correct;
    int incorrect;
    int total;
    double percentage;
  public:
    Score();

    void updateScore(T1 question, T4 userAnswer);
    void displayScore() const;
    void resetScore();

    // Mutators
    void setName(string name);
    void setAge(int age);
};

#endif