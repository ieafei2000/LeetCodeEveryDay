// reversePrint.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

vector<int> reversePrint(ListNode* head) 
{
    vector<int> res;

    //若链表为空
    if (head == NULL)
    {
        return res;
    }

    //双指针初始化
    ListNode* p = head;
    ListNode* q = head->next;
    ListNode* temp;
    //断开
    p->next = nullptr;

    while (q)
    {
        //双指针循环赋值移位
        temp = q->next;
        q->next = p;
        p = q;
        q = temp;
    }

    //head指针更新指向反转后的头部
    head = p;

    while (head)
    {
        //cout << head->val << endl;
        res.push_back(head->val);
        head = head->next;
    }

    return res;
}

int main()
{
    ListNode* head;
    head = (ListNode*)malloc(sizeof(ListNode));
    head->next = NULL;
    head->val = 0;
    ListNode* p, * q;
    p = head;
    for (int i = 1; i <= 10; i++)
    {
        q = (ListNode*)malloc(sizeof(ListNode));
        q->val = i;
        q->next = NULL;
        p->next = q;
        p = q;
    }

    reversePrint(head);
}

