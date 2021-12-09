# 解题思路
1. 对两个链表同时遍历，当存在一个链表未被遍历完时，进行比较
2. 若list1已到结尾，则直接存储list2，反之，存储list1
3. 若当前都未到结尾，则比较对应val，存储val小值对应节点
4. 开辟一个head节点，以及ans移动节点用于链接两个链表中的节点，每次新增节点后，ans = ans->next

## 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* head = new ListNode();
		ListNode* ans = head;

		while (list1 != nullptr || list2 != nullptr)
		{
			if (list1 == nullptr)
			{
				ans->next = list2;
				list2 = list2->next;
			}
			else if (list2 == nullptr)
			{
				ans->next = list1;
				list1 = list1->next;
			}
			else
			{
				if (list1->val < list2->val)
				{
					ans->next = list1;
					list1 = list1->next;
				}
				else
				{
					ans->next = list2;
					list2 = list2->next;
				}
			}
            ans = ans->next;
		}

		// while (head->next)
		// {
		// 	cout << head->next->val << endl;
		// 	head = head->next;
		// }

		return head->next;
	}
};
```

## 通过率
执行用时（25%） 内存消耗（75%）