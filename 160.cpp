#include <cstdio>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp1 = headA;
        while (tmp1 != NULL) {
        	ListNode *tmp2 = headB;
        	while (tmp2 != NULL) {
        		printf("%d %d\n", tmp1 -> val, tmp2 -> val);
        		if (tmp1 == tmp2) {
        			return tmp1;
        		}
        		tmp2 = tmp2 -> next;
        	}
        	tmp1 = tmp1 -> next;
        }
        return NULL;
    }
};
int main() {
	ListNode *list[10];
	for (int i = 0; i < 8; ++i) {
		list[i] = new ListNode(i);
	}
	list[0] -> next = list[1];
	list[1] -> next = list[2];
	list[3] -> next = list[4];
	list[4] -> next = list[5];
	list[5] -> next = list[2];
	list[2] -> next = list[6];
	list[6] -> next = list[7];
	Solution s;
	ListNode *inter = s.getIntersectionNode(list[0], list[3]);
	printf("%d\n", inter -> val);
	return 0;
}
