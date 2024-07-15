#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution 
{
public:

    static bool compareJobs(Job a,Job b)
    {
        return a.profit > b.profit; // higher profit
    }

    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, compareJobs);

        vector<int> slot (n+1,0);
        int jobsDone = 0, maxProfit = 0;

        for (int i = 0; i < n; i++)
        {
            // Iterate the slots from end till 0
            for (int j = min(n, arr[i].dead); j > 0; j--)
            {
                if (!slot[j])
                {
                    slot[j] = 1;
                    maxProfit += arr[i].profit;
                    jobsDone++;
                    break; // because slot[j] is occupied
                }
            }
        }

        return {jobsDone, maxProfit};
    } 
};