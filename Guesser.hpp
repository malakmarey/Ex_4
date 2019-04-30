#pragma once
#include<iostream>
#include "calculate.hpp"

using namespace std;

namespace bullpgia
{
	class Guesser
	{
	protected:
		unsigned int length; // holds the string length;
		string result;

	public:
		virtual string guess() = 0;

		/**
		 * this void function starts a new game with a given input
		 * @param length is length of string.
		 */
		virtual void startNewGame(unsigned int length){
			this->length = length;
		 }


		virtual void learn(string calculateBullAndPgia_ans){
    this->result = calculateBullAndPgia_ans;
		}
	 };
}