#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(vector<int> &nums, int n, vector<int> &dp)
{
    if(n < 0)
    {
        return 0;
    }

    if(n == 0)
    {
        return nums[0];
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    int incl = Memoization(nums, n-2, dp) + nums[n];
    int excl = Memoization(nums, n-1, dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

int Tabulation(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n,0);
    dp[0] = nums[0];
    dp[-1] = 0;
    for(int i=1; i<n; i++)
    {
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }

    return dp[n-1];

}

int SpaceOptimization(vector<int> &nums)
{
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1; i<n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int MaxiSum(vector<int> &nums)
{
    // int n = nums.size();
    // vector<int> dp(n, -1);
    // return Memoization(nums,n-1,dp);

    // return Tabulation(nums);

    return SpaceOptimization(nums);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        nums.push_back(t);
    }

    for(int i=0; i<n; i++)
    {
        cout<<nums[i]<<"  ";
    }

    cout<<endl;
    cout<<MaxiSum(nums)<<endl;
    return 0;
}