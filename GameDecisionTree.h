#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <bits/locale_facets_nonio.h>

#include "Node.h"
#include "Story.h"

using namespace std;

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream infile; //reads file for input

        infile.open(filename, ios::in); //opens file and checks if it opened
        if (infile.is_open()) {
            cout << "Loading story from " << filename << endl;
        } else {
            cout << "Unable to open file " << filename << endl;
        }


        vector<string> row;
        string line, word;
        map<int, Node<Story>*> nodeMap; //Map created to access story objects by event number

        while (getline(infile, line)) { //clears row vector and creates a string stream
            row.clear();
            stringstream ss(line);

            while (getline(ss, word, '|')) { //parses the information
                row.push_back(word);
            }

            if (row.size() >= 4) { //stores row values in each data type
                // cout << "Event number is " << row[0] << "\n";
                int num = stoi(row[0]);
                // cout << "Description is " << row[1] << "\n";
                string desc = row[1];
                // cout << "Left number is " << row[2] << "\n";
                int leftNum = stoi(row[2]);
                // cout << "Right number is " << row[3] << "\n";
                int rightNum = stoi(row[3]);


                Story story(desc, num, leftNum, rightNum); //Creates story object with text file values
                Node<Story>* newNode = new Node<Story>(story); //Creates a new node with story object data

                nodeMap[num] = newNode; //Adds node to map

                root = nodeMap[1]; //Creates root

            }
        }

        for (auto& pair : nodeMap) { //Creates binary tree with nodes
            Node<Story>* curr = pair.second;
            Story& story = curr->data;

            int leftNum = story.leftEventNumber;
            int rightNum = story.rightEventNumber;

            if (leftNum != -1 && nodeMap.find(leftNum) != nodeMap.end()) { //links current node pointer to left event number
                curr->left = nodeMap[leftNum];
            }

            if (rightNum != -1 && nodeMap.find(rightNum) != nodeMap.end()) { //links current node pointer to right event number
                curr->right = nodeMap[rightNum];
            }

            infile.close();
        }
    }



    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {

        Node<Story>* curr = root;

        while (curr) {
            Story& currStory = curr->data;
            cout << currStory.description << endl;

            if (currStory.leftEventNumber == -1 && currStory.rightEventNumber == -1) { //Ends if on a leaf node
                cout << "End" << endl;
                break;
            }

            cout << "Choose 1 for first option or 2 for second option" << endl;
            int choice;
            cin >> choice;

            if (choice == 1) { //Go to left child
                curr = curr->left;
            }
            else if (choice == 2) { //Go to right child
                curr = curr->right;
            } else { //Did not type 1 or 2
                cout << "Invalid event number" << endl;
            }

        }
    }
};

#endif // GAMEDECISIONTREE_H