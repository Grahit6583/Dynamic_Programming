#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Memoization(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>>& dp)
{
    if(index == 0)
    {
        if(weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if(dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int incl = 0;
    if(weight[index] <= capacity)
    {
        incl = value[index] + Memoization(weight, value, index-1, capacity-weight[index], dp);
    }

    int excl = 0 + Memoization(weight, value, index-1, capacity, dp);

    dp[index][capacity] = max(incl,excl);

    return dp[index][capacity]; 
}

int Tabulation(vector<int> weight, vector<int> value, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

    for(int w=weight[0]; w<=capacity; w++)
    {
        if(weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for(int index =1; index<n; index++)
    {
        for(int w=0; w<=capacity; w++)
        {
            int include = 0;
            if(weight[index] <= w)
            {
                include = value[index] + dp[index-1][w-weight[index]];
            }
            int exclude = 0 + dp[index-1][w];
            dp[index][w] = max(include,exclude);
        }
    }
    return dp[n-1][capacity];
}

int Space_Opti(vector<int> weight, vector<int> value, int n, int capacity)
{
    vector<int> curr(capacity+1, 0);
    vector<int> prev(capacity+1, 0);

    for(int w = weight[0]; w<=capacity; w++)
    {
        if(weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for(int index = 1; index < n; index++)
    {
        for(int w = weight[0]; w<=capacity; w++ )
        {
            int include = 0;
            if(weight[index] <= w)
            {
                include = value[index] + prev[w-weight[index]];
            }

            int exclude = 0+prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[capacity];
}

int Space_Opti1(vector<int> weight, vector<int> value, int n, int capacity)
{
    vector<int> curr(capacity+1, 0);

    for(int w = weight[0]; w<=capacity; w++)
    {
        if(weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for(int index = 1; index < n; index++)
    {
        for(int w = capacity; w>=0; w-- )
        {
            int include = 0;
            if(weight[index] <= w)
            {
                include = value[index] + curr[w-weight[index]];
            }

            int exclude = 0+curr[w];
            curr[w] = max(include, exclude);
        }
    }

    return curr[capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// vector<vector<int>> dp(n,vector<int>(maxWeight +1, -1 ));
	// return Memoization(weight, value, n-1, maxWeight, dp);

	// return Tabulation(weight, value, n, maxWeight);

	// return Space_Opti(weight, value, n, maxWeight);
	return Space_Opti1(weight, value, n, maxWeight);

}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    int maxweight;
    cin>>maxweight;
    vector<int> value,weight;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        weight.push_back(t);
    }

    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        value.push_back(t);
    }

    cout<<knapsack(weight,value,n,maxweight)<<endl;

    return 0;
}