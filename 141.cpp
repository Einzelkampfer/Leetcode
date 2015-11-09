#include <cstdio>
#include <vector>
using namespace std;
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode*> levelQueue;
        vector<TreeLinkNode*> nextLevel;
        TreeLinkNode *temp = root;
        levelQueue.push_back(temp);
        while (true) {
        	if (levelQueue[0] == NULL)
        		break;
        	vector<TreeLinkNode*>::iterator it;
        	for (it = levelQueue.begin(); it != levelQueue.end(); ++it) {
        		printf("%d", (*it) -> val);
        		nextLevel.push_back((*it) -> left);
        		nextLevel.push_back((*it) -> right);
        		if (it + 1 != levelQueue.end())
	        		(*it) -> next = *it + 1;
	        	else
	        		(*it) -> next = NULL;
        	}
        	printf("\n");
        	levelQueue.clear();
        	for (it = nextLevel.begin(); it != nextLevel.end(); ++it)
        		levelQueue.push_back(*it);
        	nextLevel.clear();
        }
    }
};
int main() {
	TreeLinkNode *t1 = new TreeLinkNode(1);
	TreeLinkNode *t2 = new TreeLinkNode(2);
	TreeLinkNode *t3 = new TreeLinkNode(3);
	TreeLinkNode *t4 = new TreeLinkNode(4);
	TreeLinkNode *t5 = new TreeLinkNode(5);
	TreeLinkNode *t6 = new TreeLinkNode(6);
	TreeLinkNode *t7 = new TreeLinkNode(7);
	t1 -> left = t2;
	t1 -> right = t3;
	
	Solution s;
	s.connect(t1);
}
