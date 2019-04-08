#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string decodeString(string s)
	{

		string res;
		string str;
		stack<string> st;
		bool flag = false;
		int num = 0;
		for ( int i = 0; i < s.size(); i++ )
		{
			if ( s[i] == '[' )
			{
				st.push(str);
				str = "";
			}
			else if ( s[i] == ']' )
			{
				if ( str.compare("") == 0 )
				{
					str = st.top();
					st.pop();
				}
				string top = st.top();
				st.pop();
				string numStr;
				string s;
				for ( int j = 0; j < top.size(); j++ )
				{
					if ( isdigit(top[j]) == 1 )
						numStr += top[j];
					else
						s += top[j];
				}
				if ( numStr.compare("") == 0 )
					numStr = "1";
				int num = str2int(numStr);
				string result;
				for ( int j = 0; j < num; j++ )
					result += str;
				result = s + result;
				str = result;
			}
			else
				str += s[i];
		}
		if ( !st.empty() )
		{
			string s = st.top();
			st.pop();
			string numStr = st.top();
			st.pop();
			int num = str2int(numStr);
			string result;
			for ( int j = 0; j < num; j++ )
				result += str;
			res += result;
		}
		if ( st.empty() && str.compare("") != 0 )
			res += str;
		return res;
	}

	int str2int(const string& str)
	{
		int res;
		stringstream ss(str);
		ss >> res;
		return res;
	}
};

int main()
{
	return 0;
}