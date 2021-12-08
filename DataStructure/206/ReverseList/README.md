# 解题思路
1. 头插法，每次从链表中取一个节点插入头部
2. ps:为啥每次写链表都晕的很

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
    ListNode* reverseList(ListNode* head) 
    {
                if (head == nullptr)
        {
            return head;
        }

        ListNode* ans = new ListNode(0, head);

        ListNode* p = head;
        ListNode* q = p->next;
        p->next = nullptr;

        while (q != nullptr)
        {
            p = q->next;
            q->next = ans->next;
            ans->next = q;
            q = p;
        }
        return ans->next;
    }
};
```

## 通过率
执行用时（45%） 内存消耗（50%）