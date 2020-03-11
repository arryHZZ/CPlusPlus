#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr && pHead2 == nullptr)
		return nullptr;
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;
	ListNode* p1 = pHead1;
	ListNode* p2 = pHead2;
	ListNode* NewHead = nullptr;
	ListNode* p = nullptr;
	while (p1 != nullptr && p2 != nullptr)
	{
		if (NewHead == nullptr)
		{
			if (p1->val < p2->val)
			{
				p = NewHead = p1;
				p1 = p1->next;
			}
			else
			{
				p = NewHead = p2;
				p2 = p2->next;
			}
		}
		else
		{
			if (p1->val < p2->val)
			{
				NewHead->next = p1;
				NewHead = NewHead->next;
				p1 = p1->next;
			}
			else
			{
				NewHead->next = p2;
				NewHead = NewHead->next;
				p2 = p2->next;
			}
		}
	}
	if (p1 == nullptr)
	{
		NewHead->next = p2;
	}
	else
	{
		NewHead->next = p1;
	}
	return p;
}

int main()
{
	ListNode a(1), b(3), c(5), d(7);
	ListNode e(2), f(6), g(9), h(10);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	Merge(&a, &e);
	return 0;
}