#include <iostream>
#include <string>
#include <vector>


using namespace std;
/*
// Employee info
class Employee {
public:
// It's the unique ID of each node.
// unique id of this employee
int id;
// the importance value of this employee
int importance;
// the id of direct subordinates
vector<int> subordinates;
};
*/

//Employee info
class Employee
{
	public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution
{
	public:
	int getImportance(vector<Employee*> employees, int id)
	{
		int allImportance = 0;
		vector<int> sub;
		for ( int i = 0; i < employees.size(); i++ )
		{
			if ( employees[i]->id == id )
			{
				allImportance = employees[i]->importance;
				sub = employees[i]->subordinates;
			}
		}

		for ( int i = 0; i < sub.size(); i++ )
		{
			allImportance += getImportance(employees, sub[i]);
		}
		return allImportance;
	}
};

int main()
{
	return 0;
}