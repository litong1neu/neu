#include<iostream>
#include<vector>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };


class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode result(INT_MIN);
		while (head)
		{
			ListNode* p = &result;
			while (p->next&&p->next->val < head->val)
				p = p->next;

			ListNode* temp = head->next;
			head->next = p->next;
			p->next = head;
			head = temp;
		}

		return result.next;
	}
};

ListNode* createL(vector<int> &v)
{
	ListNode* head = new ListNode(0), *p = head;
	for (int i = 0; i < v.size(); i++)
	{
		p->next = new ListNode(v[i]);
		p = p->next;
	}
	return head->next;
}

int main()
{
	vector<int> v{ 5, 7, 3, 6, 8 };
	ListNode *head = createL(v);
	Solution s;
	ListNode *result=s.insertionSortList(head);
	while (result)
	{
		cout << result->val<<" ";
		result = result->next;
	}

	system("pause");
}