# LeetCode
leetcode

# 指针类型题目 #


## 1. 链表 ##

----------
1. 函数参数传入的链表都没有链表的头，从第一个有数据的节点开始
2. 函数返回一个链表，这个链表也没有头


----------


## 2. 内存分配 ##

----------
1. 二维数组内存分配
二维数组分配内存空间要先分配行，再分配列
释放时要先释放列，再释放行




	    //内存分配
    	int **arr = (int **)malloc(n*sizeof(int *));
    	for(i=0;i<n;i++)
    		arr[i] = (int *)malloc(m*sizeof(int));
    	
    	//内存释放
    	for (i = 0; i < n; i++)
    		free(arr[i]);
    	free(arr);


----------
## 3.链表头 ##

LeetCode里的链表题目，都没有头节点，第一个节点就有数值。


# 整型 #

## 1. 内存溢出 ##

进行平方判断时，用除法不用乘法，因为乘法会使整型整数溢出。



## 2.  ##



# 斐波那契额数列生成 #
## 1. 方法一 ##
使用递归的方法

	int climbStairs(int n)
    {
    	if ( n == 0 || n == 1 )
		{
			return 1;
		}
		return climbStairs(n - 1) + climbStairs(n - 2);
    }

## 2. 方法二 ##
使用for循环的方法

    int climbStairs(int n)
    {
    	int stepOne = 1;
    	int stepTwo = 1;
    	int stepReturn = 1;
    	for ( int i = 2; i <= n; i++ )
    	{
    		stepReturn = stepOne + stepTwo;
    		stepOne = stepTwo;
    		stepTwo = stepReturn;
    	}
    	return stepReturn;
    }

# 求三角形面积 #

## 已知三个点坐标 ##

	double triangleArea(vector<int>& a, vector<int>& b, vector<int>& c)
	{
		double area = 0.5*abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - a[1] * b[0] - b[1] * c[0] - c[1] * a[0]);
		return area;
	}

# 位运算 #

## 1. 异或运算 ##
1. 任何两个相同的数异或得0
2. 任何数与0异或得其本身




# 字符串 #

----------
1. 做字符串题时一定要在字符串结尾加'\0'。




# 排序 #

----------

## 1. 快排 ##

	void sort_quick(int* nums, int low, int high)
	{
		if ( low > high )
			return;
		int key = nums[low];
		int tmp = 0;
		int i = low, j = high;
		while ( i < j )
		{
			while ( i < j && nums[j] >= key )
				j--;
			while ( i < j && nums[i] <= key )
				i++;
			if ( i < j )
			{
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
		nums[low] = nums[i];
		nums[i] = key;
		sort_quick(nums, low, i - 1);
		sort_quick(nums, i + 1, high);
	}


## 2. 冒泡 ##






# C++ #

## 常用函数 ##

1. set
	
		set<string>::iterator it = wordSet.find(words[i].substr(0, len));
		if ( it != wordSet.end() )//存在
2. 排序

		sort(nums.begin(), nums.end());//由小到大
3. string

		string str = A + A;
		str.append(A);
		J.find(S[i]) != -1//判断S中的S[i]元素是否在J中
	
		//判断字符串B是否是C子串
		string::size_type it;
		it = C.find(B);
		if ( it != string::npos )

		//将string中元素全部转换为小写
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		//将string中元素全部转换为大写
		transform(str.begin(), str.end(), str.begin(), ::toupper);

		//字符串str后添加char类型c，不能使用+=
		str = str + c;

		//str删除从index开始的count个字符
		str.erase(index,count);
		
		//str截取从index开始，长度为len的字符串
		str.substr(index,len);
4. 数据交换

		swap(a,b);//a，b交换值
5. 累计求和

		double sum = accumulate(nums.begin(), nums.begin() + k, 0);
		//从nums数组begin开始的k个元素求和，sum初始为0
6. vector
				
		vector<object> obj;
		object o;
		obj.push_back(o);//在vector尾部添加元素o
		nums.insert(nums.begin() + i, val);//在index为i处插入val，i处原值后移
		myList.erase(myList.begin() + index);//删除index处值

		vector<int>::iterator it;//在primes中寻找setBits是否存在
		it = find(primes.begin(), primes.end(), setBits);
		if ( it != primes.end() )//存在
 
7. 数组连续子序列相加

		#include <numeric>
		sum = accumulate(nums.begin(),nums.end(),0);//0 is sum's init
8. 最大或最小数

		#include <algorithm>
		max();
		min();
9. 判断字符是否为字母，是否为数字

		if ( isalpha(c) != 0 )//c is a-z
		if ( isdigit(c) != 0 )//c is num
10. 自定义结构体

		struct Index
		{
			int row;
			int col;
			bool operator <(const Index& other) const//在使用map、set时排序
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

11. string to int

		int count = atoi(str[0].c_str());
		
		#include <sstream>
		void int2str(const int &int_temp,string &string_temp)  
		{  
		        stringstream stream;  
		        stream<<int_temp;  
		        string_temp=stream.str();   //此处也可以用 stream>>string_temp  
		}  

		void str2int(int &int_temp,const string &string_temp)  
		{  
		    stringstream stream(string_temp);  
		    stream>>int_temp;  
		}  

12. map

		//创建map变量
		map<string, int> domainMap;
		//创建迭代器
		map<string, int>::iterator it;
		//查询
		it = domainMap.find(domain);

		//修改、插入
		if ( it != domainMap.end() )
		{
			domainMap[it->first] += count;
		}
		else
			domainMap.insert(make_pair(domain, count));
		//遍历
		for ( it = domainMap.begin(); it != domainMap.end(); it++ )
		{
			string count;
			int2str(it->second, count);

			string str = count + " " + it->first;
			domainsCount.push_back(str);
		}
13. new

		struct TreeNode
		{
			int val;
			TreeNode *left;
			TreeNode *right;
			TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		};
		TreeNode* resultTree = new TreeNode(nodes[0]);
14. 


## C++缺少的函数 ##

1. string split()

		vector<string> split(const string &s, const string &seperator)
		{
			vector<string> result;
			typedef string::size_type string_size;
			string_size i = 0;
		
			while ( i != s.size() )
			{
				//找到字符串中首个不等于分隔符的字母；
				int flag = 0;
				while ( i != s.size() && flag == 0 )
				{
					flag = 1;
					for ( string_size x = 0; x < seperator.size(); ++x )
					if ( s[i] == seperator[x] )
					{
						++i;
						flag = 0;
						break;
					}
				}
		
				//找到又一个分隔符，将两个分隔符之间的字符串取出；
				flag = 0;
				string_size j = i;
				while ( j != s.size() && flag == 0 )
				{
					for ( string_size x = 0; x < seperator.size(); ++x )
					if ( s[j] == seperator[x] )
					{
						flag = 1;
						break;
					}
					if ( flag == 0 )
						++j;
				}
				if ( i != j )
				{
					result.push_back(s.substr(i, j - i));
					i = j;
				}
			}
			return result;
		}
2. 


# TwoSum #

## Hash ##

1. set:有序的，底层基于RB-Tree，unordered_set:无序的，底层基于HashTable




# 关系矩阵的传递闭包 #

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			if ( sides[j][i] == 1 )
			{
				for ( int k = 0; k < n; k++ )
				{
					if ( sides[i][k] == 1 )
						sides[j][k] = 1;
				}
			}
		}
	}
