#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string getHint(string secret, string guess)
	{
		if ( secret.size() != guess.size() )
			return "";
		string res;
		vector<int> correct(10, 0);
		vector<int> sec(10, 0);
		vector<int> gue(10, 0);
		for ( int i = 0; i < secret.size(); i++ )
		{
			if ( secret[i] == guess[i] )
				correct[secret[i] - '0']++;
			sec[secret[i] - '0']++;
			gue[guess[i] - '0']++;
		}
		int bull = 0;
		int cow = 0;
		for ( int i = 0; i < 10; i++ )
		{
			bull += correct[i];
			cow += (min(sec[i], gue[i]) - correct[i]);
		}
		res = int2str(bull) + "A" + int2str(cow) + "B";
		return res;
	}
	string int2str(const int& temp)
	{
		string res;
		stringstream stream;
		stream << temp;
		res = stream.str();
		return res;
	}

};

int main()
{
	return 0;
}