#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*Austin Docherty, 14/10/2017
  Q: Write a method to replace spaces in a string with '%20'.
*/

int main (void)
{
	ifstream fs("Q3test.txt");

	string urlify;
	int    numberOfSpaces = 0;
	int    trueLength;

	getline(fs, urlify);
	fs >> trueLength;

	for(int i = trueLength - 1; i >= 0; i--)
	{
		if(urlify[i] == ' ')
		{
			numberOfSpaces++;

			for(int j = trueLength + (2 * numberOfSpaces) - 1; j > i + 2; j--)
			{
				urlify[j] = urlify[j-2];
			}

			urlify[i]   = '%';
			urlify[i+1] = '2';
			urlify[i+2] = '0';
		}
	}

	cout << "URLified string is: " << urlify << endl;
	return 0;
}
