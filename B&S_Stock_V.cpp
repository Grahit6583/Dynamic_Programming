#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Space_Opti(vector<int> &prices, int fee)
{
    int n = prices.size();

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for(int index = prices.size() - 1; index>=0; index-- )
    {
        for(int buy=0; buy<=1; buy++)
        {
            if(buy)
            {
                curr[buy] = max((-prices[index] + next[0]),(next[1]));
            }
            else
            {
                curr[buy] = max((prices[index] + next[1] - fee),(next[0]));
            }
        }
        next = curr;
    }

    return next[1];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, fee;
    cin>>n>>fee;

    vector<int> prices(n);

    for(int i=0; i<n; i++)
    {
        cin>>prices[i];
    }

    cout<<Space_Opti(prices, fee)<<endl;

    return 0;
}