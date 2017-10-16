#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*Austin Docherty, 15/10/2017.
  Q: Given two strings, write a function to check if they are one edit away.
*/

int numberOfEdits(string str1, string str2);

int main()
{
	ifstream fs("Q5test.txt");

	int cases;
	fs >> cases;

	string str1, str2;

	for(int i = 0; i < cases; i++)
	{
		fs >> str1 >> str2;

		if(numberOfEdits(str1, str2) < 2)
		{
			cout << str1 << ", " << str2 << " -> true" << endl;
		}

		else
		{
			cout << str1 << ", " << str2 << " -> false" << endl;
		}
	}

return 0;
}

int numberOfEdits(string str1, string str2)
{

	int edits = 0, j, k = 0;

	if(str1.length() < str2.length())
	{
		string temp = str2;
		str2        = str1;
		str1        = temp;
	}

	if(str1.length() != str2.length())
	{
		for(j = 0; j < str1.length(); j++)
		{
			if(str1[k] != str2[j])
			{
				edits++;
				k++;
			}

			k++;
		}
	}

	else
	{
		for(j = 0; j < str2.length(); j++)
		{
			if(str1[j] != str2[j])
			{
				edits++;
			}
		}
	}

return edits;
}
