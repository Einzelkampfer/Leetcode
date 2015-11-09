#include <cstdio>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        return canSumTo(root, sum, 0);
    }
    bool canSumTo(TreeNode *node, int sum, int sumNow) {
        sumNow += node -> val;
        //printf("+%d\n", node -> val);
        if (node -> left == NULL && node -> right == NULL) {
            //printf("to leaf %d, sum is %d\n", node -> val, sumNow);
            return (sumNow == sum);
        }
        bool leftCan = false;
        bool rightCan = false;
        if (node -> left != NULL) {
            leftCan = canSumTo(node -> left, sum, sumNow);
        }
        if (leftCan)
            return true;
        if (node -> right != NULL) {
            rightCan = canSumTo(node -> right, sum, sumNow);
        }
        return rightCan;
    }
};
int main() {
    int a[10] = {5,4,8,11,13,4,7,2,1};
    TreeNode *tree[10];
    for (int i = 0; i < 9; ++i) {
        tree[i] = new TreeNode(a[i]);
    }
    tree[0] -> left = tree[1];
    tree[0] -> right = tree[2];
    tree[1] -> left = tree[3];
    tree[2] -> left = tree[4];
    tree[2] -> right = tree[5];
    tree[3] -> left = tree[6];
    tree[3] -> right = tree[7];
    tree[5] -> right = tree[8];
    Solution s;
    if (s.hasPathSum(tree[0], 26))
        printf("fuck\n");
    return 0;
}
