#include<bits/stdc++.h>
using namespace std;

// By rank :

vector<int> parent;
vector<int> rank_;
vector<int> size;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    rank_[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_[a] < rank_[b])
            swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b])
            rank_[a]++;
    }
}

// by size :

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}