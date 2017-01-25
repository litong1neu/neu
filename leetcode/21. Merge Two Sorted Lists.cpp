#include<iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode head(0), *p = &head;
		if (l1 == nullptr&&l2 == nullptr)
			return nullptr;	
		while (l1 != nullptr&&l2 != nullptr)
		{			
			if (l1->val < l2->val)
			{
				p->next=l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		while(l1 != nullptr)
		{
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}
		while (l2 != nullptr)
		{
			p->next =l2;
			p = p->next;
			l2 = l2->next;
		}
		return head.next;
	}
};

void show(ListNode* p)
{
	while (p != nullptr)
	{
		cout << p->val;
		p = p->next;
	}
}

int main()
{
	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(2);
	l2->next->next = new ListNode(4);
	Solution s;
	//s.mergeTwoLists(nullptr, l2);
	show(s.mergeTwoLists(nullptr, l2));
	system("pause");
}