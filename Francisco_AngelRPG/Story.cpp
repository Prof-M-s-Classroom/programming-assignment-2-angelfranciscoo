#include "Story.h"

using namespace std;

string description;
int eventNumber;
int leftEventNumber;
int rightEventNumber;

// TODO: Default constructor
Story::Story() : description(""), eventNumber(0), leftEventNumber(-1), rightEventNumber(-1) {}

// TODO: Parameterized constructor
Story::Story(string desc, int num, int leftNum, int rightNum)
        : description(desc), eventNumber(num), leftEventNumber(leftNum), rightEventNumber(rightNum) {}
