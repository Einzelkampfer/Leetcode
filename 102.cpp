#include <cstdio>
#include <vector>
#include <list>
using namespace std;
struct TreeNode {
int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        list<vector<TreeNode*> > v;
        vector<vector<int> > result;
        if (root == NULL)
        	return result;
        vector<TreeNode*> l1;
        l1.push_back(root);
        v.push_back(l1);
        while (1) {
        	vector<TreeNode*>& level = v.back();
        	int l = level.size();
        	vector<TreeNode*> nextLevel;
        	for (int i = 0; i < l; ++i) {
        		if (level[i] -> left != NULL)
        			nextLevel.push_back(level[i] -> left);
        		if (level[i] -> right != NULL)
        			nextLevel.push_back(level[i] -> right);
        	}
        	if (nextLevel.empty())
        		break;
        	v.push_back(nextLevel);
        }
        while (!v.empty()) {
        	vector<TreeNode*>& level = v.front();
        	int l = level.size();
        	vector<int> levelVal;
        	for (int i = 0; i < l; ++i) {
        		levelVal.push_back(level[i] -> val);
        	}
        	result.push_back(levelVal);
        	v.pop_front();
        }
        return result;
    }
};
int main() {
	TreeNode *tree[5];
	tree[0] = new TreeNode(3);
	tree[1] = new TreeNode(9);
	tree[2] = new TreeNode(20);
	tree[3] = new TreeNode(15);
	tree[4] = new TreeNode(7);
	tree[0] -> left = tree[1];
	tree[0] -> right = tree[2];
	tree[2] -> left = tree[3];
	tree[2] -> right = tree[4];
	Solution s;
	vector<vector<int> > result = s.levelOrder(tree[0]);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
