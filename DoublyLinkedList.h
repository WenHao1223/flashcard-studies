#ifndef DOUBLY_LINKED_LIST_CPP
#define DOUBLY_LINKED_LIST_CPP

#include <iostream> // for input / output stream
#include <iomanip> // for input / output manipulation
#include <string> // for string manipulation
#include <cmath> // for math operations

using namespace std;

/**
 * @file DoublyLinkedList.h
 * @brief This file contains the declaration of the DoublyLinkedList class.
 */

/**
 * @class DoublyLinkedList
 * @brief A class that represents a doubly linked list.
 * @tparam T1 The type of the question in each node.
 * @tparam T2 The type of the data in each node.
 */
template <class T1, class T2>
class DoublyLinkedList {
  private:
    /**
     * @struct Node
     * @brief A struct that represents a node in the doubly linked list.
     */
    struct Node {
      T1 question; ///< The question stored in the node.
      T2 data; ///< The data stored in the node.
      Node* next; ///< Pointer to the next node.
      Node* prev; ///< Pointer to the previous node.
    };
    Node* head; ///< Pointer to the head of the list.
    Node* tail; ///< Pointer to the tail of the list.
  public:
    /**
     * @brief Constructs an empty DoublyLinkedList object.
     */
    DoublyLinkedList();

    /**
     * @brief Edits the data of a node with the specified question.
     * @param question The question of the node to be edited.
     * @param data The new data to be assigned to the node.
     */
    void editNode(T1 question, T2 data);

    /**
     * @brief Searches for a node with the specified question.
     * @param question The question to search for.
     * @return The index of the node if found, -1 otherwise.
     */
    int searchQuestionNode(T1 question) const;

    /**
     * @brief Searches for a node with the specified data.
     * @param data The data to search for.
     * @return The index of the node if found, -1 otherwise.
     */
    int searchNode(T2 data) const;

    /**
     * @brief Deletes the node with the specified question.
     * @param question The question of the node to be deleted.
     */
    void deleteQuestionNode(T1 question);

    /**
     * @brief Deletes the node with the specified data.
     * @param data The data of the node to be deleted.
     */
    void deleteNode(T2 data);

    /**
     * @brief Destroys the DoublyLinkedList object and frees the memory.
     */
    ~DoublyLinkedList();

    /**
     * @brief Inserts a new node with the specified question and data.
     * @param question The question of the new node.
     * @param data The data of the new node.
     */
    void insertNode(T1 question, T2 data);
    
    /**
     * @brief Displays the list of questions.
     */
    void displayQuestionList() const;

    /**
     * @brief Displays the data of a node with the specified question.
     * @param question The question of the node to display.
     * @param field The field of the node to display.
     */
    void displayNode(T1 question, string field) const;

    /**
     * @brief Gets the number of nodes in the list.
     * @return The number of nodes in the list.
     */
    int getNumberOfNodes() const;

    /**
     * @brief Gets the value of the head node.
     * @return The value of the head node.
     */
    T2 getHeadValue() const;

    /**
     * @brief Gets the value of the tail node.
     * @return The value of the tail node.
     */
    T2 getTailValue() const;

    /**
     * @brief Gets the value of a node with the specified question.
     * @param question The question of the node to get the value.
     * @return The value of the node.
     */
    T2 getNodeValue(T1 question) const;

    /**
     * @brief Gets the value of the previous node of a node with the specified question.
     * @param question The question of the node to get the previous node value.
     * @return The value of the previous node.
     */
    T2 getPreviousNodeValue(T1 question) const;

    /**
     * @brief Gets the value of the next node of a node with the specified question.
     * @param question The question of the node to get the next node value.
     * @return The value of the next node.
     */
    T2 getNextNodeValue(T1 question) const;
};

#endif