#include "DoublyLinkedList.h" // preprocessor directive to include the DoublyLinkedList header file

/**
 * @file DoublyLinkedList.cpp
 * @brief Implementation file for the DoublyLinkedList class.
 */

/**
 * @class DoublyLinkedList
 * @brief A template class that represents a doubly linked list.
 *
 * The DoublyLinkedList class provides functionality to store and manipulate data in a doubly linked list.
 * It supports operations such as inserting nodes, deleting nodes, searching for nodes, and displaying the list.
 * The class is implemented using templates, allowing it to work with different types of data.
 *
 * @tparam T1 The type of the question in each node.
 * @tparam T2 The type of the data in each node.
 */


/**
 * @brief Constructs an empty DoublyLinkedList object.
 */
template <class T1, class T2>
DoublyLinkedList<T1, T2>::DoublyLinkedList() {
  head = nullptr; // Initialize the head pointer to null.
  tail = nullptr; // Initialize the tail pointer to null.
}

/**
 * @brief Edits the data of a node with the specified question.
 * @param question The question of the node to be edited.
 * @param data The new data to be assigned to the node.
 */
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::editNode(T1 question, T2 data) {
  // try-catch block to handle exceptions
  // The function searches for a node with the specified question and updates its data.
  // If the question is not found, an exception is thrown.
  try {
    Node* temp = head; // Initialize a temporary pointer to the head of the list
    // Traverse the list to find the node with the specified question
    while (temp != nullptr) {
      // Check if the question of the current node matches the specified question
      if (temp->question == question) {
        temp->data = data; // Update the data of the node
        return;
      }
      temp = temp->next; // Move to the next node
    }
    throw "Data not found."; // Throw an exception if the question is not found
  } catch (const char* error) { // Catch the exception and display an error message
    cout << error << endl;
  }
}

/**
 * @brief Searches for a node with the specified question.
 * @param question The question to search for.
 * @return The index of the node if found, -1 otherwise.
 */
template <class T1, class T2>
int DoublyLinkedList<T1, T2>::searchQuestionNode(T1 question) const {
  Node* temp = head; // Initialize a temporary pointer to the head of the list
  // Traverse the list to find the node with the specified question
  while (temp != nullptr) {
    // Check if the question of the current node matches the specified question
    if (temp->question == question) {
      return 1; // Return 1 if the question is found
    }
    temp = temp->next; // Move to the next node
  }
  return -1; // Return -1 if the question is not found
}

/**
 * @brief Searches for a node with the specified data.
 * @param data The data to search for.
 * @return The index of the node if found, -1 otherwise.
 */
template <class T1, class T2>
int DoublyLinkedList<T1, T2>::searchNode(T2 data) const {
  const string border = "+------------------------------------------+"; // Border for the search result
  Node* temp = head; // Initialize a temporary pointer to the head of the list
  bool searched = false; // Flag to indicate if the data is found

  // Traverse the list to find the node with the specified data
  while (temp != nullptr) {
    // Check if the data of the current node matches the specified data
    if (temp->data == data) {
      cout << border << endl;
      cout << "Data found." << endl;
      cout << "Question: " << temp->question << endl;
      cout << "Data: " << temp->data << endl;
      cout << border << endl;
      searched = true; // Set the flag to true
    }
    temp = temp->next; // Move to the next node
  }

  // Return 1 if the data is found, -1 otherwise
  if (searched) {
    return 1; // Return 1 if the data is found
  }
  cout << border << endl;
  cout << "Data not found." << endl;
  cout << border << endl;
  return -1; // Return -1 if the data is not found
}

/**
 * @brief Deletes the node with the specified question.
 * @param question The question of the node to be deleted.
 */
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::deleteQuestionNode(T1 question) {
  // try-catch block to handle exceptions
  // The function searches for a node with the specified question and deletes it.
  // If the question is not found, an exception is thrown.
  try {
    Node* temp = head; // Initialize a temporary pointer to the head of the list
    // Traverse the list to find the node with the specified question
    while (temp != nullptr) {
      // Check if the question of the current node matches the specified question
      if (temp->question == question) {
        // Check if the node is the head of the list
        if (temp == head) {
          head = temp->next; // Update the head pointer
          head->prev = nullptr; // Set the previous pointer of the new head to null
          delete temp; // Delete the node
          return; // Return from the function
        // Check if the node is the tail of the list
        } else if (temp == tail) {
          tail = temp->prev; // Update the tail pointer
          tail->next = nullptr; // Set the next pointer of the new tail to null
          delete temp; // Delete the node
          return; // Return from the function
        // Check if the node is in the middle of the list
        } else {
          temp->prev->next = temp->next; // Update the next pointer of the previous node
          temp->next->prev = temp->prev; // Update the previous pointer of the next node
          delete temp; // Delete the node
          return; // Return from the function
        }
      }
      temp = temp->next; // Move to the next node
    }
    throw "Card not found."; // Throw an exception if the question is not found
  } catch (const char* error) { // Catch the exception and display an error message
    cout << "Error: " << error << endl;
  }
}

/**
 * @brief Deletes the node with the specified data.
 * @param data The data of the node to be deleted.
 */
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::deleteNode(T2 data) {
  // try-catch block to handle exceptions
  // The function searches for a node with the specified data and deletes it.
  // If the data is not found, an exception is thrown.
  try {
    Node* temp = head; // Initialize a temporary pointer to the head of the list
    // Traverse the list to find the node with the specified data
    while (temp != nullptr) {
      // Check if the data of the current node matches the specified data
      if (temp->data == data) {
        // Check if the node is the head of the list
        if (temp == head) {
          head = temp->next; // Update the head pointer
          head->prev = nullptr; // Set the previous pointer of the new head to null
          cout << "Card '" << temp->question << "' deleted." << endl;
          delete temp; // Delete the node
          return; // Return from the function
        // Check if the node is the tail of the list
        } else if (temp == tail) {
          tail = temp->prev; // Update the tail pointer
          tail->next = nullptr; // Set the next pointer of the new tail to null
          cout << "Card '" << temp->question << "' deleted." << endl;
          delete temp; // Delete the node
          return; // Return from the function
        // Check if the node is in the middle of the list
        } else {
          temp->prev->next = temp->next; // Update the next pointer of the previous node
          temp->next->prev = temp->prev; // Update the previous pointer of the next node
          cout << "Card '" << temp->question << "' deleted." << endl;
          delete temp; // Delete the node
          return; // Return from the function
        }
      }
      temp = temp->next; // Move to the next node
    }
    throw "Card not found."; // Throw an exception if the data is not found
  } catch (const char* error) { // Catch the exception
    cout << "Error: " << error << endl; // Display an error message
  }
}

/**
 * @brief Destroys the DoublyLinkedList object and frees the memory.
 */
template <class T1, class T2>
DoublyLinkedList<T1, T2>::~DoublyLinkedList() {
  Node* temp = head; // Initialize a temporary pointer to the head of the list
  // Traverse the list and delete each node
  while (temp != nullptr) {
    Node* next = temp->next; // Store the next node in a temporary pointer
    delete temp; // Delete the current node
    temp = next; // Move to the next node
  }
}

/**
 * @brief Inserts a new node with the specified question and data.
 * @param question The question of the new node.
 * @param data The data of the new node.
 */
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::insertNode(T1 question, T2 data) {
  // try-catch block to handle exceptions
  // The function inserts a new node with the specified question and data into the list.
  // If the question already exists in the list, an exception is thrown.
  try {
    Node* temp = head; // Initialize a temporary pointer to the head of the list
    // Traverse the list to check if the question already exists
    while (temp != nullptr) {
      // Check if the question of the current node matches the specified question
      if (temp->question == question) {
        throw "Question already exists."; // Throw an exception if the question already exists
      }
      temp = temp->next; // Move to the next node
    }
    Node* newNode = new Node; // Create a new node
    Node* nodePtr; // Pointer to traverse the list
    Node* previousNode = nullptr; // Pointer to the previous node

    newNode->question = question; // Set the question of the new node
    newNode->data = data; // Set the data of the new node

    // Check if the list is empty
    if (!head) {
      head = newNode; // Set the new node as the head
      tail = newNode; // Set the new node as the tail
      newNode->next = nullptr; // Set the next pointer to null
      newNode->prev = nullptr; // Set the previous pointer to null
    // List is not empty
    } else {
      nodePtr = head; // Initialize the pointer to the head of the list
      previousNode = nullptr; // Set the previous node pointer to null

      // Traverse the list to find the correct position to insert the new node
      // based on the question
      while (nodePtr != nullptr && nodePtr->question < question) {
        previousNode = nodePtr; // Update the previous node pointer
        nodePtr = nodePtr->next; // Move to the next node
      }

      // Insert the new node at the beginning of the list
      if (previousNode == nullptr) {
        head = newNode; // Set the new node as the head
        newNode->prev = nullptr; // Set the previous pointer to null
        newNode->next = nodePtr; // Set the next pointer to the current head
        // Update the previous pointer of the current head
        if (nodePtr != nullptr) {
          nodePtr->prev = newNode; // Set the previous pointer of the current head
        }
      // Insert the new node at the end or in the middle of the list
      } else {
        previousNode->next = newNode; // Update the next pointer of the previous node
        newNode->prev = previousNode; // Set the previous pointer to the previous node 
        newNode->next = nodePtr; // Set the next pointer to the current node

        // Update the previous pointer of the current node
        if (nodePtr != nullptr) { // If the new node is inserted in the middle of the list
          nodePtr->prev = newNode; // Set the previous pointer of the current node
        } else { // If the new node is inserted at the end of the list
          tail = newNode; // Set the new node as the tail
        }
      }
    }
  } catch (const char* error) { // Catch the exception
    cout << "Error: " << error << endl; // Display an error message
  }
}

/**
 * @brief Displays the list of questions.
 */
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::displayQuestionList() const {
  // try-catch block to handle exceptions
  // The function displays the list of questions in the list.
  // If the list is empty, a warning message is displayed.
  try {
    Node* temp = head; // Initialize a temporary pointer to the head of the list
    int i = 0; // Initialize a counter for the question number

    // Traverse the list and display the questions
    while (temp != nullptr) {
      cout << "==================================" << endl;
      cout << "|| Question " << ++i << ". " << setw(15) << left << temp->question << " ||" << endl;
      cout << "==================================" << endl;
      temp = temp->next; // Move to the next node
    }

    // Display a warning message if the list is empty
    if (head == nullptr) {
      throw "List is empty."; // Throw an exception
    }
  } catch (const char* error) { // Catch the exception
    cout << "Warning: " << error << endl; // Display a warning message
  }
}

/**
 * @brief Displays the data of a node with the specified question.
 * @param question The question of the node to display.
 * @param field The field of the node to display.
 */
template <class T1, class T2>
void DoublyLinkedList<T1, T2>::displayNode(T1 question, string field) const {
  // try-catch block to handle exceptions
  // The function displays the data of a node with the specified question.
  // If the list is empty, a warning message is displayed.
  try {
    Node* temp = head; // Initialize a temporary pointer to the head of the list
    const string border = "+------------------------------------------+"; // Border for the node display

    // Traverse the list to find the node with the specified question
    while (temp != nullptr) {
      // Check if the question of the current node matches the specified question
      if (temp->question == question) {
        cout << border << endl;
        cout << "Question: " << temp->question << endl;
        cout << "Data: " << temp->data << endl;
        cout << border << endl;
        return;
      }
      temp = temp->next; // Move to the next node
    }

    // Display a warning message if the list is empty
    if (head == nullptr) {
      throw "List is empty."; // Throw an exception
    }
  } catch (const char* error) { // Catch the exception
    cout << "Warning: " << error << endl; // Display a warning message
  }
}

/**
 * @brief Gets the number of nodes in the list.
 * @return The number of nodes in the list.
 */
template <class T1, class T2>
int DoublyLinkedList<T1, T2>::getNumberOfNodes() const {
  Node* temp = head; // Initialize a temporary pointer to the head of the list
  int count = 0; // Initialize a counter for the number of nodes

  // Traverse the list and count the number of nodes
  while (temp != nullptr) {
    count++; // Increment the counter
    temp = temp->next; // Move to the next node
  }
  return count; // Return the number of nodes
}

/**
 * @brief Gets the value of the head node.
 * @return The value of the head node.
 */
template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getHeadValue() const {
  // try-catch block to handle exceptions
  // The function gets the value of the head node.
  // If the list is empty, a warning message is displayed.
  try {
    // Check if the list is not empty
    if (head != nullptr) {
      return head->data; // Return the data of the head node
    } else { // List is empty
      throw "List is empty."; // Throw an exception
    }
  } catch (const char* error) { // Catch the exception
    cout << "Warning: " << error << endl; // Display a warning message
    return T2(); // Return a default value
  }
}

/**
 * @brief Gets the value of the tail node.
 * @return The value of the tail node.
 */
template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getTailValue() const {
  // try-catch block to handle exceptions
  // The function gets the value of the tail node.
  // If the list is empty, a warning message is displayed.
  try {
    // Check if the list is not empty
    if (tail != nullptr) {
      return tail->data; // Return the data of the tail node
    } else { // List is empty
      throw "List is empty."; // Throw an exception
    }
  } catch (const char* error) { // Catch the exception
    cout << "Warning: " << error << endl; // Display a warning message
    return T2(); // Return a default value
  }
}

/**
 * @brief Gets the value of a node with the specified question.
 * @param question The question of the node to get the value.
 * @return The value of the node.
 */
template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getNodeValue(T1 question) const {
  // try-catch block to handle exceptions
  // The function gets the value of a node with the specified question.
  // If the question is not found, an exception is thrown.
  try {
    Node* temp = head; // Initialize a temporary pointer to the head of the list
    // Traverse the list to find the node with the specified question
    while (temp != nullptr) {
      // Check if the question of the current node matches the specified question
      if (temp->question == question) {
        return temp->data; // Return the data of the node
      }
      temp = temp->next; // Move to the next node
    }
    throw "Question not found."; // Throw an exception if the question is not found
  } catch (const char* error) { // Catch the exception
    cout << "Error: " << error << endl; // Display an error message
    return T2(); // Return a default value
  }
}

/**
 * @brief Gets the value of the previous node of a node with the specified question.
 * @param question The question of the node to get the previous node value.
 * @return The value of the previous node.
 */
template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getPreviousNodeValue(T1 question) const {
  // The function gets the value of the previous node of a node with the specified question.
  // If the previous node does not exist, an exception is thrown.
  // If the question is not found, an exception is thrown.
  try {
    Node* temp = head; // Initialize a temporary pointer to the head of the list
    // Traverse the list to find the node with the specified question
    while (temp != nullptr) {
      // Check if the question of the current node matches the specified question
      if (temp->question == question) {
        // Check if the previous node exists
        if (temp->prev != nullptr) {
          return temp->prev->data; // Return the data of the previous node
        } else {
          throw "No previous node exists."; // Throw an exception if the previous node does not exist
        }
      }
      temp = temp->next; // Move to the next node
    }
    throw "Question not found."; // Throw an exception if the question is not found
  } catch (const char* error) { // Catch the exception
    cout << "Error: " << error << endl; // Display an error message
    return T2(); // Return a default value
  }
}

/**
 * @brief Gets the value of the next node of a node with the specified question.
 * @param question The question of the node to get the next node value.
 * @return The value of the next node.
 */
template <class T1, class T2>
T2 DoublyLinkedList<T1, T2>::getNextNodeValue(T1 question) const {
  // The function gets the value of the next node of a node with the specified question.
  // If the next node does not exist, an exception is thrown.
  // If the question is not found, an exception is thrown.
  try {
    Node* temp = head; // Initialize a temporary pointer to the head of the list

    // Traverse the list to find the node with the specified question
    while (temp != nullptr) {
      // Check if the question of the current node matches the specified question
      if (temp->question == question) {
        // Check if the next node exists
        if (temp->next != nullptr) {
          return temp->next->data; // Return the data of the next node
        } else { // Next node does not exist
          throw "No next node exists."; // Throw an exception
        }
      }
      temp = temp->next; // Move to the next node
    }
    throw "Question not found."; // Throw an exception if the question is not found
  } catch (const char* error) { // Catch the exception
    cout << "Error: " << error << endl; // Display an error message
    return T2(); // Return a default value
  }
}

// Explicit instantiation of the DoublyLinkedList class with the required template types.
// This is necessary to avoid linker errors for the template class.
// The template class is instantiated for the following types:
// - T1: string
// - T2: string
// This allows the DoublyLinkedList class to be used with the specified template types.
template class DoublyLinkedList <string, string>;

// The template class is instantiated for the following types:
// - T1: string
// - T2: int
template class DoublyLinkedList <string, int>;

// The template class is instantiated for the following types:
// - T1: string
// - T2: double
template class DoublyLinkedList <string, double>;