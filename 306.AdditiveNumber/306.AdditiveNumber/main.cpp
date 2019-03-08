#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool isAdditiveNumber(string num)
	{
		if ( num.size() < 3 )
			return false;
		for ( int i = 1; i < num.size(); i++ )
		{
			for ( int j = 1; i + j < num.size(); j++ )
			{
				

			}
		}
	}

	bool isAdditive(string num, int i, int j)
	{
		long num1 = str2int(string(num.begin(), num.begin() + i));
		if ( num[i] == '0' )
			return false;
		long num2 = str2int(string(num.begin() + i, num.begin() + i + j));
		int num3Start = i + j;
		while ( true )
		{
			long num3 = num1 + num2;
			string str3 = int2str(num3);
		}
	}
	string int2str(const long& num)
	{
		string res;
		stringstream stream;
		stream << num;
		stream >> res;
		return res;
	}
	long str2int(const string& str)
	{
		long res;
		stringstream stream(str);
		stream >> res;
		return res;
	}
};

int main()
{
	return 0;
}