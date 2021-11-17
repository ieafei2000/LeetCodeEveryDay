#include <iostream>
#include <vector>

using namespace std;

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

//二分查找，缩短遍历时间O（n）至对数级别
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

int main()
{
	vector<int> numbers = { 3,4,5,1,2 };
	std::cout << minArray2(numbers) << std::endl;
}

