#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
	 ListNode(int x) : val(x), next(nullptr) {}

	 friend ostream& operator<<(ostream& os, ListNode L)
	 {
		 ListNode* p = &L;		 
		 while (p!=nullptr)
		 {			 
			 
			 cout << p->val;
			  p= p->next;
		 }
		 return os;
	 }
 };


 class Solution {
 public:
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 if (l1 == nullptr)
			 return l2;
		 else if (l2 == nullptr)
			 return l1;
		 else
		 {
			 long long v1 = 0;
			 long long v2 = 0;
			 for (int i = 0; l1 != nullptr; i++)
			 {
				 v1 += l1->val*pow(10, i);
				 l1 = l1->next;
			 }
			 for (int i = 0; l2 != nullptr; i++)
			 {
				 v2 += l2->val*pow(10, i);
				 l2 = l2->next;
			 }
			 long long sum = v1 + v2;

			 ListNode head(0), *p = &head;
			 gen_list(sum, p);
			 return head.next;
		 }

	 }
 private:
	 void gen_list(long long n, ListNode* &p)
	 {
		 p = p->next = new ListNode(0);
		 int digit = n % 10;
		 p->val = digit;
		 while (1)
		 {
			 n /= 10;
			 if (n == 0)
				 break;
			 digit = n % 10;
			 p->next = new ListNode(0);
			 p = p->next;
			 p->val = digit;
		 }
	 }
 };

 class Solution2 {
 public:
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 if (l1 == nullptr)
			 return l2;
		 else if (l2 == nullptr)
			 return l1;
		 else
		 {
			 int carry = 0;
			 int val = 0;
			 ListNode head(0), *p = &head;
			 while (l1 != nullptr||l2 != nullptr)
			 {
				 val = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
				 carry = val / 10;
				 p->next = new ListNode(val % 10);
				 p = p->next;
				 if (l1 != nullptr)
					 l1 = l1->next;
				 if (l2 != nullptr)
					 l2 = l2->next;
			 }
			 if (carry == 1)
				 p->next = new ListNode(1);
			 return head.next;
		 }
	 }
 };
int main()
{
	ListNode *l1 = new ListNode(2);	
	ListNode* n1=l1->next = new ListNode(4);
	n1->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	ListNode* n2 = l2->next = new ListNode(6);
	n2->next = new ListNode(4);

	ListNode L1(1);
	L1.next = new ListNode(8);
	ListNode L2(0);
	Solution2 s;
	s.addTwoNumbers(&L1, &L2);
	//cout << L1;
	system("pause");
}