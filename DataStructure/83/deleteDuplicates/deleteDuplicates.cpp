#include <iostream>
#include <map>

using namespace std;


//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

int main()
{
    int a = 1;
    int* p1 = new int();
    int* p2 = new int();

    cout << p1 << " " << p2 << endl;

    p1 = &a;
    p2 = &a;

    cout << p1 << " " << p2 << endl;

}



