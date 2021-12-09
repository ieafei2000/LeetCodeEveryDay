# 解题思路
1. 采用快慢指针，快指针fast一次行进两个节点，慢指针一次行进一个节点
2. 当fast->next 与 fast->next->next不为空时，每次行进判定fast是否与slow相等即可
3. 即只有存在环,则快跑运动员终究会超过慢运动员(每次距离缩短1)

## 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	bool hasCycle(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return false;

		ListNode* slow = head;
		ListNode* fast = head;

		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;

			if (fast == slow)
				return true;
		}
		return false;
	}
};
```

## 通过率
执行用时（50%） 内存消耗(60%)