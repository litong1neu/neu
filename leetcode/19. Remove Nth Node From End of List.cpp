#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode **t1 = &head, *t2 = head;
		for (int i = 1; i <= n; i++)
			t2 = t2->next;
		while (t2)
		{
			t1 = &((*t1)->next);
			t2 = t2->next;
		}
		ListNode *tmp = *t1;
		*t1 = (*t1)->next;
		delete(tmp); // delete it here
		return head;
	}
	ListNode* removeNthFromEnd2(ListNode* head, int n) {
		ListNode *t1 = head, *t2 = head;
		ListNode *new1 = new ListNode(0);
		new1->next = head;
		ListNode *p = new1;
		for (int i = 1; i <= n; i++)
			t2 = t2->next;
		while (t2!=nullptr)
		{
			t1 = t1->next;
			t2 = t2->next;
			p = p->next;
		}
		p->next = t1->next;
		delete t1;
		return new1->next;
	}
};

void show(ListNode *p)
{
	if (p == nullptr)
	{
		cout << "tail";
		return;
	}
	else
	{
		cout << p->val << " ";
		show(p->next);
	}
}

int main()
{
	ListNode* t=new ListNode(1);
//	t->next = new ListNode(2);
//	t->next->next = new ListNode(3);
//	show(t);
	
	Solution s;
	show(s.removeNthFromEnd2(t, 1));
	
	system("pause");

}