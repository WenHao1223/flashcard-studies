#ifndef SCORE_H
#define SCORE_H

#include <iostream> // for input / output stream
#include <string> // for string manipulation
#include <iomanip> // for input / output manipulation
using namespace std;

#include "FlashCard.h" // preprocessor directive to include the FlashCard header file

/**
 * @file Score.h
 * @brief This file contains the declaration of the Score class.
 */

/**
 * @class Score
 * @brief A class that represents the score of a flashcard game.
 * @tparam T1 The type of the flashcard question.
 * @tparam T2 The type of the flashcard answer.
 * @tparam T3 The type of the flashcard category.
 * @tparam T4 The type of the user's answer.
 * @tparam T5 The type of the flashcard difficulty.
 */
template <class T1, class T2, class T3, class T4, class T5>
class Score : public FlashCard<T1, T2, T3, T4, T5> {
  private:
    string name; /**< The name of the player. */
    int age; /**< The age of the player. */

    int correct; /**< The number of correct answers. */
    int incorrect; /**< The number of incorrect answers. */
    int total; /**< The total number of questions. */
    double percentage; /**< The percentage of correct answers. */
  public:
    /**
     * @brief Default constructor for the Score class.
     */
    Score();

    /**
     * @brief Updates the score based on the user's answer.
     * @param question The flashcard question.
     * @param userAnswer The user's answer.
     */
    void updateScore(T1 question, T4 userAnswer);

    /**
     * @brief Displays the score.
     */
    void displayScore() const;

    /**
     * @brief Resets the score to zero.
     */
    void resetScore();

    // Mutators

    /**
     * @brief Sets the name of the player.
     * @param name The name of the player.
     */
    void setName(string name);

    /**
     * @brief Sets the age of the player.
     * @param age The age of the player.
     */
    void setAge(int age);
};

#endif