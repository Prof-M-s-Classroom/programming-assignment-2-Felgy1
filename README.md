[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Jose Ramos`  
### **Student ID:** `826881660`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

> This project uses a binary tree to guide the user through an RPG scenario. Every event is stored in story objects used to create nodes and the next node or event is determined by the option the user chooses. The entire story is read from the text file ('story.txt') which is then parsed and placed into the tree nodes. Once the player reaches a leaf node the game ends.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `Specifies the filename and delimiter, loads the data and starts the game.`  
- **`GameDecisionTree.h`** → `Loads story from text file, builds a binary tree, then traverses it yo play the game.`  
- **`Node.h`** → `Creates nodes with story data, left pointer, and right pointer.`  
- **`Story.h`** → `Creates story objects holding the event number, description, left event number, and right event number.`  
- **`story.txt`** → `Where the story is written separated by delimiters`

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

> Story objects are created in the GameDecisionTree.h file by using ifstream to read the text file, parsing the information and creating a story object by using the Story.cpp constructors. Nodes are linked by using a map that finds the left and right numbers and links the current node's pointers to those nodes the int event number. When an event has -1 for both children, it means it is a leaf node which ends the game through the if statement that breaks the while loop.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

> The user has to type either 1 or 2 which depending on the choice either takes them the left child or the right child. When the player reaches a leaf node the game ends. Several paths lead to the same outcome which are simply linked through event numbers and can lead to different leaf nodes or the same leaf node outcome.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

> The file is read using ifstream and a string stream to parse the information using '|' as a delimiter. Probably not optimal, but I ensured all nodes were properly linked by playing through the game. One challenge I faced while handling file input was that it wasn't being read due to it being located in the wrong directory.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

> I took note of two errors that I caught and fixed. The first was my text file not reading because it wasn't in the cmake-build-debug directory. I was able to test this out through an if statement infile.is_open that showed if the file opened or not. The second error, which was more of a series of me trying to figure out how to get the game to correctly traverse the binary tree based on user input, was to see how to make the user's input take them to the corresponding node. A main mistake was using eventNumber = currStory.leftEventNumber rather than curr = curr->right to guide the user to the next node.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

> The player is first prompted by the story description and two potential choices which are chosen by typing 1 or 2. This then guides them to the selected scenario which is the next node where they'll be given the different event and choices, but through the same 1 and 2 options. Once this process leads them to a leaf node the game ends and the user will no longer be able to select options.

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n)`  
- **Searching for an event in the tree** → `O(n)`  
- **Game traversal efficiency** → `O(n)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

> I did have to test a scenario where the player reaches a leaf node because the program only ended after the user chose 1 or 2 again. I had to keep testing by placing the if statement in the correct spot and using a break statement.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

> The only additional feature I added was for my personal benefit which were cout commands that explain what information is being gathered from the story text file before it is stored into a data type to create an story object. These commands are commented out for the purpose of the game.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
