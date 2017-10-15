#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*Austin Docherty, 15/10/2017
  Q: Write a function to check if a string is a permutation of a palindrome.
*/

int main()
{

	ifstream fs("Q4test.txt");

	string possiblePalindrome;

	int numberOfOddFreqChar;
	int charFreq[128];
	int cases;

	fs >> cases;
	fs.ignore();

	for(int i = 0; i < cases; i++)
	{
		getline(fs, possiblePalindrome);
		fill_n(charFreq, 128, 0);
		numberOfOddFreqChar = 0;

		for(int j = 0; j < possiblePalindrome.length(); j++)
		{
			 if('A' <= possiblePalindrome[j] &&
			    'Z' >= possiblePalindrome[j])
			{
				charFreq[possiblePalindrome[j]+32]++;
			}

			else
			{
				charFreq[possiblePalindrome[j]]++;
			}
		}

		for(int k = 0; k < 128; k++)
		{
			if((charFreq[k] % 2) == 1)
			{
				numberOfOddFreqChar++;
			}
		}

		if(numberOfOddFreqChar >= 3)
		{
			cout << possiblePalindrome << " is not a permutation of a palindrome" << endl;
		}

		else if(((possiblePalindrome.length() - numberOfOddFreqChar) % 2) == 0)
		{
			cout << possiblePalindrome << " is a permutation of a palindrome" << endl;
		}

		else
		{
			cout << possiblePalindrome << " is not a permutation of a palindrome" << endl;
		}
	}

return 0;
}
