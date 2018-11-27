#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string convert(string s, int numRows)
	{
		if ( numRows == 1 )
			return s;
		int index = 0;
		int next = 0;
		vector<string> strSub(numRows);
		for ( int i = 0; i < s.size(); i++ )
		{
			if ( index == next )
			{
				next = index + numRows - 1;
				for ( int j = i, k = 0; j < s.size() && k < strSub.size(); j++, k++ )
				{
					strSub[k] = strSub[k] + s[j];
				}
				i += (numRows - 1);
			}
			else
			{
				strSub[next - index] = strSub[next - index] + s[i];
			}
			index++;
		}
		string result;
		for ( int i = 0; i < strSub.size(); i++ )
		{
			result += strSub[i];
		}
		return result;
	}

};

int main()
{
	return 0;
}