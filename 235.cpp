#include <cstdio>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ppath, qpath;
        bool pfind = false, qfind = false;
        traverse(root, p, q, ppath, qpath, pfind, qfind);
        /*for (int i = 0; i < ppath.size(); ++i) {
            printf("%d ", ppath[i] -> val);
        }
        printf("\n");
        for (int i = 0; i < qpath.size(); ++i) {
            printf("%d ", qpath[i] -> val);
        }
        printf("\n");*/
        int l = (ppath.size() > qpath.size()) ? qpath.size() : ppath.size();
        int i = 0;
        while (ppath[i] == qpath[i]) {
            ++i;
        }
        return ppath[i - 1];
    }
    void traverse(TreeNode *node, TreeNode *p, TreeNode *q, vector<TreeNode*> &ppath, vector<TreeNode*> &qpath, bool &pfind, bool &qfind) {
        if (pfind && qfind)
            return;
        //printf("look %d\n", node -> val);
        if (!pfind) {
            ppath.push_back(node);
        }
        if (!qfind) {
            qpath.push_back(node);
        }
        if (node == p) {
            //printf("find p\n");
            pfind = true;
        }
        if (node == q) {
            //printf("find q\n");
            qfind = true;
        }
        if (node -> left != NULL) {
            traverse(node -> left, p, q, ppath, qpath, pfind, qfind);
            if (!pfind) {
                ppath.pop_back();
            }
            if (!qfind) {
                qpath.pop_back();
            }
        }
        if (node -> right != NULL) {
            traverse(node -> right, p, q, ppath, qpath, pfind, qfind);
            if (!pfind) {
                ppath.pop_back();
            }
            if (!qfind) {
                qpath.pop_back();
            }
        }
    }
};#include <cstdio>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ppath, qpath;
        bool pfind = false, qfind = false;
        traverse(root, p, q, ppath, qpath, pfind, qfind);
        /*for (int i = 0; i < ppath.size(); ++i) {
            printf("%d ", ppath[i] -> val);
        }
        printf("\n");
        for (int i = 0; i < qpath.size(); ++i) {
            printf("%d ", qpath[i] -> val);
        }
        printf("\n");*/
        int l = (ppath.size() > qpath.size()) ? qpath.size() : ppath.size();
        int i = 0;
        while (ppath[i] == qpath[i]) {
            ++i;
        }
        return ppath[i - 1];
    }
    void traverse(TreeNode *node, TreeNode *p, TreeNode *q, vector<TreeNode*> &ppath, vector<TreeNode*> &qpath, bool &pfind, bool &qfind) {
        if (pfind && qfind)
            return;
        //printf("look %d\n", node -> val);
        if (!pfind) {
            ppath.push_back(node);
        }
        if (!qfind) {
            qpath.push_back(node);
        }
        if (node == p) {
            //printf("find p\n");
            pfind = true;
        }
        if (node == q) {
            //printf("find q\n");
            qfind = true;
        }
        if (node -> left != NULL) {
            traverse(node -> left, p, q, ppath, qpath, pfind, qfind);
            if (!pfind) {
                ppath.pop_back();
            }
            if (!qfind) {
                qpath.pop_back();
            }
        }
        if (node -> right != NULL) {
            traverse(node -> right, p, q, ppath, qpath, pfind, qfind);
            if (!pfind) {
                ppath.pop_back();
            }
            if (!qfind) {
                qpath.pop_back();
            }
        }
    }
};
int main() {
    TreeNode *tree[7];
    for (int i = 0; i < 7; ++i) {
        tree[i] = new TreeNode(i);
    }
    tree[5] -> left = tree[3];
    tree[5] -> right = tree[6];
    tree[3] -> left = tree[2];
    tree[3] -> right = tree[4];
    tree[2] -> left = tree[1];
    Solution s;
    TreeNode *result = s.lowestCommonAncestor(tree[5], tree[6], tree[1]);
    printf("%d\n", result -> val);
    return 0;
}
