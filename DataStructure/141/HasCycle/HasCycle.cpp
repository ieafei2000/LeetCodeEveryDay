#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

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

int main()
{
	std::cout << "Hello World!\n";
}
