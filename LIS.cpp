#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int n, int a[], int curr, int prev, vector<vector<int>>&dp)
{
    if(curr == n)
    {
        return 0;
    }

    if(dp[curr][prev+1] != -1)
    {
        return dp[curr][prev+1];
    }

    int include = 0;
    if(prev == -1 || a[curr] > a[prev])
    {
        include = 1 + Memoization(n,a, curr+1, curr, dp);
    }

    int exclude = 0 + Memoization(n, a, curr+1, prev, dp);

    return dp[curr][prev+1] = max(include, exclude);
}

int Tabulation(int n, int a[])
{
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = curr-1; prev>=-1; prev--)
            {
                int include = 0;
                if(prev == -1 || a[curr] > a[prev])
                {
                    include = 1 + dp[curr+1][curr + 1];
                }
                int exclude = 0 + dp[curr+1][prev + 1];
                
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        
        return dp[0][0];
}
    
int Tabulation1(int n, int a[])
{
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = curr-1; prev>=-1; prev--)
            {
                int include = 0;
                if(prev == -1 || a[curr] > a[prev])
                {
                    include = 1 + nextRow[curr + 1];
                }
                int exclude = 0 + nextRow[prev + 1];
                
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        
    return nextRow[0];
}
    
int Space_Optimal(int n, int a[])
{
    if(n == 0)
    {
        return 0;
    }
        
    vector<int> ans;
    ans.push_back(a[0]);
    
    for(int i=1; i<n; i++)
    {
        if(a[i] > ans.back())
        {
        ans.push_back(a[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}
int LIS(int n, int a[])
{
    // vector<vector<int>> dp(n, vector<int>(n+1, -1));
    // return Memoization(n, a, 0, -1, dp);
    // return Tabulation(n, a);
        
    // return Tabulation1(n, a);
        
    return Space_Optimal(n, a);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    cout<<LIS(n,a)<<endl;
    return 0;
}