#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct Index
{
	int row;
	int col;
	bool operator <(const Index& other) const
	{
		if ( row < other.row )
			return true;
		else if ( row == other.row )
		{
			if ( col < other.col )
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
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
	{
		queue<Index*> q;
		map<Index,bool> indexMap;
		Index* index = new Index;
		index->row = sr;
		index->col = sc;
		q.push(index);
		indexMap.insert(make_pair(*index, true));
		while ( !q.empty() )
		{
			Index* qIndex = q.front();
			q.pop();
			for ( int i = 0; i < 4; i++ )
			{
				Index* nextIndex = moveTo(image, qIndex, i);
				if ( nextIndex == NULL )
					continue;

				map<Index, bool>::iterator iter;
				iter = indexMap.find(*nextIndex);
				if ( iter != indexMap.end() )
					continue;
				indexMap.insert(make_pair(*nextIndex, true));
				q.push(nextIndex);
			}
			image[qIndex->row][qIndex->col] = newColor;
		}
		return image;
	}

	Index* moveTo(vector<vector<int>>& image, Index* index, int i)
	{
		Index* nextIndex = NULL;
		int row = image.size();
		int col = image[0].size();
		switch ( i )
		{
			case 0:
				if ( index->col - 1 >= 0 && image[index->row][index->col] == image[index->row][index->col - 1] )
				{
					nextIndex = new Index;
					nextIndex->row = index->row;
					nextIndex->col = index->col - 1;
				}
				break;
			case 1:
				if ( index->row + 1 < row && image[index->row][index->col] == image[index->row + 1][index->col] )
				{
					nextIndex = new Index;
					nextIndex->row = index->row + 1;
					nextIndex->col = index->col;
				}
				break;
			case 2:
				if ( index->col + 1 < col && image[index->row][index->col] == image[index->row][index->col + 1] )
				{
					nextIndex = new Index;
					nextIndex->row = index->row;
					nextIndex->col = index->col + 1;
				}
				break;
			case 3:
				if ( index->row - 1 >= 0 && image[index->row][index->col] == image[index->row - 1][index->col] )
				{
					nextIndex = new Index;
					nextIndex->row = index->row - 1;
					nextIndex->col = index->col;
				}
				break;
			default:
				break;
		}
		return nextIndex;
	}
};


int main()
{
	return 0;
}