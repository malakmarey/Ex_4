#include <iostream>
using namespace std;
#include "calculate.hpp"
#include<string>
using namespace std;
namespace bullpgia{

    string calculateBullAndPgia(string choice, string guess){
        int i;
		int j;
		int pgiaa = 0; // good guess without index matchings
		int bulls = 0; // good guess with index matchings as well
		int num = choice.length();
		int* arr_ZeroF_oneT = new int[num]; //represents the guess string , marks hits , regardless if it's a bull or pgiaa
      //this loop should be dele
		for (i = 0; i < num; i++) {
			arr_ZeroF_oneT[i] = 0;
		}

		for (i = 0; i < choice.length(); i++) {
			char c = choice.at(i);
			char g = guess.at(i);
			if (c == g) {
				bulls++;
				arr_ZeroF_oneT[i] = 1;
				continue;
			}
			for (j = 0; j < guess.length(); j++) {
				g = guess.at(j);
				if (c == g && arr_ZeroF_oneT[j]==0) {
					pgiaa++;
					arr_ZeroF_oneT[j] = 1;
					break;
				}

			}
		}

		delete[] arr_ZeroF_oneT;
		string cal = to_string(bulls) + "," + to_string(pgiaa);
    return cal;
}
}