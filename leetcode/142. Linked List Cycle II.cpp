#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		bool isCycle = false;
		ListNode *tortoise = head;
		ListNode *hare = head;
		if (head != nullptr && head->next != nullptr)
		{
			while (hare->next != nullptr&&hare->next->next != nullptr)
			{
				tortoise = tortoise->next;
				hare = hare->next->next;
				if (hare == tortoise)
				{
					isCycle = true;
					break;
				}
			}
		}
		if (!isCycle)
			return nullptr;
		else
		{
			hare = head;
			while (hare != tortoise)
			{
				hare = hare->next;
				tortoise = tortoise->next;
			}
			return hare;
		}
	}
};

void show(ListNode *n)
{
	if (!n)
		cout << "no cycle!";
	else
		cout << "cycle!";
}

int main()
{
	ListNode *n = nullptr;
	Solution s;
	show(s.detectCycle(n));
	system("pause");
}