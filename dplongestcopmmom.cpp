#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b, int i, int j)
{
    if (a.size() == i)
    {
        return 0;
    }

    if (b.size() ==j)
    {
        return 0;
    }
   int ans=0;
    if (a[i] == b[j])
    {
        ans= solve(a, b, i + 1, j + 1) + 1;
    }
    else
    {
        ans= max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
    }
    return ans;
}
int longestCommonSubsequence(string text1, string text2)
{

    //         int size1=text.size();
    //         int size2=text.size();

     return solve(text1, text2, 0, 0); // 0 and 0 starting point of both string
   
}

int main()
{
    string S1 = "ayush";
    string S2 = "ayushi";
    int m = S1.size();
    int n = S2.size();

    cout << "Length of LCS is " << longestCommonSubsequence(S1, S2);

    return 0;
}


// https://leetcode.com/problems/longest-common-subsequence/submissions/