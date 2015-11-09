#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int i = 1;
        while (i < n) {
            string temp = "";
            int l = s.size();
            int j = 0;
            int k = j;
            while (j < l) {
                while (k < l && s[k] == s[j])
                    ++k;
                int partLen = k - j;
                stringstream ss;
                string lenstr;
                ss << partLen;
                ss >> lenstr;
                temp += lenstr;
                temp += s[j];
                j = k;
            }
            //cout << temp << "\n";
            s = temp;
            ++i;
        }
        return s;
    }
};
int main() {
    Solution s;
    cout << s.countAndSay(2) << "\n";
    return 0;
}

