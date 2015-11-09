#include <cstdio>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *result = NULL;
        ListNode *temp;
        int first;
        while (1) {
        	if (t1 == NULL || t2 == NULL) {
        		break;
        	}
        	ListNode *newNode;
        	if (t1 -> val > t2 -> val) {
        		newNode = new ListNode(t2 -> val);
        		t2 = t2 -> next;
        	} else {
        		newNode = new ListNode(t1 -> val);
        		t1 = t1 -> next;
        	}
        	if (first) {
        		result = newNode;
        		temp = result;
        		first = false;
        	} else {
        		temp -> next = newNode;
        		temp = temp -> next;
        	}
        }
        if (t1 != NULL) {
        	while (t1 != NULL) {
        		ListNode *newNode = new ListNode(t1 -> val);
        		if (first) {
        			result = newNode;
	        		temp = result;
	        		first = false;
        		} else {
        			temp -> next = newNode;
	        		temp = temp -> next;
        		}
        		t1 = t1 -> next;
        	}
        }
        if (t2 != NULL) {
        	while (t2 != NULL) {
        		ListNode *newNode = new ListNode(t2 -> val);
        		if (first) {
        			result = newNode;
	        		temp = result;
	        		first = false;
        		} else {
        			temp -> next = newNode;
	        		temp = temp -> next;	
        		}
        		t2 = t2 -> next;
        	}
        }
        return result;
    }
};
int main() {
	ListNode *l1 = NULL;
	ListNode *l2 = new ListNode(0);
	Solution s;
	ListNode *l = s.mergeTwoLists(l1, l2);
	
	return 0;
}
