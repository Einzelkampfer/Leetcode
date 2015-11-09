#include <string>
#include <map>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> charMap;
        map<string, char> stringMap;
        int l = pattern.size();
        vector<string> words = split(str);
        if (words.size() != l)
            return false;
        int charCount = 0;
        for (int i = 0; i < l; ++i) {
            map<char, string>::iterator it1 = charMap.find(pattern[i]);
            map<string, char>::iterator it2 = stringMap.find(words[i]);
            if (it1 == charMap.end() && it2 == stringMap.end()) {
                charMap[pattern[i]] = words[i];
                stringMap[words[i]] = pattern[i];
            } else if (it1 != charMap.end() && it2 != stringMap.end()) {
                if (charMap[pattern[i]] != words[i] || stringMap[words[i]] != pattern[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
    vector<string> split(string str) {
        int l = str.size();
        int i = 0;
        int j = 0;
        vector<string> result;
        while (i < l) {
            while (j < l && str[j] != ' ')
                ++j;
            string word = str.substr(i, j - i);
            result.push_back(word);
            i = j + 1;
            j = i;
        }
        return result;
    }
};
int main() {
    string str = "fuck shitt fuck shit shit";
    Solution s;
    if (s.wordPattern("acabb", str))
        printf("fuck\n");
    return 0;
}
