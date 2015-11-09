#include <cstdio>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSame(TreeNode *leftp, TreeNode *rightp) {
		if (leftp == NULL && rightp == NULL)
			return true;
		if (leftp != NULL && rightp != NULL) {
			return (leftp -> val == rightp -> val);
		}
		return false;
	}
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
        	return true;
        }
        return compareLeftRight(root -> left, root -> right);
    }
    bool compareLeftRight(TreeNode *leftp, TreeNode *rightp) {
    	if (!isSame(leftp, rightp))
    		return false;
    	if (leftp != NULL && rightp != NULL) {
    		printf("%d %d\n", leftp -> val, rightp -> val);
    		bool b1 = compareLeftRight(leftp -> left, rightp -> right);
    		bool b2 = compareLeftRight(leftp -> right, rightp -> left);
    		return (b1 && b2);
    	}
    	return true;
    }
};
int main() {
	TreeNode *tree[10];
	int a[10] = {1,2,2,3,4,4,3};
	for (int i = 0; i < 7; ++i)
		tree[i] = new TreeNode(a[i]);
	tree[0] -> left = tree[1];
	tree[0] -> right = tree[2];
	tree[1] -> left = tree[3];
	//tree[1] -> right = tree[4];
	tree[2] -> left = tree[5];
	tree[2] -> right = tree[6];
	Solution s;
	if (s.isSymmetric(tree[0]))
		printf("fuck\n");
	return 0;
}
	
