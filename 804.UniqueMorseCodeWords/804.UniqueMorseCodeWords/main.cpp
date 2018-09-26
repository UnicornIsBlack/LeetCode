#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
	public:
	int uniqueMorseRepresentations(vector<string>& words)
	{	
		set<string> wordSet;
		for ( int i = 0; i < words.size(); i++ )
		{
			string morse = wordToMorse(words[i]);
			set<string>::iterator it;
			it = wordSet.find(morse);
			if ( it != wordSet.end() )
				continue;
			wordSet.insert(morse);
		}
		return wordSet.size();
	}
	string wordToMorse(string word)
	{
		vector<string> morseCode = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
			".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
			".--", "-..-", "-.--", "--.." };
		string morse = "";
		for ( int i = 0; i < word.size(); i++ )
		{
			morse += morseCode[word[i] - 'a'];
		}
		return morse;
	}
};

int main()
{
	return 0;
}