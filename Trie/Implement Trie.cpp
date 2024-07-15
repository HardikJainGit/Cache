#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26]; //each node can have 26 children
        bool isTerminal; //search eg : TIME present => TIM present (not necessary) -> make E terminal

        TrieNode(char ch) 
        {
            this->data = ch;
            this->isTerminal = false; //Initialise bool as F

            for(int i=0; i<26; i++) 
            {
                this->children[i] = NULL;
            }
        }
};

class Trie {
public:
    TrieNode* root;

    Trie() 
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* &root, string word) 
    {
        //base case
        if(word.length() == 0) 
        {
            root->isTerminal = true; //mark terminal node's bool as true
            return;
        }

        // Assumption : Word will be in small
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) 
        {
            // Character Present
            child = root->children[index];
        } 
        else 
        {
            // Character Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1)); //start from index 1 onwards
    }

    void insert(string word) 
    {
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root, string word) 
    {
        // Base case
        if(word.length() == 0) 
        {
            return root->isTerminal; 
        } 

        // Finding index through mapping
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) 
        {
            // Present
            child = root->children[index];
        } 
        else 
        {
            // Absent
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word) 
    {
        return searchUtil(root,word);
    }

    bool startsutil(TrieNode* root, string word) 
    {
        // Base case
        if(word.length() == 0) {
            return true; 
        } 

        // Finding index through mapping
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) 
        {
            // Present
            child = root->children[index];
        } 
        else
        {
            // Absent
            return false;
        }

        return startsutil(child, word.substr(1));
    }   

    bool startsWith(string prefix) 
    {
        return startsutil(root,prefix);
    }
};
