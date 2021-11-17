# 解题思路
1. 若为旋转列表，则必定存在numbers[i] > numbers[i+1]，此时返回numbers[i+1]即可，将标记flag置为true
2. 若flag为false，说明为递增列表，此时返回numbers[0]即可

# 补充
可通过二分法求解，定位右排序数组的第一个元素

# 通过率
执行用时（85%） 内存消耗（90%）

# 代码
方法一
```cpp
class Solution {
public:
int minArray(vector<int>& numbers)
{
		int res = 0;
	bool flag = false;

	for (int i = 0; i < numbers.size() - 1; i++)
	{
		if (numbers[i] > numbers[i + 1])
		{
			res = numbers[i + 1];
			flag = true;
			break;
		}
	}

	if (!flag)
	{
		res = numbers[0];
	}

	return res;
}
};
```
方法二
```
int minArray2(vector<int>& numbers)
{
	int low = 0;
	int high = numbers.size() - 1;
	int mid = 0;
	while (low < high)
	{
		mid = low + (high - low) / 2;
		if (numbers[mid] > numbers[high])
		{
			low = mid + 1;
		}
		else if (numbers[mid] < numbers[high])
		{
			high = mid;
		}
		else if (numbers[mid] == numbers[high])
		{
			high -= 1;
		}
	}
	return numbers[low];
}
```
