#include <cstdio>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *t1 = head, *t2 = head;
        while (n--)
        	t2 = t2 -> next;
        ListNode *temp;
        if (t2 == NULL) {
        	temp = head;
        	head = head -> next;
        } else {
        	while (t2 -> next != NULL) {
	        	t1 = t1 -> next;
	        	t2 = t2 -> next;
	        }
	        temp = t1 -> next;
	        t1 -> next = temp -> next;
        }
        delete(temp);
        return head;
    }
};
int main() {
	ListNode *list[5];
	for (int i = 0; i < 5; ++i)
		list[i] = new ListNode(i + 1);
	for (int i = 0; i < 4; ++i)
		list[i] -> next = list[i + 1];
	Solution s;
	list[0] = s.removeNthFromEnd(list[0], 5);
	ListNode *temp = list[0];
	int count = 0;
	while (temp != NULL) {
		if (count <= 10)
			printf("%d->", temp -> val);
		temp = temp -> next;
		count++;
	}
	return 0;
}
