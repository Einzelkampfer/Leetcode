#include <cstdio>
#include <string>
#include <cstring>
#define MAX 26
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int counter[MAX];
        memset(counter, 0, sizeof(counter));
        int l = s.size();
        for (int i = 0; i < l; ++i) {
            counter[s[i] - 'a']++;
        }
        l = t.size();
        for (int i = 0; i < l; ++i) {
            counter[t[i] - 'a']--;
        }
        for (int i = 0; i < MAX; ++i) {
            if (counter[i] != 0)
                return false;
        }
        return true;
    }
};
int main() {
    string st = "anagram";
    string t = "nagbram";
    Solution s;
    if (s.isAnagram(st, t)) {
        printf("fuck");
    }
    return 0;

}
