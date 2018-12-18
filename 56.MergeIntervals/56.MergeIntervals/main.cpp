#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution
{
	public:
	vector<Interval> merge(vector<Interval>& intervals)
	{
		if ( intervals.size() < 2 )
			return intervals;
		sort_quick(intervals, 0, intervals.size() - 1);
		Interval former = intervals[0];
		vector<Interval> result;
		for ( Interval interval : intervals )
		{
			if ( former.end >= interval.start )
			{
				former.start = min(former.start, interval.start);
				former.end = max(former.end, interval.end);
			}
			else
			{
				result.push_back(former);
				former = interval;
			}
		}
		result.push_back(former);
		return result;
	}
	void sort_quick(vector<Interval>& intervals, int low, int high)
	{
		if ( low > high )
			return;
		int i = low;
		int j = high;
		Interval key = intervals[i];
		while ( i < j )
		{
			while ( i < j && intervals[j].start >= key.start )
				j--;
			while ( i < j && intervals[i].start <= key.start )
				i++;
			if ( i < j )
			{
				Interval tmp = intervals[i];
				intervals[i] = intervals[j];
				intervals[j] = tmp;
			}
		}
		intervals[low] = intervals[i];
		intervals[i] = key;
		sort_quick(intervals, low, i - 1);
		sort_quick(intervals, i + 1, high);
	}

};

int main()
{
	Interval val1(1, 2);
	Interval val2(2, 3);
	val1 = val2;
	cout << val1.start << val1.end << endl;
	return 0;
}