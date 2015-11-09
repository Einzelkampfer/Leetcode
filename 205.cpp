#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> alphabet1, alphabet2;
        map<int, vector<int> > pos1, pos2;
        int l = s.size();
        int charNum1 = 0;
        int charNum2 = 0;
        for (int i = 0; i < l; ++i) {
            map<char, int>::iterator it = alphabet1.find(s[i]);
            if (it == alphabet1.end()) {
                alphabet1.insert(pair<char, int>(s[i], charNum1));
                vector<int> temp;
                temp.push_back(i);
                pos1.insert(pair<int, vector<int> >(charNum1, temp));
                charNum1++;
            } else {
                int code = it -> second;
                pos1[code].push_back(i);
            }
        }
        l = t.size();
        for (int i = 0; i < l; ++i) {
            map<char, int>::iterator it = alphabet2.find(t[i]);
            if (it == alphabet2.end()) {
                alphabet2.insert(pair<char, int>(t[i], charNum2));
                vector<int> temp;
                temp.push_back(i);
                pos2.insert(pair<int, vector<int> >(charNum2, temp));
                charNum2++;
            } else {
                int code = it -> second;
                pos2[code].push_back(i);
            }
        }
        if (charNum1 != charNum2)
            return false;
        for (int i = 0; i < charNum1; ++i) {
            if (pos1[i].size() != pos2[i].size())
                return false;
            l = pos1[i].size();
            for (int j = 0; j < l; ++j) {
                if (pos1[i][j] != pos2[i][j])
                    return false;
            }
        }
        return true;
    }
};
int main() {
    Solution s;
    if (s.isIsomorphic("paper", "title")) {
        printf("fuck\n");
    }
    return 0;
}

