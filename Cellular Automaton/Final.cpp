// Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int n = 0; // the sum of three values
int rule; // rule Number
int length = 9; // how many numbers contain in one line 
int line; // how many lines to output
int l1[100];
int l2[100];

void setup() { // print the first line
    std::cout << "Input the rule you want to apply: ";
    std::cin >> rule;

    std::cout << "Input the length number: ";
    std::cin >> length;
    std::cout << "Input the line number: " ;
    std::cin >> line;
    std::cout << std::endl;
    for (int i = 0; i < (length/2) - 1; i++) { // first half
        std::cout << " ";
    }
    // the middle
    l1[length/2] = 1;
    std::cout << "x";
    //after the middle
    for (int i = (length/2)+1; i < length; i++) {
        std::cout << " ";
    }
    std::cout << std::endl;
}

void draw() {

    for (int i = 1; i < line; i++) {

        /*if (i == 1) { // the first one that only has two blocks
            n = l1[i] + l1[1 + i] + l1[length]; // add the last one 
        }
        else if (i == length) { // the last one that only has two blocks
            n = l1[i - 1] + l1[i] + l1[1]; // add the first one
        }
        else {
            n = l1[i - 1] + l1[i] + l1[i + 1]; // sum of the three neighbors
        }
        */
        if ((l1[i] == 1 && l1[1 + i] == 1 && l1[length] == 1)) {
            l2[i] = 0;
            std::cout << " ";
        }
        else if (l1[i] == 0 && l1[1 + i] == 0 && l1[length] == 0) {
            l2[i] = 0;
            std::cout << " ";
        }
        else if (l1[i - 1] == 1 && l1[i] == 1 && l1[i + 1] == 1) {
            l2[i] = 0;
            std::cout << " ";
        }
        else if ((l1[i - 1] == 0 && l1[i] == 0 && l1[i + 1] == 0)) {
            l2[i] = 0;
            std::cout << " ";
        }
        else { // other cases generate x
            l2[i] = 1;
            std::cout << "x";
        }
        // rule 126
        /*if (n == 0 || n == 3) { // only sum of 0 and 3 will generate " "
            l2[i] = 0;
            std::cout << " ";
        }
        else { // other cases generate x
            l2[i] = 1;
            std::cout << "x";
        }
        */
    }

    // replace the value from the second line to the first line 
    for (int i = 0; i < line; i++) {
        l1[i] = l2[i];
    }
    std::cout << std::endl;
    return;
}


int main() {
    setup();
    for (int i = 0; i < line; i++) { // repeat several times to see the whole pic
        draw();
    }

    return 0;
}
