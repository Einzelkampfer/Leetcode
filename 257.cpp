#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<TreeNode*> temp;
        if (root == NULL)
            return result;
        temp.push_back(root);
        traverse(root, result, temp);
        return result;
    }
    void traverse(TreeNode *node, vector<string>& result, vector<TreeNode*>& temp) {
        if (node -> left != NULL) {
            temp.push_back(node -> left);
            traverse(node -> left, result, temp);
            temp.pop_back();
        }
        if (node -> right != NULL) {
            temp.push_back(node -> right);
            traverse(node -> right, result, temp);
            temp.pop_back();
        }
        if (node -> left == NULL && node -> right == NULL) {
            string str = "";
            int l = temp.size();
            for (int i = 0; i < l; ++i) {
                stringstream ss;
                string s;
                ss << (temp[i] -> val);
                ss >> s;
                str += s;
                if (i != l - 1)
                    str += "->";
            }
            //cout << str << "\n";
            result.push_back(str);
        }
    }
};
int main() {
    TreeNode *tree[10];
    for (int i = 1; i < 10; ++i) {
        tree[i] = new TreeNode(i);
    }
    tree[1] -> left = tree[2];
    tree[1] -> right = tree[3];
    tree[2] -> right = tree[5];
    Solution s;
    s.binaryTreePaths(tree[1]);
    return 0;
}
