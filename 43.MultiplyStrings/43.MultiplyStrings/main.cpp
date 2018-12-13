#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
	public:
	string multiply(string num1, string num2)
	{
		string result = "0";
		string zero;
		int end = num2.size() - 1;
		for ( int i = 0; i < num2.size(); i++ )
		{
			string res = multiplyOne(num1, num2[end - i]);
			res += zero;
			zero = zero + '0';
			if ( res[0] == '0' )
				res = "0";
			result = addStr(result, res);
		}
		return result;
	}
	string multiplyOne(string num, char a)
	{
		string result = "0";
		if ( a == '0' )
			return "0";
		else if ( a == '1' )
			return num;
		string zero;
		int end = num.size() - 1;
		for ( int i = 0; i < num.size(); i++ )
		{
			int res = (num[end - i] - '0')*(a - '0');
			string resStr;
			int2str(res, resStr);
			resStr += zero;
			if ( resStr[0] == '0' )
				resStr = "0";
			result = addStr(result, resStr);
			zero = zero + '0';
		}
		return result;
	}
	string addStr(string num1, string num2)
	{
		if ( num2[0] == '0' )
			return num1;
		if ( num1[0] == '0' )
			return num2;
		string result;
		int flag = 0;
		int aLen = num1.size();
		int bLen = num2.size();
		int len = min(aLen, bLen);
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		for ( int i = 0; i < len; i++ )
		{
			int a = num1[end1 - i] - '0';
			int b = num2[end2 - i] - '0';
			int sum = a + b + flag;
			flag = sum / 10;
			int mod = sum % 10;
			char num = mod + '0';
			result = num + result;
		}
		if ( aLen > bLen )
		{
			for ( int i = len; i < aLen; i++ )
			{
				int a = num1[end1 - i] - '0';
				int sum = a + flag;
				flag = sum / 10;
				int mod = sum % 10;
				char num = mod + '0';
				result = num + result;
			}
		}
		else if ( aLen < bLen )
		{
			for ( int i = len; i < bLen; i++ )
			{
				int a = num2[end2 - i] - '0';
				int sum = a + flag;
				flag = sum / 10;
				int mod = sum % 10;
				char num = '0' + mod;
				result = num + result;
			}
		}
		if ( flag )
			result = "1" + result;
		return result;
	}

	void int2str(const int &int_temp, string &string_temp)
	{
		stringstream stream;
		stream << int_temp;
		string_temp = stream.str();
	}
};

int main()
{
	return 0;
}