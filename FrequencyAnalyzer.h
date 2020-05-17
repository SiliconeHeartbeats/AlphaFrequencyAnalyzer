#ifndef FREQUENCYANALYZER_H
#define FREQUENCYANALYZER_H
#include <iostream>
#include <string>
#include <vector>

class ANFrequency {

	
	std::vector<char> inputquote; //input chars
	std::vector<char> whitespacefreeinput; //input chars with whitespace removed to calculate letter frequency
	std::vector<char> symbols = { 'a','b','c','d','e','f','g','h','i','j',		//alphabet vector used for reference
							   'k','l','m','n','o','p','q','r','s','t',
								'u','v','w','x','y','z' };   

	std::vector<int> occurences{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };  //each of the 26 elements represents how many times a respective letter is used
	std::vector<int> spacepoints;		//keeps track of every space that whitespace was used
	std::vector<float> frequency;		//stores number of times a letter appears proportional to input size

public:
//Inserts input into string, which is then copied over into char vector. Note that this only works if
//input is all lowercase and has zero punctuation.
	void scan() {
		std::string inputquot3;
		std::getline(std::cin, inputquot3);
		std::copy(inputquot3.begin(), inputquot3.end(), std::back_inserter(inputquote));
		return;
	}
//increments the appropriate element of occurences for every letter used in input
//
	void lettercount() {
		for (int i = 0; i < inputquote.size(); i++) {
			for (int j = 0; j < 26; j++) {
				if (inputquote.at(i) == symbols.at(j)) {
					occurences.at(j)++;
				}

			}
		}
		return;
	}
//removes whitespace from input while storing their position in spacepoints
//
	void concatenater() {			
		for (int i = 0; i < inputquote.size(); i++) {
			if (!(inputquote.at(i) == ' ')) {
				whitespacefreeinput.push_back(inputquote.at(i));
			}
			else spacepoints.push_back(i);
		}
		return ;
	}
//adds decimal percentage of appearance of a given letter to frequency vector. these values are multiplied by 100
//to make them more intuitive as percentages
	void averages() {
		for (int i = 0; i < 26; i++) {
			frequency.push_back(100 * (float)occurences.at(i) / whitespacefreeinput.size());
		}
		return;
	}
//streamlines building of class object
//
	void build() {
		scan();
		lettercount();
		concatenater();
		averages();
		return;
	}
//prints letter, how many times letter occurs in input, and the percentage of that letters appearance in the given input.
//
	void printfrequency() {

		for (int i = 0; i < 26; i++) {
			std::cout << symbols.at(i) << "  ";
			std::cout << occurences.at(i) << "  ";
			std::cout << frequency.at(i) << "%";
			std::cout << "\n";
		}
		return;
	}
};

#endif
