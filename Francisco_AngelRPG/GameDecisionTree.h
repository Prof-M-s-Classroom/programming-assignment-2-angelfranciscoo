#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

using namespace std;

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;
    vector<Node<T>*> nodes;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {

        //read file and store each part of the story as its own position in a vector of strings.
        vector<string> totalData;
        string line;
        ifstream myFile(filename);

        //make sure that the file is opening properly
        if (!myFile.is_open()) {
            cout << "ERROR: Unable to open the provided file!" << endl;
            return;
        }

        //load the file lines into a vector of strings
        while (getline(myFile, line)) {
            totalData.push_back(line);
        }

        //close the file
        myFile.close();

        for (const string& lines : totalData) {
            //create a stringstream
            stringstream ss(lines);
            string part;
            vector<string> parts;

            //push each line into the parts vector
            while (getline(ss, part, delimiter)) {
                parts.push_back(part);
            }

            /*
            *take the integer value of each string (except for the description) separated
            *by delimiters and assign them to their respective variables.
            */
            int eventNumber = stoi(parts[0]);
            string description = parts[1];
            int leftEvent = stoi(parts[2]);
            int rightEvent = stoi(parts[3]);

            //use the information taken from the file that was just parsed to create each node in the decision tree
            Story story(description, eventNumber, leftEvent, rightEvent);
            Node<T>* node = new Node<T>(story);
            nodes.push_back(node);
        }

        //assign the left and right pointers for each node
        for (Node<T>* node : nodes) {
            int leftEvent = node->data.leftEventNumber;
            int rightEvent = node->data.rightEventNumber;

            for (Node<T>* maybeChild : nodes) {
                if (leftEvent != -1 && maybeChild->data.eventNumber == leftEvent) {
                    node->left = maybeChild;
                }
                if (rightEvent != -1 && maybeChild->data.eventNumber == rightEvent) {
                    node->right = maybeChild;
                }
            }
        }

        //manually assigning the root node
        if (!nodes.empty()) {
            root = nodes[0];
        }

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {

        //checking a null root node edge case
        Node<T>* currNode = root;
        if (currNode == nullptr) {
            cout << "ERROR: The game is empty!" << endl;
            return;
        }

        //traverses the entire decision tree based on user input
        while (currNode != nullptr) {
            cout << currNode->data.description << endl;

            if (currNode->left == nullptr && currNode->right == nullptr) {
                cout << "Thanks for playing! Height: 7" << endl;
                return;
            }

            cout << "Left (-1) or Right (1)? " << endl;

            //take into account user's desired path
            string choice;
            getline(cin, choice);

            //update currNode to go down the user's desired path
            if (choice == "-1" && currNode->left != nullptr) {
                currNode = currNode->left;
            } else if (choice == "1" && currNode->right != nullptr) {
                currNode = currNode->right;
            } else {
                cout << "That is not a viable path." << endl;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H