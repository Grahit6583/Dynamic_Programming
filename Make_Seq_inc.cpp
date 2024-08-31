#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
{
    if(index == nums1.size())
    {
        return 0;
    }

    if(dp[index][swapped] != -1)
    {
        return dp[index][swapped];
    }

    int ans = INT_MAX;

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    if(swapped)
    {
        swap(prev1, prev2);
    }

    if(nums1[index] > prev1 && nums2[index] > prev2)
    {
        ans = Memoization(nums1, nums2, index+1, 0, dp);
    }

    if(nums1[index] > prev2 && nums2[index] > prev1)
    {
        ans = min(ans, 1 + Memoization(nums1, nums2, index+1, 1, dp));
    }

    return dp[index][swapped] = ans;
}

int Tabulation(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int index=n-1; index>=1; index--)
    {
        for(int swapped = 1; swapped>=0; swapped--)
        {
            int ans = INT_MAX;

            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];

            if(swapped)
            {
                swap(prev1, prev2);
            }

            if(nums1[index] > prev1 && nums2[index] > prev2)
            {
                ans = dp[index+1][0];
            }

            if(nums1[index] > prev2 && nums2[index] > prev1)
            {
                ans = min(ans, 1+dp[index+1][1]);
            }

            dp[index][swapped] = ans;
        }
    }

    return dp[1][0];
}

int Space_Opti(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    int swap = 0;
    int noswap = 0;
    int currswap = 0;
    int currnoswap = 0;

    for(int index=n-1; index>=0; index--)
    {
        for(int swapped = 1; swapped>=0; swapped--)
        {
            int ans = INT_MAX;

            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];

            if(swapped)
            {
                int temp = prev1;
                prev1 = prev2;
                prev2 = prev1;
            }

            if(nums1[index] > prev1 && nums2[index] > prev2)
            {
                ans = noswap;
            }

            if(nums1[index] > prev2 && nums2[index] > prev1)
            {
                ans = min(ans, 1+swap);
            }

            if(swapped)
            {
                currswap = ans;
            }
            else
            {
                currnoswap = ans;
            }
        }
        swap = currswap;
        noswap = currnoswap;
    }

    return min(currswap, currnoswap);
}

int Make_Seq(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    // bool swapped = 0;
    // int n = nums1.size();
    // vector<vector<int>> dp(n, vector<int>(2, -1));
    // return Memoization(nums1, nums2, 1, swapped, dp);

    return Tabulation(nums1, nums2);

}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    vector<int> nums1;
    vector<int> nums2;

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        nums1.push_back(t);
    }

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        nums2.push_back(t);
    }


    cout<<Make_Seq(nums1, nums2)<<endl;
    return 0;
}