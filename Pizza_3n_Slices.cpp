#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int index, int endindex, vector<int> &slices, int n, vector<vector<int>> &dp)
{
    if(n == 0 || index > endindex)
    {
        return 0;
    }

    if(dp[index][n] != -1)
    {
        return dp[index][n];
    }

    int take = slices[index] + Memoization(index+2, endindex, slices, n-1, dp);
    int nottake = 0 + Memoization(index+1, endindex, slices, n, dp);

    return dp[index][n] = max(take, nottake);
}

int Tabulation(vector<int> &slices)
{
    int k = slices.size();
    vector<vector<int>> dp1(k+2, vector<int>(k ,0));
    vector<vector<int>> dp2(k+2, vector<int>(k, 0));

    for(int index = k-2; index>=0; index--)
    {
        for(int n=1; n<=k/3; n++)
        {
            int take = slices[index] + dp1[index+2][n-1];
            int nottake = 0 + dp1[index+1][n];

            dp1[index][n] = max(take, nottake);
            cout<<dp1[index][n]<<"  ";
        }
    }

    int case1 = dp1[0][k/3];
    // cout<<case1<<endl;
    for(int index=k-1; index>=1; index--)
    {
        for(int n=1; n<=k/3; n++)
        {
            int take = slices[index] + dp2[index+2][n-1];
            int nottake = 0 + dp2[index+1][n];

            dp2[index][n] = max(take, nottake);
        }
    }

    int case2 = dp2[1][k/3];
    return max(case1, case2);
}

int Space_Opti(vector<int> &slices)
{
    int k = slices.size();

    vector<int> prev1(k+2, 0);
    vector<int> curr1(k+2, 0);
    vector<int> next1(k+2, 0);

    for(int index=k-2; index>=0; index--)
    {
        for(int n=1; n<=k/3; n++)
        {
            int take = slices[index] + next1[n-1];
            int nottake = 0 + curr1[n];

            prev1[n] = max(take, nottake);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    int case1 = curr1[k/3];

    vector<int> prev2(k+2, 0);
    vector<int> curr2(k+2, 0);
    vector<int> next2(k+2, 0);

    for(int index=k-1; index>=1; index--)
    {
        for(int n=1; n<=k/3; n++)
        {
            int take = slices[index] + next2[n-1];
            int nottake = 0 + curr2[n];

            prev2[n] = max(take, nottake);
        }
        next2 = curr2;
        curr2 = prev2;
    }

    int case2 = curr2[k/3];

    return max(case1, case2);
}

int max_slices(vector<int> &slices)
{
    // int k = slices.size();
    // vector<vector<int>> dp1(k, vector<int>(k, -1));
    // int case1 = Memoization(0, k-2, slices, k/3, dp1);

    // vector<vector<int>> dp2(k, vector<int>(k, -1));
    // int case2 = Memoization(1, k-1, slices, k/3, dp2);

    // return max(case1, case2);

    return Tabulation(slices);

    // return Space_Opti(slices);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int k;
    cin>>k;

    vector<int> slices;

    for(int i=0; i<k; i++)
    {
        int t;
        cin>>t;

        slices.push_back(t);
    }

    cout<<max_slices(slices);
    return 0;
}