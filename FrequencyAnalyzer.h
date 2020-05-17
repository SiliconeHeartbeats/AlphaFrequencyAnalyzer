#ifndef FREQUENCYANALYZER_H
#define FREQUENCYANALYZER_H
#include <iostream>
#include <string>
#include <vector>

class ANFrequency {


	std::vector<char> inputQuote; //input chars
	std::vector<char> whiteSpaceFreeInput; //input chars with whitespace removed to calculate letter frequency
	std::vector<char> symbols = { 'a','b','c','d','e','f','g','h','i','j',		//alphabet vector used for reference
							   'k','l','m','n','o','p','q','r','s','t',
								'u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9' };

	std::vector<int> occurences{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };  //each of the 26 elements represents how many times a respective letter is used
	std::vector<int> spacePoints;		//keeps track of every space that whitespace was used
	std::vector<float> frequency;		//stores number of times a letter appears proportional to input size

public:
	//Converts upper case letters to lower case and replaces the appropriate element. Ignores numbers.
	//Any cipher based on the variance of case value is made unsolvable by this function.
	void homogenize(std::vector<char>& input) {
		
		std::vector<char> upperCaseSymbols = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
											  'S','T','U','V','W','X','Y','Z' };
		
		for (int i = 0; i < input.size(); i++) {
			for (int j = 0; j < 26; j++) {
				if (input.at(i) == upperCaseSymbols.at(j)) {
					input.at(i) = symbols.at(j);
				}
			}
		}
		
		return;
	}

	//Inserts input into string, which is then copied over into char vector. Note that this only works if
	//input is all lowercase and has zero punctuation.
	void scan() {
		
		std::string inputquot3;
		std::getline(std::cin, inputquot3);
		std::copy(inputquot3.begin(), inputquot3.end(), std::back_inserter(inputQuote));
		homogenize(inputQuote);
		return;
	}
	//increments the appropriate element of occurences for every letter used in input
	//
	void letterCount() {
		
		for (int i = 0; i < inputQuote.size(); i++) {
			for (int j = 0; j < 36; j++) {
				if (inputQuote.at(i) == symbols.at(j)) {
					occurences.at(j)++;
				}

			}
		}
		return;
	}
	//removes whitespace from input while storing their position in spacepoints
	//
	void concatenater() {
		
		for (int i = 0; i < inputQuote.size(); i++) {
			if (!(inputQuote.at(i) == ' ')) {
				whiteSpaceFreeInput.push_back(inputQuote.at(i));
			}
			else spacePoints.push_back(i);
		}
		return;
	}
	//adds decimal percentage of appearance of a given letter to frequency vector. these values are multiplied by 100
	//to make them more intuitive as percentages
	void averages() {
		
		for (int i = 0; i < 36; i++) {
			frequency.push_back(100 * (float)occurences.at(i) / whiteSpaceFreeInput.size());
		}
		return;
	}
	//streamlines building of class object
	//
	void build() {
		
		scan();
		letterCount();
		concatenater();
		averages();
		return;
	}
	//prints letter, how many times letter occurs in input, and the percentage of that letters appearance in the given input.
	//
	void printfrequency() {

		for (int i = 0; i < 36; i++) {
			
			std::cout << symbols.at(i) << "    ";
			std::cout << occurences.at(i) << "    ";
			std::cout << frequency.at(i) << "%";
			std::cout << "\n";
		}
		return;
	}
};

#endif
