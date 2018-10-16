#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct point
{
	int x;
	int y;

	bool operator <(const point& other) const
	{
		if ( x < other.x )
			return true;
		else if ( x == other.x )
		{
			if ( y < other.y )
				return true;
			else
				return false;
		}
		return false;
	}
};

class Solution
{
	public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
	{
		set<point> pointSet;
		for ( int i = 0; i < obstacles.size(); i++ )
		{
			point p;
			p.x = obstacles[i][0];
			p.y = obstacles[i][1];
			pointSet.insert(p);
		}
		point start;
		start.x = 0;
		start.y = 0;
		int dire = 3;
		for ( int i = 0; i < commands.size(); i++ )
		{
			point next = nextPoint(start, pointSet, dire, commands[i]);
			start = next;
		}
		return start.x*start.x + start.y*start.y;
	}

	point nextPoint(point start, set<point> pointSet, int& dire, int dis)
	{
		switch ( dis )
		{
			case -1:
				dire--;
				dire = dire % 4;
				if ( dire < 0 )
					dire += 4;
				break;
			case -2:
				dire++;
				dire = dire % 4;
				break;
			default:
				if ( dis < 1 || dis > 9 )
					break;
				point before = start;
				point next;
				for ( int i = 1; i <= dis; i++ )
				{
					switch ( dire )
					{
						case 0:
							next.x = before.x - 1;
							next.y = before.y;
							break;
						case 1:
							next.x = before.x;
							next.y = before.y - 1;
							break;
						case 2:
							next.x = before.x + 1;
							next.y = before.y;
							break;
						case 3:
							next.x = before.x;
							next.y = before.y + 1;
							break;
					}
					set<point>::iterator it;
					it = pointSet.find(next);
					if ( it != pointSet.end() )
					{
						return before;
					}
					before = next;
				}
				return next;
		}
		return start;
	}
};

int main()
{
	return 0;
}