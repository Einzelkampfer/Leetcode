#include <cstdio>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *t1 = head;
        ListNode *t2 = head;
        while (t2 != NULL) {
        	printf("%d %d\n", t1 -> val, t2 -> val);
        	if (t2 -> val == val) {
        		if (t2 == head) {
        			head = head -> next;
        			t1 = head;
        			delete t2;
        			t2 = t1;
        		} else {
        			t1 -> next = t2 -> next;
        			delete t2;
        			t2 = t1 -> next;
        		}
        	} else {
        		if (t2 != head)
	        		t1 = t1 -> next;
        		t2 = t2 -> next;
        	}
        }
        return head;
    }
};
void printList(ListNode *node) {
	if (node != NULL) {
		printf("%d->", node -> val);
		printList(node -> next);
	}	
}
int main() {
	ListNode *list[10];
	int a[10] = {1,1,1,6,1,1,1};
	for (int i = 0; i < 7; ++i) {
		list[i] = new ListNode(a[i]);
	}
	for (int i = 0; i < 6; ++i) {
		list[i] -> next = list[i + 1];
	}
	printList(list[0]);
	printf("\n\n");
	Solution s;
	list[0] = s.removeElements(list[0], 1);
	printList(list[0]);
	return 0;
}
