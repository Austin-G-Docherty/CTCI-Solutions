#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*Austin Docherty, 13/10/2017
  Q: Given two strings, write a method to decide if one is a permutation of the other.
*/

int main(void)
{
	ifstream fs("Q2test.txt");

	bool isPermutation;
	
	int i, j;
	char testCases;
	fs >> testCases;

	string firstWord;
	string secondWord;

	int characterFrequency[128];
	for(i = 0; i < testCases - '0'; i++)
	{
		fs >> firstWord >> secondWord;
		isPermutation = true;

		if(firstWord.length() != secondWord.length())
		{
			isPermutation = false;
		}

		else
		{
			fill_n(characterFrequency, 128, 0);

			for(j = 0; j < firstWord.length(); j++)
			{
				characterFrequency[firstWord[j]]++;
				characterFrequency[secondWord[j]]--;
			}

			for(j = 0; j < 128; j++)
			{
				if(characterFrequency[j] != 0)
				{ 
					isPermutation = false;
					break;
				}
			}
		}

		if(isPermutation)
		{
			cout << firstWord << " and " << secondWord << " are permutations." << endl;
		}

		else
		{
			cout << firstWord << " and " << secondWord << " are not permutations." << endl;
		}
	}

return 0;
}
