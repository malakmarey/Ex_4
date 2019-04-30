/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main()
{

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0)
	{

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
			.CHECK_OUTPUT(calculateBullAndPgia("1234", "1234"), "4,0") // 4 bull, 0 pgia
			// TESTING BULL AND PGIA
			.CHECK_OUTPUT(calculateBullAndPgia("5555", "5555"), "4,0") // 4 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("0000", "5555"), "0,0") // 0 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("8526", "8521"), "3,0") // 3 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("8526", "8511"), "2,0") // 2 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("8526", "8411"), "1,0") // 1 bull, 0 pgia
			;

		testcase.setname("Play with dummy choosers and guessers")
			.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)	
			.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101) 
			.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)   
			;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		RandomGuesser randy_g;
		for (uint i = 0; i < 100; ++i)
		{
			testcase.CHECK_EQUAL(play(randy, smarty, 1, 100) <= 10, true); // smarty should always win in at most 10 turns!
		}

		

		testcase.setname("Random chooser with smart guesser")
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true)
			.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 10, true);

		grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: " << grade << endl;
	return 0;
}

