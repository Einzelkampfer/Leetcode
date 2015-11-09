#include <queue>
#include <cstdio>
using namespace std;
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        topEle = x;
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int s = q.size() - 1;
        queue<int> temp;
        while (s--) {
            temp.push(q.front());
            topEle = q.front();
            q.pop();
        }
        q.pop();
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
    }

    // Get the top element.
    int top() {
        return topEle;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
    int topEle;
};
int main() {
    Stack s;
    s.push(1);
    printf("%d\n", s.top());
    s.push(2);
    printf("%d\n", s.top());
    s.pop();
    printf("%d\n", s.top());
    s.pop();
    if (s.empty()) {
        printf("fuck\n");
    }
    return 0;
}
