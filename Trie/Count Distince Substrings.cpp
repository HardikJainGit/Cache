#include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

class TrieNode {
    public:
        char data;
        TrieNode* children[26]; //each node can have 26 children
        bool isTerminal; //search eg : TIME present => TIM present (not necessary) -> make E terminal

        TrieNode(char ch) {
            this->data = ch;
            this->isTerminal = false; //Initialise bool as F

            for(int i=0; i<26; i++) {
                this->children[i] = NULL;
            }
        }
};

/* The complexity for a trie for insertion deletion and search is O(length of word)
Each character in the word corresponds to a node in the trie. So space complexity is O(length) */

class Trie {
    public :    
        TrieNode* root;

        Trie() 
        {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* &root, string word) {

            //base case
            if(word.length() == 0) {
                root->isTerminal = true; //mark terminal node's bool as true
                return;
            }

            // Assumption : Word will be in small
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL) {
                // Character Present
                child = root->children[index];
            } else {
                // Character Absent
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            // Recursion
            insertUtil(child, word.substr(1)); //start from index 1 onwards
        }

        void insertNode(string word) {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word) {
            // Base case
            if(word.length() == 0) {
                return root->isTerminal; //For prefix return true in this step
            } 

            // Finding index through mapping
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL) {
                // Present
                child = root->children[index];
            } else {
                // Absent
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

        bool search(string word) {
            return searchUtil(root, word);
        }

        void removeUtil(TrieNode* root, string word) {
            // Base case
            if(word.length() == 0) {
                if(root->isTerminal) {
                    // If the current node represents the end of a word,
                    // mark it as non-terminal (remove the word from the Trie)
                    root->isTerminal = false;
                }
                return;
            }

            // Finding index through mapping
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL) {
                // If the child node corresponding to the current character exists,
                // move to that child and continue the removal process
                child = root->children[index];
            } else {
                // If the child node doesn't exist, the word is not present in the Trie
                return;
            }

            // Recursively call removeUtil on the child node with the remaining characters of the word
            removeUtil(child, word.substr(1));
        
        }


        void remove(string word) {
            return removeUtil(root, word);
        }

        void eraseUtil(TrieNode* root, string word) {
            // Base case
            if(word.length() == 0) {
                if(root->isTerminal) {
                    root->isTerminal = false;
                    delete root;
                    return;
                } else {
                    return;
                }
            }

            // Finding index through mapping
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL) {
                // Present
                child = root->children[index];
            } else {
                // Absent
                return;
            }

            eraseUtil(child, word.substr(1));
            return;
        }

        void erase(string word) {
            return eraseUtil(root, word);
        }
        
};

int countDistinctSubstrings(string &s) 
{
    Trie trie;
    int count = 0;

    for(int i = 0; i < s.length(); i++) {
        string substring = "";
        for(int j = i; j < s.length(); j++) 
        {
            substring += s[j];
            if(!trie.search(substring)) 
            {
                trie.insertNode(substring);
                count++;
            }
        }
    }
    return count + 1;
}