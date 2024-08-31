#include<iostream>
#include <bits/stdc++.h> 

using namespace std;

long long int Space_Opti(vector<int> &nums)
{
    int n = nums.size();

    long long int prev2 = 0;
    long long int prev1 = nums[0];

    for(int i=1; i<n; i++)
    {
        long long int incl = prev2 + nums[i];
        long long int excl = prev1 + 0;

        long long int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();

    if(n == 1)
    {
        return valueInHouse[0];
    }

    vector<int> first, second;

    for(int i=0; i<n; i++)
    {
        if(i != n-1)
        {
            first.push_back(valueInHouse[i]);
        }

        if(i != 0)
        {
            second.push_back(valueInHouse[i]);
        }
    }

    return max(Space_Opti(first), Space_Opti(second));
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    vector<int> house;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        house.push_back(t);
    }

    cout<<houseRobber(house)<<endl;
    return 0;
}