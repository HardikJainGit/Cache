#include <bits/stdc++.h>
using namespace std;

class Node 
{
    public:
        int data;
        int row, col;

        // Constructor

        Node(int data, int row, int col) 
        {
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

bool compare(Node* a, Node* b) {
    return a->data > b->data;
}


vector<int> mergeKSortedArrays(vector<vector<int> > kArrays, int K) {

   priority_queue<Node*, vector<Node*>, decltype(&compare)> minHeap(&compare);  //Node* type minHeap

    // Step 1 : Insert all first elements in minHeap
    for(int row=0; row<K; row++) {
        Node* temp = new Node(kArrays[row][0], row, 0); //col=0
        minHeap.push(temp);
    }

    vector<int> ans;

    // Step 2 : Comparing each node and moving further in the array
    while(minHeap.size() > 0) {
        Node* temp = minHeap.top(); //minimum element

        ans.push_back(temp->data);
        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        // Push next element of the same array temp belongs to
        
        if(col+1 < kArrays[row].size()) {
            Node* next = new Node(kArrays[row][col+1], row, col+1); //pushing next element in heap
            minHeap.push(next);
        }
    }

    return ans;
}