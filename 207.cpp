#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
struct edge {
    int pointTo;
    edge(int point) {
        pointTo = point;
    }
};
struct graphNode{
    vector<edge> outTo;
    int inDegree;
    bool taken;
    graphNode() {
        taken = false;
        inDegree = 0;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<graphNode> graph;
        for (int i = 0; i < numCourses; ++i) {
            graphNode temp;
            graph.push_back(temp);
        }
        for (vector<pair<int, int> >::iterator i = prerequisites.begin(); i != prerequisites.end(); ++i) {
            graph[i -> second].inDegree++;
            edge e(i -> second);
            graph[i -> first].outTo.push_back(e);
        }
        int remainNode = numCourses;
        while (1) {
            vector<graphNode>::iterator it;
            bool canTake = false;
            for (it = graph.begin(); it != graph.end(); ++it) {
                if (!(it -> taken) && it -> inDegree == 0) {
                    it -> taken = true;
                    canTake = true;
                    vector<edge>::iterator eit;
                    for (eit = (it -> outTo).begin(); eit != it -> outTo.end(); ++eit) {
                        graph[eit -> pointTo].inDegree--;
                    }
                    remainNode--;
                }
            }
            if (!canTake) {
                return false;
            }
            if (remainNode == 0)
                return true;
        }
    }
};
int main() {
    Solution s;
    int numCourses = 2;
    vector<pair<int, int> > prerequisites;
    pair<int, int> p1(1, 0);
    pair<int, int> p2(0, 1);
    //prerequisites.push_back(p1);
    //prerequisites.push_back(p2);
    if (s.canFinish(numCourses, prerequisites)) {
        printf("fuck\n");
    }
    return 0;
}
