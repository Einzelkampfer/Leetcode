#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        int result = 0;
        for (int i = 0; i < l; ++i) {
        	if (result >= l - i)
        		break;
        	bool repeated = false;
        	int locallongest;
        	for (int j = i; j < l; ++j) {
        		int record[128];
        		memset(record, 0, 128 * sizeof(int));
        		for (int k = i; k <= j; ++k) {
        			if (record[s[k]] == 0) {
        				record[s[k]] = 1;
        			} else {
        				repeated = true;
        				break;
        			}
        		}
        		if (repeated) {
        			break;
        		} else {
        			locallongest = (j - i) + 1;
        		}
        	}
        	if (locallongest > result) {
        		result = locallongest;
        	}
        }
        return result;
    }
};
int main() {
	Solution s;
	printf("%d\n", s.lengthOfLongestSubstring("abcdefghijk"));
	return 0;
}

