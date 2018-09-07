#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
	bool judgeCircle(string moves)
	{
		vector<int> position = { 0, 0 };
		for ( int i = 0; i < moves.size(); i++ )
		{
			moveTo(position, moves[i]);
		}
		if ( position[0] == 0 && position[1] == 0 )
			return true;
		return false;
	}

	void moveTo(vector<int> &position, char move)
	{
		switch ( move )
		{
			case 'L':
				position[0]--;
				break;
			case 'D':
				position[1]--;
				break;
			case 'R':
				position[0]++;
				break;
			case 'U':
				position[1]++;
				break;
		}
	}
};

int main()
{
	return 0;
}