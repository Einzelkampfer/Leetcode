#include <cctype>
#include <cstdio>
#include <string>
#include <list>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int l = s.size();
        int i = 0;
        int j = l - 1;
        while (1) {
            while (i < l && !isalpha(s[i]) && !isdigit(s[i]))
                ++i;
            while (j >= 0 && !isalpha(s[j]) && !isdigit(s[j]))
                --j;
            if (i > j)
                break;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
int main() {
    Solution s;
    if (s.isPalindrome("1a2"))
        printf("fuck\n");
    return 0;
}

