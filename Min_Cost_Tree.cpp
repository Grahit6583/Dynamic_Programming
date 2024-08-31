#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(int left, int right, vector<int> &arr, map<pair<int, int>,int> &maxi, vector<vector<int>> &dp)
{
    if(left == right)
    {
        return 0;
    }

    if(dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int ans = INT_MAX;

    for(int i=left; i<right; i++)
    {
        ans = min(ans, maxi[{left, i}]*maxi[{i+1, right}] + Memoization(left, i, arr, maxi, dp) + Memoization(i+1, right, arr, maxi, dp));
    }

    return dp[left][right] = ans;
}

int Min_Tree(vector<int> &arr)
{
    int n = arr.size();
    map<pair<int,int>, int> maxi;

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    for(int i=0; i<n; i++)
    {
        maxi[{i,i}] = arr[i];
        for(int j=i+1; j<n; j++)
        {
            maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
        }
    }

    return Memoization(0,n-1,arr,maxi,dp);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    typedef vector<int> vi;
    typedef pair<int, int> ii;

    int n;
    cin>>n;

    vi arr;

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }

    cout<<Min_Tree(arr)<<endl;
    return 0;
}