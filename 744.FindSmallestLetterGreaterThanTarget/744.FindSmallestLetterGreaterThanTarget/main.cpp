#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	char nextGreatestLetter(vector<char>& letters, char target)
	{
		char letter = letters[0];
		bool notFind = true;
		for ( int i = 0; i < letters.size(); i++ )
		{
			if ( letters[i] > target && notFind )
			{
				letter = letters[i];
				break;
			}
		}
		return letter;
	}
};

int main()
{
	return 0;
}