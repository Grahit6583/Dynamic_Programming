#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxEnvelopes(int n, vector<vector<int>> &env)
{
    if(n == 0)
    {
        return 0;
    }

    sort(env.begin(), env.end(), [](vector<int> a, vector<int> b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    vector<int> ans;
    ans.push_back(env[0][1]);

    for(int i=1; i<n; i++)
    {
        if(env[i][1] > ans.back())
        {
            ans.push_back(env[i][1]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), env[i][1])-ans.begin();
            ans[index] = env[i][1];
        }
    }

    return ans.size();
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    vector<vector<int>> env;

    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int i=0; i<=1; i++)
        {
            int t;
            cin>>t;

            temp.push_back(t);
        }
        env.push_back(temp);
    }

    cout<<maxEnvelopes(n, env);
}