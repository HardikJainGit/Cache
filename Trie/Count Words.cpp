#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26]; // Each node can have 26 children
    bool isTerminal; // Marks the end of a word
    int wordCount; // Counts occurrences of the word ending at this node

    TrieNode(char ch) {
        this->data = ch;
        this->isTerminal = false; // Initialize isTerminal as false
        this->wordCount = 0; // Initialize word count as 0

        for(int i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); // Root is initialized with null character
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case
        if(word.length() == 0) {
            root->isTerminal = true; // Mark the terminal node
            root->wordCount += 1; // Increment word count
            return;
        }

        // Assumption: Word is in lowercase
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != nullptr) {
            // Character present
            child = root->children[index];
        } else {
            // Character absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1)); // Process the next character
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    void searchUtil(TrieNode* root, string word, int &c) {
        // Base case
        if(word.length() == 0) {
            if(root->isTerminal) {
                c = root->wordCount;
            }
            return;
        }

        // Finding index through mapping
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != nullptr) {
            // Present
            child = root->children[index];
        } else {
            // Absent
            return;
        }

        searchUtil(child, word.substr(1), c);
    }

    int countWordsEqualTo(string &word) {
        int c = 0;
        searchUtil(root, word, c);
        return c;
    }

    void pr_count(TrieNode* root, string word, int &d) {
        // Base case

        // Reach till the end of the prefix and then return count of all words of that prefix

        if(word.length() == 0) {
            if (root->isTerminal) {
                d += root->wordCount;
            }
            for(int i = 0; i < 26; i++) {
                if(root->children[i] != nullptr) {
                    pr_count(root->children[i], word, d);
                }
            }
            return;
        } 

        // Finding index through mapping
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != nullptr) {
            // Present
            child = root->children[index];
        } else {
            // Absent
            return;
        }

        pr_count(child, word.substr(1), d);
    }

    int countWordsStartingWith(string &word) {
        int d = 0;
        pr_count(root, word, d);
        return d;
    }

    void eraseUtil(TrieNode* root, string word) {
        // Base case
        if(word.length() == 0) {
            if(root->isTerminal) {
                root->wordCount -= 1; // Decrement word count
                if(root->wordCount == 0) {
                    root->isTerminal = false;
                }
            }
            return;
        }

        // Finding index through mapping
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != nullptr) {
            // Present
            child = root->children[index];
        } else {
            // Absent
            return;
        }

        eraseUtil(child, word.substr(1));

        // Clean up the node if it's no longer needed
        
        bool hasChildren = false;
        for(int i = 0; i < 26; i++) {
            if(root->children[i] != nullptr) {
                hasChildren = true;
                break;
            }
        }
        // no children, not a terminal node and not the root node
        if(!hasChildren && !root->isTerminal && root->data != '\0') {
            delete root;
            root = nullptr;
        }
    }

    void erase(string &word) {
        eraseUtil(root, word);
    }
};
