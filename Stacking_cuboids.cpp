#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool check(vector<int> base, vector<int> newbox)
{
    if(newbox[0] <= base[0] && newbox[1] <= base[1] && newbox[2] <= base[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Tabulation(int n, vector<vector<int>> &a)
{
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for(int curr = n-1; curr>=0; curr--)
    {
        for(int prev = curr-1; prev>=-1; prev--)
        {
            int include = 0;
            if(prev == -1 || check(a[curr], a[prev]))
            {
                include = a[curr][2] + nextRow[curr + 1];
            }
            
            int exclude = 0 + nextRow[prev+1];
            currRow[prev +1] = max(include, exclude);
        }

        nextRow = currRow;
    }

    return nextRow[0];
}

int max_height(vector<vector<int>> &a)
{
    for(auto &i : a)
    {
        sort(i.begin(), i.end());
    }

    sort(a.begin(), a.end());

    return Tabulation(a.size(), a);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    vector<vector<int>> a;

    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<=2; j++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        a.push_back(temp);
    }

    cout<<max_height(a)<<endl;
    return 0;
}