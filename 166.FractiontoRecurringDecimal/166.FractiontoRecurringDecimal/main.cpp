#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
class Solution
{
	public:
	string fractionToDecimal(int numerator, int denominator)
	{
		if ( numerator == 0 )
			return "0";
		long long num = numerator;
		long long den = denominator;
		long long b = -2147483648;
		bool sign = num*den < 0;
		if ( num == b )
			sign = den < 0 ? false : true;
		string res;
		num = abs(num);
		den = abs(den);

		long long a = num / den;
		int2str(a, res);
		if ( res == "-2147483648" )
			res.erase(0, 1);
		res = sign ? "-" + res : res;

		long long mod = num%den;

		return mod == 0 ? res : res + "." + getDec(mod, den);
	}

	string getDec(long long mod, long long den)
	{
		map<long long, int> modMap;
		string result;
		for ( int i = 0; mod != 0 && modMap.find(mod) == modMap.end(); i++ )
		{
			modMap[mod] = i;
			mod *= 10;
			long long a = mod / den;
			string aStr;
			int2str(a, aStr);
			result += aStr;
			mod %= den;
		}

		if ( modMap.find(mod) != modMap.end() )
		{
			int index = modMap[mod];
			result.insert(index, "(", 1);
			result.push_back(')');
		}
		return result;
	}

	void str2int(int &int_temp, const string &string_temp)
	{
		stringstream stream(string_temp);
		stream >> int_temp;
	}
	void int2str(const int &int_temp, string &string_temp)
	{
		stringstream stream;
		stream << int_temp;
		string_temp = stream.str();   //此处也可以用 stream>>string_temp  
	}
};


int main()
{
	return 0;
}