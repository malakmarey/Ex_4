#pragma once
#include <iostream>
#include "Guesser.hpp"
#include <set>
#include <iterator>

namespace bullpgia{

using namespace std;
class SmartGuesser : public bullpgia::Guesser {
    public:

    string currentGuess;

    set<string> allCombinations;

    virtual string guess() override;

    void startNewGame(uint length) override;
    
    void learn(string l) override;
    
    

    private:
    string fixNumber(string, uint); //this function will fix the number of the form

    void setBuilder(uint length);

};

}
