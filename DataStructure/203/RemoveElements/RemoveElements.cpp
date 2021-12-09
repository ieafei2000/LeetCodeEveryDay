#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

		return head;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
