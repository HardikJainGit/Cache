#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

class Solution {
public:
#define INF 99999

    void shortest_distance(vector<vector<int>>& matrix) {
        int V = matrix.size();

        // Replace -1 with INF, and set diagonal elements to 0
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (matrix[i][j] == -1 && i != j) {
                    matrix[i][j] = INF;
                } else if (i == j) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Floyd-Warshall algorithm
        // k is split point i starting j ending
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }

        // Replace INF back to -1 to indicate no path
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (matrix[i][j] == INF) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};
