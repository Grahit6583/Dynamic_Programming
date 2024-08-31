#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int index, int N, int arr[], int target, vector<vector<int>> &dp)
{
    if(index >= N)
    {
        return 0;
    }

    if(target < 0)
    {
        return 0;
    }

    if(target == 0)
    {
        return 1;
    }

    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool incl = Memoization(index+1, N, arr, target-arr[index], dp);
    bool excl = Memoization(index+1, N, arr, target-0, dp);

    return dp[index][target] = incl or excl;
}

int Tabulation(int N, int arr[], int total)
{
    vector<vector<int>> dp(N+1, vector<int>(total+1, 0));

    for(int i=0; i<=N; i++)
    {
        dp[i][0] = 1;
    }

    for(int index=N-1; index>=0; index--)
    {
        for(int target=0; target<=total/2; target++)
        {
            bool incl = 0;
            if(target-arr[index] >= 0)
            {
                incl = dp[index+1][target-arr[index]];
            }
            bool excl = dp[index+1][target];

            dp[index][target] = incl or excl;
        }
    }

    return dp[0][total/2];
}

int Space_Opti(int N, int arr[], int total)
{
    vector<int> next(total/2 + 1, 0);
    vector<int> curr(total/2 + 1, 0);

    curr[0] = 1;
    next[0] = 1;

    for(int index=N-1; index >= 0; index--)
    {
        for(int target=0; target<=total/2; target++)
        {
            bool incl = 0;
            if(target-arr[index] >= 0)
            {
                incl = next[target-arr[index]];
            }
            bool excl = next[target];

            curr[target] = incl or excl;
        }
        next = curr;
    }

    return next[total/2];
}

int equal_partition(int N, int arr[])
{
    int total=0;

    for(int i=0; i<N; i++)
    {
        total += arr[i];
    }

    if(total & 1)
    {
        return 0;
    }

    // int target = total/2;
    // vector<vector<int>> dp(N, vector<int>(target+1, -1));
    // return Memoization(0, N, arr, target, dp);

    // return Tabulation(N, arr, total);

    return Space_Opti(N, arr, total);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int N;
    cin>>N;

    int arr[N];

    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
    }

    if(equal_partition(N, arr) == 1)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}