#include <bits/stdc++.h> 
using namespace std;

// https://www.naukri.com/code360/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

bool pr_check(string s, unordered_map<string,int> m)
{
    string prefix = "";
    for (int i = 0; i < s.length(); i++)
    {
        prefix += s[i];
        if (!m[prefix])
        {
            return false;
        }
    }
    return true;
}
string completeString(int n, vector<string> &a){

    unordered_map<string,int> m;
    for(auto it : a)
    {
       m[it] = 1;
    }

    string longest = "";

    for(auto it : a)
    {
        if(pr_check(it,m))
        {
            if(it.length() > longest.length())
            {
                longest = it;
            }
            if(it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }
    return (longest.length()) ? longest : "None";
}

// Trie

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        this->isTerminal = false;

        for(int i=0; i<26; i++) {
            this->children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* &root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertNode(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            return root->isTerminal;
        } 

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            if(root->isTerminal) {
                root->isTerminal = false;
            }
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return;
        }

        removeUtil(child, word.substr(1));
    }

    void remove(string word) {
        removeUtil(root, word);
    }

    void eraseUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            if(root->isTerminal) {
                root->isTerminal = false;
                delete root;
                return;
            } else {
                return;
            }
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return;
        }

        eraseUtil(child, word.substr(1));
        return;
    }

    void erase(string word) {
        eraseUtil(root, word);
    }
    
    bool pr_check(string s)
    {
        string prefix = "";
        for (int i = 0; i < s.length(); i++)
        {
            prefix += s[i];
            if (!search(prefix))
            {
                return false;
            }
        }
        return true;
    }

};

string completeString(int n, vector<string> &a){
    Trie tr;
    for(auto it : a)
    {
        tr.insertNode(it);
    }

    string longest = "";

    for(auto it : a)
    {
        if(tr.pr_check(it))
        {
            if(it.length() > longest.length())
            {
                longest = it;
            }
            if(it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }
    return (longest.length()) ? longest : "None";
}

