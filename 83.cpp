#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *t1, *t2;
        t1 = head;
        while (t1 != NULL) {
            t2 = t1;
            while (t2 != NULL && t2 -> val == t1 -> val) {
                t2 = t2 -> next;
            }
            if (t2 != t1 -> next) {
                ListNode *dTemp = t1 -> next;
                while (dTemp != t2) {
                    ListNode *temp = dTemp -> next;
                    delete(dTemp);
                    dTemp = temp;
                }
                t1 -> next = t2;
            }
            t1 = t1 -> next;
        }
        return head;
    }
};
int main() {
    ListNode *l[10];
    int a[10] = {1};
    for (int i = 0; i < 1; ++i) {
        l[i] = new ListNode(a[i]);
    }
    for (int i = 0; i < 0; ++i) {
        l[i] -> next = l[i + 1];
    }
    ListNode *temp = l[0];
    while (temp != NULL) {
        printf("%d ", temp -> val);
        temp = temp -> next;
    }
    printf("\n");
    Solution s;
    l[0] = s.deleteDuplicates(l[0]);
    temp = l[0];
    while (temp != NULL) {
        printf("%d ", temp -> val);
        temp = temp -> next;
    }
    printf("\n");
    return 0;
}
