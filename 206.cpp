#include <cstdio>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
        	ListNode *temp2 = temp -> next;
        	if (newHead == NULL) {
        		temp -> next = NULL;
        	} else {
        		temp -> next = newHead;
        	}
        	newHead = temp;
        	temp = temp2;
        }
        return newHead;
    }
};
void printList(ListNode* node) {
	if (node != NULL) {
		printf("%d->", node -> val);
		
		printList(node -> next);
	}
}
int main() {
	ListNode *list[10];
	for (int i = 0; i < 10; ++i)
		list[i] = new ListNode(i);
	for (int i = 0; i < 9; ++i)
		list[i] -> next = list[i + 1];
	printList(list[0]);
	printf("\n");
	Solution s;
	ListNode* newList = s.reverseList(list[0]);
	printList(newList);
	return 0;
}

