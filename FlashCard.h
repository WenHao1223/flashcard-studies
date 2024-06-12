#ifndef FLASH_CARD_H
#define FLASH_CARD_H

#include <iostream> // for input / output stream
#include <string> // for string manipulation
#include <iomanip> // for input / output manipulation
#include <cmath> // for math operations
#include <cstdlib> // standard general utilities library
#include <ctime> // for handling date and time information
#include <fstream> // for file input / output
using namespace std;

#include "DoublyLinkedList.h" // preprocessor directive to include the DoublyLinkedList header file

/**
 * @file FlashCard.h
 * @brief This file contains the declaration of the FlashCard class.
 */

/**
 * @class FlashCard
 * @brief A class representing a flashcard.
 * @tparam T1 The type of the question.
 * @tparam T2 The type of the description.
 * @tparam T3 The type of the operation.
 * @tparam T4 The type of the answer.
 * @tparam T5 The type of the difficulty.
 */
template <class T1, class T2, class T3, class T4, class T5>
class FlashCard {
  private:
    DoublyLinkedList <T1, T1> questions; /**< The list of questions. */
    DoublyLinkedList <T1, T2> descriptions; /**< The list of descriptions. */
    DoublyLinkedList <T1, T3> operations; /**< The list of operations. */
    DoublyLinkedList <T1, T4> answers; /**< The list of answers. */
    DoublyLinkedList <T1, T5> difficulties; /**< The list of difficulties. */
  public:
    /**
     * @brief Default constructor for the FlashCard class.
     */
    FlashCard();

    /**
     * @brief Initializes the flashcard from a file.
     * @param fileName The name of the file to read from.
     */
    void initialize(string fileName);

    /**
     * @brief Edits a flashcard.
     * @param fileName The name of the file to write to.
     * @param question The new question.
     * @param description The new description.
     * @param operation The new operation.
     * @param answer The new answer.
     * @param difficulty The new difficulty.
     */
    void editCard(string fileName, T1 question, T2 description, T3 operation, T4 answer, T5 difficulty);

    /**
     * @brief Displays the value of a specific data field for a given question.
     * @param question The question to search for.
     * @param field The data field to display.
     */
    void displayDataField(T1 question, string field) const;

    /**
     * @brief Searches for a question node in the flashcard.
     * @param question The question to search for.
     * @return The index of the question node if found, -1 otherwise.
     */
    int searchQuestionNode(T1 question) const;

    /**
     * @brief Searches for a description in the flashcard.
     * @param data The description to search for.
     * @return The index of the description if found, -1 otherwise.
     */
    int searchDescription(T2 data) const;

    /**
     * @brief Searches for an operation in the flashcard.
     * @param data The operation to search for.
     * @return The index of the operation if found, -1 otherwise.
     */
    int searchOperation(T3 data) const;

    /**
     * @brief Searches for an answer in the flashcard.
     * @param data The answer to search for.
     * @return The index of the answer if found, -1 otherwise.
     */
    int searchAnswer(T4 data) const;

    /**
     * @brief Searches for a difficulty in the flashcard.
     * @param data The difficulty to search for.
     * @return The index of the difficulty if found, -1 otherwise.
     */
    int searchDifficulty(T5 data) const;

    /**
     * @brief Deletes a question node from the flashcard.
     * @param fileName The name of the file to write to.
     * @param question The question to delete.
     */
    void deleteQuestionNode(string fileName, T1 question);

    /**
     * @brief Destructor for the FlashCard class.
     */
    ~FlashCard();

    /**
     * @brief Inserts a new node into the flashcard.
     * @param question The question to insert.
     * @param description The description to insert.
     * @param operation The operation to insert.
     * @param answer The answer to insert.
     * @param difficulty The difficulty to insert.
     */
    void insertNode(T1 question, T2 description, T3 operation, T4 answer, T5 difficulty);

    /**
     * @brief Displays all flashcards.
     */
    void displayAllFlashCard() const;

    /**
     * @brief Displays the list of questions.
     */
    void displayQuestionList() const;

    /**
     * @brief Displays a flashcard without the answer.
     * @param question The question to display.
     */
    void displayFlashCardNoAnswer(T1 question) const;

    /**
     * @brief Displays a flashcard with the answer.
     * @param question The question to display.
     */
    void displayFlashCardWithAnswer(T1 question) const;

    /**
     * @brief Displays flashcards one by one.
     */
    void displayFlashCardOneByOne() const;

    /**
     * @brief Displays a random flashcard.
     * @return The question of the random flashcard.
     */
    T1 displayRandomFlashCard() const;

    /**
     * @brief Gets the description value for a given question.
     * @param question The question to search for.
     * @return The description value if found, an empty string otherwise.
     */
    T2 getDescriptionValue(T1 question) const;

    /**
     * @brief Gets the operation value for a given question.
     * @param question The question to search for.
     * @return The operation value if found, an empty string otherwise.
     */
    T3 getOperationValue(T1 question) const;

    /**
     * @brief Gets the answer value for a given question.
     * @param question The question to search for.
     * @return The answer value if found, an empty string otherwise.
     */
    T4 getAnswerValue(T1 question) const;

    /**
     * @brief Gets the difficulty value for a given question.
     * @param question The question to search for.
     * @return The difficulty value if found, an empty string otherwise.
     */
    T5 getDifficultyValue(T1 question) const;

    /**
     * @brief Calculates the average difficulty of the flashcard.
     * @tparam U1 The type of the question.
     * @tparam U2 The type of the description.
     * @tparam U3 The type of the operation.
     * @tparam U4 The type of the answer.
     * @tparam U5 The type of the difficulty.
     * @param card The flashcard to calculate the average difficulty for.
     * @return The average difficulty.
     */
    template <class U1, class U2, class U3, class U4, class U5>
    friend double averageDifficulty(const FlashCard<U1, U2, U3, U4, U5> & card);

    /**
     * @brief Calculates the number of questions in the flashcard.
     * @brief friend function declaring in main.cpp
     * 
     * @tparam U1 The type of the question.
     * @tparam U2 The type of the description.
     * @tparam U3 The type of the operation.
     * @tparam U4 The type of the answer.
     * @tparam U5 The type of the difficulty.
     * @param card The flashcard to calculate the number of questions for.
     * @return The number of questions.
     */
    template <class U1, class U2, class U3, class U4, class U5>
    friend int numberOfQuestions(const FlashCard<U1, U2, U3, U4, U5> & card);
};

#endif