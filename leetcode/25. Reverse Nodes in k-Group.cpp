#include<iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 class Solution {
 public:
	 ListNode* reverseKGroup(ListNode* head, int k) {
		 if (!hasKNodes(head, k)) return head;
		 ListNode* new_head = new ListNode(0);
		 new_head->next = head;
		 ListNode* pre = new_head;
		 ListNode* cur = head;
		 while (hasKNodes(cur, k)) {
			 for (int i = 0; i < k - 1; i++) {
				 ListNode* temp = pre->next;
				 pre->next = cur->next;
				 cur->next = cur->next->next;
				 pre->next->next = temp;
			 }
			 pre = cur;
			 cur = pre->next;
		 }
		 return new_head->next;
	 }
 private:
	 bool hasKNodes(ListNode* node, int k) {
		 int cnt = 0;
		 while (node) {
			 cnt++;
			 if (cnt >= k) return true;
			 node = node->next;
		 }
		 return false;
	 }
 };

 void show(ListNode *n)
 {
	 while (n!=nullptr)
	 {
		 cout << n->val << " ";
		 n = n->next;
	 }
 }

 int main()
 {
	 ListNode *head = new ListNode(1);
	 head->next = new ListNode(2);
	 head->next->next = new ListNode(3);
	 Solution s;
	 show(s.reverseKGroup(head,3));
	 system("pause");
 }