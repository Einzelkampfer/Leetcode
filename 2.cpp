#include <cstdio>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result, *cur;
        int carry = 0;
        bool first = true;
        ListNode *p1 = l1, *p2 = l2;
        while (1) {
        	if (p1 == NULL && p2 == NULL && carry == 0)
        		break;
        	int v1 = (p1 == NULL) ? 0 : (p1 -> val);
        	int v2 = (p2 == NULL) ? 0 : (p2 -> val);
        	int sum = v1 + v2 + carry;
        	printf("%d %d :", v1, v2);
        	printf("%d\n", sum);
        	ListNode *temp = new ListNode(sum % 10);
        	carry = sum / 10;
        	if (first) {
        		result = temp;
        		cur = temp;
        		first = false;
        	} else {
        		cur -> next = temp;
        		cur = cur -> next;
        	}
        	if (p1 != NULL)
        		p1 = p1 -> next;
        	if (p2 != NULL)
        		p2 = p2 -> next;
        }
        return result;
    }
};

void print(ListNode *node) {
	if (node != NULL) {
		printf("%d ", node -> val);
		print(node -> next);
	}
}
int main() {
	Solution s;
	ListNode* l11 = new ListNode(2);
	ListNode* l12 = new ListNode(4);
	ListNode* l13 = new ListNode(3);
	ListNode* l14 = new ListNode(5);
	ListNode* l21 = new ListNode(5);
	ListNode* l22 = new ListNode(6);
	ListNode* l23 = new ListNode(4);
	l11 -> next = l12;
	l12 -> next = l13;
	l13 -> next = l14;
	l21 -> next = l22;
	l22 -> next = l23;
	print(s.addTwoNumbers(l11, l21));
	return 0;
}
