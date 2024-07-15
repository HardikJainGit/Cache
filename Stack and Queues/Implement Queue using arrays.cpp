#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/implement-queue-using-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-queue-using-array

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    arr[rear++] = x;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(front==rear) //not rear + 1 as rear is already updated arr[read] is empty
    {
        return -1;
    }
    int x = arr[front];
    front+=1;
    return x;
}