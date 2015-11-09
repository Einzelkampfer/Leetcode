#include <cstdio>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invertNode(root);
        return root;
    }
    void invertNode(TreeNode *node) {
    	if (node == NULL)
    		return;
    	TreeNode* temp = node -> left;
    	node -> left = node -> right;
    	node -> right = temp;
    	if (node -> left != NULL)
    		invertNode(node -> left);
    	if (node -> right != NULL)
    		invertNode(node -> right);
    }
};
int main() {
	Tree
	 return 0;
}
