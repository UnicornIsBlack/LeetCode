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

1. 数组连续子序列相加

		#include <numeric>
		sum = accumulate(nums.begin(),nums.end(),0);//0 is sum's init
2. 最大或最小数

		#include <algorithm>
		max();
		min();
3. 判断字符是否为字母，是否为数字

		if ( isalpha(c) != 0 )//c is a-z
		if ( isdigit(c) != 0 )//c is num


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
