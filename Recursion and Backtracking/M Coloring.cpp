// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution{
public:
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col) 
    {
        for (int k = 0; k < n; k++) 
        {
            if (k != node && graph[k][node] == 1 && color[k] == col) 
            {
                return false; // adj nodes have same color
            }
        }
        return true;
    }
    bool solve(int node, int color[], int m, int N, bool graph[101][101]) 
    {
        if (node == N) 
        {
            return true;
        }

        for (int i = 1; i <= m; i++) 
        {
            if (isSafe(node, color, graph, N, i)) 
            {
                color[node] = i;
                
                // Move to next node :
                if (solve(node + 1, color, m, N, graph)) 
                return true;

                // Backtrack
                color[node] = 0;
            }

        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int N) 
    {
        int color[N] = {0};
        if (solve(0, color, m, N, graph)) 
        return true;

        return false;
    }
};