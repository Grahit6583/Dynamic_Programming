#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int LongestSubsequence(vector<int> &arr, int diff)
{
    unordered_map<int,int> dp;

    int ans = 0;

    for(int i=0; i<arr.size(); i++)
    {
        int temp = arr[i]-diff;
        int tempAns = 0;

        if(dp.count(temp))
        {
            tempAns = dp[temp];
        }

        dp[arr[i]] = 1+tempAns;
        ans = max(ans, dp[arr[i]]);
    }

    return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    int diff;
    cin>>diff;
    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;

        arr.push_back(t);
    }

    cout<<LongestSubsequence(arr, diff);

    return 0;
}