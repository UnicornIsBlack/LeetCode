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
				if ( isAdditive(num, i, j) )
					return true;
			}
		}
		return false;
	}

	bool isAdditive(string num, int i, int j)
	{
		if ( (num[0] == '0' && i != 1) || (num[i] == '0' && j != 1) )
			return false;
		long num1 = str2int(string(num.begin(), num.begin() + i));		
		long num2 = str2int(string(num.begin() + i, num.begin() + i + j));
		int num3Start = i + j;
		while ( num3Start < num.size() )
		{
			long num3 = num1 + num2;
			string str3 = int2str(num3);
			if ( num3Start + str3.size() > num.size() )
				return false;
			if ( str3.compare(num.substr(num3Start, str3.size())) != 0 )
				return false;
			num3Start += str3.size();
			num1 = num2;
			num2 = num3;
		}
		return true;
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