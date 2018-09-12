#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

class Solution
{
	public:
	int calPoints(vector<string>& ops)
	{
		int sum = 0;
		stack<int> s;
		int tmp = 0;
		for ( int i = 0; i < ops.size(); i++ )
		{
			if ( ops[i] == "C" )
			{
				tmp = s.top();
				sum -= tmp;
				s.pop();
			}
			else if ( ops[i] == "D" )
			{
				tmp = s.top();
				sum += tmp * 2;
				s.push(tmp * 2);
			}
			else if ( ops[i] == "+" )
			{
				tmp = s.top();
				s.pop();
				int addSum = tmp + s.top();
				sum += addSum;
				s.push(tmp);
				s.push(addSum);
			}
			else
			{
				tmp = atoi(ops[i].c_str());
				sum += tmp;
				s.push(tmp);
			}
		}
		return sum;
	}
};

int main()
{
	return 0;
}