#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		if ( wordList.size() == 0 )
			return 0;
		int n = wordList.size();
		int endIndex = indexWordList(endWord, wordList);
		if ( endIndex == -1 )
			return 0;
		int beginIndex = indexWordList(beginWord, wordList);
		vector<int> path(n, -1);
		vector<int> moved(n, 0);
		if ( beginIndex != -1 )
		{
			path[beginIndex] = 0;
			moved[beginIndex] = 1;
		}
		string currWord = beginWord;
		int currPath = 1;
		dijkstra(currWord, currPath, path, wordList);
		while ( true )
		{
			int minNum = INT_MAX;
			int index = -1;
			for ( int i = 0; i < n; i++ )
			{
				if ( path[i] == -1 )
					continue;
				if ( path[i] < minNum && moved[i] == 0 )
				{
					minNum = path[i];
					index = i;
				}
			}
			if ( index == -1 )
				break;
			currPath = path[index] + 1;
			currWord = wordList[index];
			moved[index] = 1;
			dijkstra(currWord, currPath, path, wordList);
			if ( path[endIndex] != -1 )
				break;
		}
		return path[endIndex] + 1;
	}

	void dijkstra(string currWord, int currPath, vector<int>& path, vector<string>& wordList)
	{
		for ( int i = 0; i < wordList.size(); i++ )
		{
			if ( path[i] != -1 )
				continue;
			if ( moveTo(currWord, wordList[i]) )
				path[i] = currPath;
		}
	}

	bool moveTo(string beginWord, string endWord)
	{
		if ( beginWord.size() != endWord.size() )
			return false;
		int count = 0;
		for ( int i = 0; i < beginWord.size(); i++ )
		{
			if ( beginWord[i] != endWord[i] )
				count++;
		}
		if ( count == 1 )
			return true;
		return false;
	}

	int indexWordList(string word, vector<string>& wordList)
	{
		for ( int i = 0; i < wordList.size(); i++ )
		{
			if ( word == wordList[i] )
				return i;
		}
		return -1;
	}
};

int main()
{
	return 0;
}