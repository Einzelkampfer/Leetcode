#include <stack>
#include <cstdio>
using namespace std;
class MinStack {
public:
    void push(int x) {
        s.push(x);
        if (!minS.empty()) {
        	if (minS.top() >= x) {
        		minS.push(x);
        	}
        } else {
        	minS.push(x);
        }
    }

    void pop() {
    	if (minS.top() == s.top())
    		minS.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
private:
	stack<int> minS;
	stack<int> s;
};
int main() {
	MinStack s;
	s.push(1);
	s.push(3);
	printf("%d %d\n", s.top(), s.getMin());
	s.pop();
	s.pop();
	s.push(10);
	s.push(5);
	s.push(1);
	s.push(8);
	s.push(1);
	printf("%d %d\n", s.top(), s.getMin());
	s.pop();
	printf("%d %d\n", s.top(), s.getMin());
	s.pop();
	printf("%d %d\n", s.top(), s.getMin());
	s.pop();
	printf("%d %d\n", s.top(), s.getMin());
	s.pop();
	printf("%d %d\n", s.top(), s.getMin());
	s.pop();
	return 0;
}
