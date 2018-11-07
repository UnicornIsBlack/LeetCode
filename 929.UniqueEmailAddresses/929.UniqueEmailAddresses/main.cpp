#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
	public:
	int numUniqueEmails(vector<string>& emails)
	{
		set<string> addresses;

		for ( int i = 0; i < emails.size(); i++ )
		{
			vector<string> email = split(emails[i], '@');
			string address;
			vector<string> localName = split(email[0], '+');
			for ( int j = 0; j < localName[0].size(); j++ )
			{
				if ( localName[0][j] == '.' )
				{
					localName[0].erase(j, 1);
					j--;
				}
			}
			address = localName[0] + '@' + email[1];
			addresses.insert(address);
		}

		return addresses.size();
	}

	vector<string> split(string email, char c)
	{
		vector<string> results;
		for ( int i = 0; i < email.size(); i++ )
		{
			if ( email[i] == c )
			{
				results.push_back(email.substr(0, i));
				results.push_back(email.substr(i + 1));
				break;
			}
		}
		return results;
	}
};

int main()
{
	return 0;
}