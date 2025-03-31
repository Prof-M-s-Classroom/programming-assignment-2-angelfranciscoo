    [![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Angel Francisco`  
### **Student ID:** `130730077`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

Example:
> My project implements a golf centered, text-based RPG using a binary decision tree. My program takes a file as input (StoryFile.txt), parses the entire file while taking into consideration delimiters ("|"), and constructs a full-fledged binary decision tree of height 7. Once the file is parsed and the decision tree is created, the user is then prompted, node by node, to make one of two decisions. At the end of each possible path, the player is given the option to either restart or terminate the game. To terminate the game, I incorporated a node with both left child and right child equal to -1.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `Opens, parses, and creates a binary decision tree from a file. Allows the user to play the text-based RPG in the console.`  
- **`GameDecisionTree.h`** → `Contains a templated GameDecisionTree<T> where T is the Story class. Has two methods (loadStoryFromFile and playGame) that load story data from a file as well as creates a decision tree, and traverses the decision tree depending on which path the user takes, respectively. `  
- **`Node.h`** → `Contains a templated Node<T> class where T is the Story class. Creates nodes that have three variables (data, leftChild, rightChild). Has three total constructors, a default constructor, a constructor that only takes data as input, and a constructor that takes data, left, and right children as input.`  
- **`Story.h`** → `Contains variables for each event in a decision tree (description, eventNumber, leftEventNumber, rightEventNumber. Also contains a default and parameterized constructor for the Story class.`  
- **`story.txt`** → `The game loads story events from this file using the method loadStoryFromFile located in the GameDecisionTree.h file. This method opens the file, stores each line in a string vector, parses each line to separate information based on delimiter placement, and then uses that information to successfully create nodes. The node's left and right pointers are created based on the leftEventNumber and rightEventNumber variables.`  

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file? Story objects are created after the .txt file has been parsed and information separated by delimiters has been stored into their respective variables.
- How are nodes linked based on left and right event numbers? Each node's left and right pointers are linked based on the event numbers provided in the .txt file. These links are very important as each event must have the exact left and right event numbers shown in the .txt file to maintain clarity and proper flow within the decision tree.
- What happens if an event has `-1` as left or right children? `-1` is a special event number as it terminates the game if the user decides to follow that path.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken? User input is always either a -1 or 1 indicating that they are either going down the left or right path, respectively. 
- What happens when the player reaches a leaf node? When the player reaches a leaf node they are given the option to either terminate the game or restart from the beginning (program takes them back to the root node).
- Explain the special case where multiple events lead to the same outcome. With our binary decision tree, nodes do not have parent values, this is done intentionally to allow the special case of a node having multiple parent nodes. In my program for example, Node 36 has 4 different parents, it serves as the node that terminates the game. All four parent nodes prompt the user to choose to restart or terminate the game, if the user decides to terminate the game, Node 36 (which has left and right child values of -1) is reached and the game ends.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter? The file is opened and read using an ifstream and is parsed using a delimiter through a stringstream.
- How do you ensure nodes are properly linked? I spent a lot of time making sure my logic was correct for the node linking, trial and error was also helpful. By going down every possible path I was able to confirm that all my nodes had been linked correctly.
- Any challenges faced while handling file input? Yes, a lot. I had multiple issues including issues with whitespace, opening the file, reading the file, it was a lot that I had to figure out. Through perseverance, I was able to solve all my errors. 

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
> One major debugging challenge that I faced was not being able to open my .txt file. I tried moving the location of the file from my desktop into the cLion folder, and even into the build folder and nothing was working. I then decided to use the entire file path instead of just the name of the file and that fixed the issue. However, I was getting errors parsing the file due to previous whitespace that I had inside. It was a lot of nitpicking but I finally perfected the .txt file and everything ultimately ran smoothly.
> 
> Update: I relocated my story.txt file to the cmake-build-debug directory which allowed me to use the file as intended without having to make the filename in main.cpp the absolute path!

---

## **7. Sample Output & Walkthrough**
Welcome to Golf! Easy mode or Hard mode?  
Left (-1) or Right (1)?  
1  
Par 3, 150 yards to the pin. Choose your club: Sand Wedge OR Pitching Wedge?  
Left (-1) or Right (1)?  
1  
Nice shot! You have a 15 foot putt to sink. Do you think it breaks left or right?  
Left (-1) or Right (1)?  
-1  
Oh no! It seems to have broken right! Now you have a 7 foot putt. You should take your time on this one. Would you like a sip of Water or Gatorade?  
Left (-1) or Right (1)?  
-1  
Great choice! I bet that was refreshing. Now...do you think this one is straight or does it break slightly right?  
Left (-1) or Right (1)?  
1  
Great putt! You read the line perfectly and scored a par! Would you like to play again? Yes (left), No (right)  
Left (-1) or Right (1)?  
1  
--  
Thanks for playing! Those were some nice shots. Bye for now!  

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(N^2)`  
- **Searching for an event in the tree** → `O(log(N))`  
- **Game traversal efficiency** → `O(h)` → "h" is the height of the tree. This is because the traversal for one game only consists of going down a single path (root to leaf).

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested the edge case at the end of game that would require the user to either terminate the game or play again. I created a new node with left and right children that have values of -1. If the user opts to terminate the game, the program will reach that node and the game ends. If they would like to play again, that node is not reached, instead, the program traverses back to the root node, serving as a "restart".

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> N/A -- The methods originally given to us were enough for me to create my game, I did not need the help of any additional methods/featurues.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
