#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*Austin Docherty, 12/10/2017
  Q: Implement an algorithm to determine if a string has all unique characters.
     What if you cannot use additional data structures?
*/

int main(void)
{
	ifstream fs("Q1test.txt");

	string stringToTest;

	int i;

	bool hasCharacter[128], hasRepetition;
	fill_n(hasCharacter, 128, false);

	while(getline(fs, stringToTest))
	{
		hasRepetition = false;
		fill_n(hasCharacter, 128, false);
		i = 0;

		while(i < stringToTest.length())
		{
			if(hasCharacter[stringToTest[i]])
			{
				hasRepetition = true;
				break;
			}

			else
			{
				hasCharacter[stringToTest[i]] = true;
			}

			i++;
		}

		if(hasRepetition)
		{
		cout << "'" << stringToTest << "'" << " has a repeated character." << endl;
		}

		else
		{
		cout << "'" << stringToTest << "'" << " has no repeated characters." << endl;
		}
	}

return 0;
}
