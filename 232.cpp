#include <cstdio>
#include <stack>
using namespace std;
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        if (s.empty())
            frontEle = x;
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> temp;
        while (!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        temp.pop();
        if (!temp.empty())
            frontEle = temp.top();
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        return frontEle;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
private:
    stack<int> s;
    int frontEle;
};
int main() {
    Queue q;
    q.push(1);
    q.push(2);
    printf("%d\n", q.peek());
    q.pop();
    printf("%d\n", q.peek());
    q.pop();
    //if (q.empty()) {
        printf("fuck\n");
    //}
    return 0;
}
