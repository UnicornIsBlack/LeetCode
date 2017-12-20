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