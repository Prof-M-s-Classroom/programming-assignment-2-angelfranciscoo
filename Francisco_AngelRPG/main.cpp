#include <iostream>
#include <string>
#include "GameDecisionTree.h"
using namespace std;
int main() {
    GameDecisionTree<Story> myGame;

    //StoryFile.txt relative path
    ///Users/angelfrancisco/CLionProjects/programming-assignment-2-angelfranciscoo/Francisco_AngelRPG/StoryFile.txt

    //story.txt relative path
    ///Users/angelfrancisco/CLionProjects/programming-assignment-2-angelfranciscoo/Francisco_AngelRPG/story.txt

    string filename = "/Users/angelfrancisco/CLionProjects/programming-assignment-2-angelfranciscoo/Francisco_AngelRPG/StoryFile.txt";     // Specify the input file
    char delimiter = '|';     // '|' is the delimiter, change if needed

    // Load the story data from the file
    myGame.loadStoryFromFile(filename, delimiter);

    // Start the game
    myGame.playGame();

    return 0;
}