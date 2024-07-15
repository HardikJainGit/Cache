#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vi>>
#define f(b) for(int i=0;i<b;i++)
#define fz(i,a,b) for(int i=a;i<b;i++)
#define sz(x) ((int)(x).size())
#define vp vector<pair<int,int>>
#define pi pair<int,int>
#define pb push_back
#define ff first
#define ss second

// https://www.naukri.com/code360/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


void insert(int arr[],int val,int size) { //O(log N)
    int index = ++size;
    arr[index] = val; //base 1 indexing first element -1    

    while(index > 1) {
        int parent = index/2;

        if(arr[parent] > arr[index]) { //max heap
            swap(arr[parent], arr[index]);
            index = parent; //next we compare the parent with its parent ie keep going up
        } else {
            return;
        }
    }   
}
void heapify(int arr[], int n, int i) 
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    

    if(left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
            
    if(right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
int pr_min(int arr[],int size) // O(1)
{
    if (size == 1) {
        size -= 1;
        return arr[1];
    }
    int ret = arr[1];
    arr[1] = arr[size];
    size -= 1;
    heapify(arr,size,1);
    return ret;
}

vector<int> minHeap(int n, vector<vector<int>>& q) 
{
    vi ret;
    int size = 0;

    int arr[n];

    for (int i = 0; i < n; i++) 
    {
        if (q[i][0] == 0) 
        {
            insert(arr, q[i][1], size);
        } else 
        {
            ret.push_back(pr_min(arr, size));
        }
    }

    return ret;
}