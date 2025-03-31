#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
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
        //Read file and store each part of the story as its own position in a vector of strings.
        vector<string> totalData;
        string line;
        ifstream myFile(filename);
        if (!myFile.is_open()) {
            cout << "ERROR: Unable to open the provided file!" << endl;
            return;
        }

        while (getline(myFile, line)) {
            totalData.push_back(line);
        }
        myFile.close();

        for (const string& lines : totalData) {
            stringstream ss(lines);
            string part;
            vector<string> parts;

            while (getline(ss, part, delimiter)) {
                parts.push_back(part);
            }

            int eventNumber = stoi(parts[0]);
            string description = parts[1];
            int leftEvent = stoi(parts[2]);
            int rightEvent = stoi(parts[3]);

            Story story(description, eventNumber, leftEvent, rightEvent);
            Node<T>* node = new Node<T>(story);
            nodes.push_back(node);
        }

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

        if (!nodes.empty()) {
            root = nodes[0];
        }

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<T>* currNode = root;
        if (currNode == nullptr) {
            cout << "ERROR: The game is empty!" << endl;
            return;
        }

        while (currNode != nullptr) {
            cout << currNode->data.description << endl;

            if (currNode->left == nullptr && currNode->right == nullptr) {
                cout << "Thanks for playing! Those were some nice shots. Bye for now!" << endl;
                return;
            }

            cout << "Left (-1) or Right (1)? " << endl;

            string choice;
            getline(cin, choice);

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