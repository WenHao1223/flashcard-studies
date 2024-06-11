#include "Score.h" // preprocessor directive to include the Score header file

/**
 * @file Score.cpp
 * @brief Implementation file for the Score class.
 * @details This file contains the implementation of the Score class, which represents the score of a flashcard game.
 * The Score class is a template class that takes five template parameters: T1, T2, T3, T4, and T5.
 * It provides functionality to update and display the score, as well as reset the score and set the name and age of the player.
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

/**
 * @brief Default constructor for the Score class.
 */
template <class T1, class T2, class T3, class T4, class T5>
Score<T1, T2, T3, T4, T5>::Score() {
  correct = 0; // Initialize the number of correct answers to 0.
  incorrect = 0; // Initialize the number of incorrect answers to 0.
  total = 0; // Initialize the total number of questions to 0.
  percentage = 0.0; // Initialize the percentage of correct answers to 0.0.
}

/**
 * @brief Updates the score based on the user's answer.
 * @param question The flashcard question.
 * @param userAnswer The user's answer.
 */
template <class T1, class T2, class T3, class T4, class T5>
void Score<T1, T2, T3, T4, T5>::updateScore(T1 question, T4 userAnswer) {
  T4 answer = FlashCard<T1, T2, T3, T4, T5>::getAnswerValue(question); // Get the correct answer for the question.
  bool isCorrect = userAnswer == answer; // Check if the user's answer is correct. 

  // Update the score based on the correctness of the user's answer.
  // Increment the number of correct answers if the answer is correct, otherwise increment the number of incorrect answers.
  if (isCorrect) {
    correct++; // Increment the number of correct answers.
    cout << "Correct!" << endl;
  } else {
    incorrect++; // Increment the number of incorrect answers.
    cout << "Incorrect!" << endl;
  }
  total++; // Increment the total number of questions.
  percentage = (static_cast<double>(correct) / total) * 100; // Calculate the percentage of correct answers.
  cout << "Score updated: " << correct << "/" << total << endl;
}

/**
 * @brief Displays the score.
 */
template <class T1, class T2, class T3, class T4, class T5>
void Score<T1, T2, T3, T4, T5>::displayScore() const {
  const string border = "+------------------------------------------+"; // Border for the score display.
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

/**
 * @brief Resets the score to zero.
 */
template <class T1, class T2, class T3, class T4, class T5>
void Score<T1, T2, T3, T4, T5>::resetScore() {
  name = ""; // Reset the name of the player.
  age = 0; // Reset the age of the player.
  correct = 0; // Reset the number of correct answers.
  incorrect = 0; // Reset the number of incorrect answers.
  total = 0; // Reset the total number of questions.
  percentage = 0.0; // Reset the percentage of correct answers.

  cout << "Score reset." << endl;
}

/**
 * @brief Sets the name of the player.
 * @param name The name of the player.
 */
template <class T1, class T2, class T3, class T4, class T5>
void Score<T1, T2, T3, T4, T5>::setName(string name) {
  // try-catch block to handle exceptions for invalid name input.
  try {
    // Check if the name is empty.
    if (name == "") {
      throw "Name cannot be empty."; // Throw an exception if the name is empty.
    }
  } catch (const string error) { // Catch the exception.
    cout << error << endl; // Display the error message.
    return; // Return from the function.
  }

  this->name = name; // Set the name of the player.
}

/**
 * @brief Sets the age of the player.
 * @param age The age of the player.
 */
template <class T1, class T2, class T3, class T4, class T5>
void Score<T1, T2, T3, T4, T5>::setAge(int age) {
  // try-catch block to handle exceptions for invalid age input.
  try {
    // Check if the age is negative.
    if (age < 0) {
      throw "Age cannot be negative."; // Throw an exception if the age is negative.
    }
  } catch (const string error) { // Catch the exception.
    cout << error << endl; // Display the error message.
    return; // Return from the function.
  }

  this->age = age; // Set the age of the player.
}

// Explicit instantiation of the Score class with the required template types.
// This is necessary to avoid linker errors for the template class.
// The template class is instantiated for the following types:
// - T1: string
// - T2: string
// - T3: string
// - T4: double
// - T5: int
// This allows the Score class to be used with the specified template types.
// The explicit instantiation is done in the implementation file (Score.cpp).
template class Score<string, string, string, double, int>;