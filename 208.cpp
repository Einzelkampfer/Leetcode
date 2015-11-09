#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
    	end = false;
        for (int i = 0; i < 26; ++i)
        	childs[i] = NULL;
    }
    TrieNode *childs[26];
    bool end;
};

class Trie {
	
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void printnode(TrieNode *node) {
    	for (int i = 0; i < 26; ++i) {
    		if (node -> childs[i] != NULL) {
    			printf("%c\n", i + 'a');
    			printnode(node -> childs[i]);
    		}
    	}
    }
    void print() {
    	printnode(root);
    }
    void insert(string word) {
        int l = word.size();
        TrieNode *temp = root;
        for (int i = 0; i < l; ++i) {
        	if (temp -> childs[word[i] - 'a'] == NULL) {
        		TrieNode *nextNode = new TrieNode();
        		temp -> childs[word[i] - 'a'] = nextNode;
        	}
        	temp = temp -> childs[word[i] - 'a'];
        }
        temp -> end = true;
    }
    bool search(string word) {
        int l = word.size();
        TrieNode *temp = root;
        for (int i = 0; i < l; ++i) {
        	if (temp -> childs[word[i] - 'a'] == NULL) {
        		return false;
        	}
        	temp = temp -> childs[word[i] - 'a'];
    	}
    	return temp -> end;
    }
    bool startsWith(string prefix) {
    	int l = prefix.size();
        TrieNode *temp = root;
        for (int i = 0; i < l; ++i) {
        	if (temp -> childs[prefix[i] - 'a'] == NULL) {
        		return false;
        	}
        	temp = temp -> childs[prefix[i] - 'a'];
    	}
        return true;
    }
};


int main() {
	Trie tree;
	tree.insert("abc");
	if (tree.search("ab")) {
		printf("hi");
	}
	return 0;
}

