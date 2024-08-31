#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Space_Opti(string a, string b)
{
    vector<int> curr(a.length() + 1, 0);
    vector<int> next(b.length() + 1, 0);

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            if (a[i] == b[j])
            {
                curr[j] = 1 + next[j + 1];
            }
            else
            {
                curr[j] = max(next[j], curr[j + 1]);
            }
        }
        next = curr;
    }

    return next[0];
}
int longestPalindromeSubseq(string s)
{
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    return Space_Opti(s, revStr);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;
    while(cin>>s)
    {
        cout<<longestPalindromeSubseq(s)<<endl;
    }
    return 0;
}