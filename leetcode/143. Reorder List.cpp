#include<iostream>
#include<map>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next)
			return;

		int count = 1;
		map<ListNode*, ListNode*> pre_map;
		pre_map[head] = nullptr;
		ListNode *n = head;
		while (n->next != nullptr)
		{
			pre_map[n->next] = n;
			n = n->next;
			count++;
		}
		ListNode *cur_inser = n, *next_inser = pre_map[n], *p = head;
		while (count>2)
		{
			count -= 2;
			next_inser->next = nullptr;
			cur_inser->next = p->next;
			p->next = cur_inser;
			p = cur_inser->next;

			cur_inser = next_inser;
			next_inser = pre_map[next_inser];
		}
	}
};