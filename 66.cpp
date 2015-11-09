#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n - 1]++;
        int carry = 0;
        for (int i = n - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            if (carry == 0)
                break;
            digits[i] %= 10;
        }
        if (carry != 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
int main() {
    int a[10] = {9, 9, 9};
    vector<int> v(a, a + 1);
    for (int i = 0; i < v.size(); ++i) {
        printf("%d", v[i]);
    }
    printf("\n");
    Solution s;
    vector<int> a1 = s.plusOne(v);
    for (int i = 0; i < a1.size(); ++i) {
        printf("%d", a1[i]);
    }
    printf("\n");
    return 0;
}
