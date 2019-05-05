#include <iostream>
#include <cmath>
#include "SmartGuesser.hpp"

using namespace std;
using namespace bullpgia;


void SmartGuesser::startNewGame(uint length) {
    this->length = length;
    setBuilder(length);
}

void SmartGuesser::setBuilder(uint length) {
    string combination;
    int maxComb = pow(10,length);
    for(int i=0; i<maxComb; i++){
        combination = fixNumber(to_string(i),length);
        allCombinations.insert(combination);
    }
}

string SmartGuesser::fixNumber(string num, uint reqLength){
    while(num.length() < reqLength){
        num = "0" + num;    
    }
    return num;
}

string SmartGuesser::guess() {
    int rnd = rand() % allCombinations.size();
    auto it = allCombinations.begin();
    advance(it, rnd);
    currentGuess = *it;
    return currentGuess;
}

void SmartGuesser::learn(string l) {
    auto it = allCombinations.begin();
    while( it != allCombinations.end()) {
        string ans = calculateBullAndPgia(currentGuess, *it);
        if(ans != l) {
           it = allCombinations.erase(it);
        }
        else it++;
    }
}
