
# 解题思路
1. 遍历链表，因为是有序链表，所以每次只需比较相邻位val是否相等即可

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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr)
            return head;

        ListNode* pre = head;
        ListNode* cur = pre->next;

        while (cur != nullptr)
        {
            if (cur->val == pre->val)
            {
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};
```

## 通过率
执行用时（98%） 内存消耗（84%）