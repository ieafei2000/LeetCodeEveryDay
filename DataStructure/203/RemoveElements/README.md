# 解题思路
1. 双指针p,q分别遍历链表，q在p后面
2. 若q->val == val，则执行删除当前q所指节点，即p->next = q->next，同时q后移一个节点
3. 若不等，则p，q同时后移一位
4. ps:开辟新节点p指向head（q），保证head->val == val，也可删除,初始化最后将p赋值给head，最后直接返回head即可（为啥感觉链表这里老晕呢）

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
	ListNode* removeElements(ListNode* head, int val)
	{
		if (head == nullptr)
			return head;

		ListNode* p = new ListNode();
		ListNode* q = head;
		p->next = q;
		head = p;

		while (q)
		{
			if (q->val == val)
			{
				p->next = q->next;
				q = q->next;
			}
			else
			{
				p = q;
				q = q->next;
			}
		}

		return head->next;
	}
};
```

## 通过率
执行用时（99%） 内存消耗(95%)