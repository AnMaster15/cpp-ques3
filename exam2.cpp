#include <bits/stdc++.h>
using namespace std;

bool ans(vector<int> &nums, int k, int target, int start, vector<int> &groups, vector<vector<int>> &result)
{
    if (k == 0)
        return true;

    for (int i = start; i < nums.size(); i++)
    {
        if (i > start && nums[i] == nums[i - 1])
            continue;

        groups[k - 1] += nums[i];

        if (groups[k - 1] == target)
        {
            if (ans(nums, k - 1, target, 0, groups, result))
                return true;
        }
        else
        {
            if (ans(nums, k, target - nums[i], i + 1, groups, result))
                return true;
        }
        groups[k - 1] -= nums[i];
    }
    return false;
}

bool subset(vector<int> &nums, int k, vector<vector<int>> &result)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum % k != 0)
        return false;
    int target = sum / k;
    vector<int> groups(k, 0);
    sort(nums.begin(), nums.end(), greater<int>());
    return ans(nums, k, target, 0, groups, result);
}

int main()
{
    vector<int> nums = {2, 1, 4, 5, 6};
    int k = 3;
    vector<vector<int>> result(k);
    if (subset(nums, k, result))
    {
        cout << "Can be divided into " << k << " subsets with equal sum." << endl;
    }
    else
    {
        cout << "Cannot be divided into " << k << " subsets with equal sum." << endl;
    }
    return 0;
}
