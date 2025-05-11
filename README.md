# 🧠 Flashcard Studies

An interactive flashcard learning tool developed in **C++**, designed to help users test and improve their memory through customizable flashcard sets. It utilizes a **doubly linked list** data structure for efficient card management and offers both **random** and **sequential** play modes via a simple command-line interface.


## 💡 Features

- ✅ Create, update, and delete flashcards
- 🔄 Random and sequential review modes
- 🧩 Uses **doubly linked list** for dynamic memory handling
- 🖥️ Command-line interface for fast, distraction-free learning
- 🗂️ Category support for better organization (optional extension)


## 📸 Demo

```bash
[1] Create Flashcard
[2] Edit Flashcard
[3] Delete Flashcard
[4] Start Flashcard Quiz
[5] Exit
Enter your choice: _
```


## ⚙️ How It Works

Flashcards are stored using a custom implementation of a **doubly linked list**, where each node represents a card with a question and an answer. The program supports:

- Inserting cards at any position
- Forward and backward traversal
- Shuffling (random play)
- Simple memory-based quiz format


## 🛠️ Tech Stack

- Language: **C++**
- Data Structure: **Doubly Linked List**
- Interface: **Console / Terminal**


## 🧪 Usage

To run the program:

```bash
g++ flashcard.cpp -o flashcard
./flashcard
```

Make sure you have a C++ compiler (like g++) installed.
