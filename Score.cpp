#include "Score.h"

template <class T1, class T2, class T3, class T4, class T5>
Score<T1, T2, T3, T4, T5>::Score() {
  correct = 0;
  incorrect = 0;
  total = 0;
  percentage = 0.0;
}

template <class T1, class T2, class T3, class T4, class T5>
void Score<T1, T2, T3, T4, T5>::updateScore(T1 question, T4 userAnswer) {
  T4 answer = FlashCard<T1, T2, T3, T4, T5>::getAnswerValue(question);
  bool isCorrect = userAnswer == answer;

  if (isCorrect) {
    correct++;
  } else {
    incorrect++;
  }
  total++;
  percentage = (static_cast<double>(correct) / total) * 100;
}

template <class T1, class T2, class T3, class T4, class T5>
void Score<T1, T2, T3, T4, T5>::displayScore() const {
  const string border = "+------------------------------------------+";
  cout << border << endl;
  cout << "| " << setw(40) << left << "Name: " + name << " |" << endl;
  cout << "| " << setw(40) << left << "Age: " + to_string(age) << " |" << endl;
  cout << "| " << setw(40) << left << " " << " |" << endl;
  cout << "| " << setw(40) << left << "Score" << " |" << endl;
  cout << "| " << setw(40) << left << "Correct: " + to_string(correct) << " |" << endl;
  cout << "| " << setw(40) << left << "Incorrect: " + to_string(incorrect) << " |" << endl;
  cout << "| " << setw(40) << left << "Total: " + to_string(total) << " |" << endl;
  cout << "| " << setw(40) << left << "Percentage: " + to_string(percentage) + "%" << " |" << endl;
  cout << border << endl;
}

template <class T1, class T2, class T3, class T4, class T5>
void Score<T1, T2, T3, T4, T5>::resetScore() {
  correct = 0;
  incorrect = 0;
  total = 0;
  percentage = 0.0;
}

template class Score<string, string, string, double, int>;