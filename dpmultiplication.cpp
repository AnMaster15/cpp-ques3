#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int mini = INT_MAX;
	int count;

	for (k = i; k < j; k++) 
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		mini = min(count, mini);
	}
	return mini;
}

int main()
{
	int arr[] = { 4,10,3, 12,20,7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, 1, N - 1);
	return 0;
}

// #include <vector>
// #include <string>
// #include <algorithm>
// #include <iostream>

// using namespace std;


//     string largestNumber(vector<int>& nums) {
        
       
//         vector<int>ans;
        
//         int size=nums.size();
       
//         for(int i=0;i<size;i++){
//             int digit = nums[i]%10;
//             nums[i] /= 10;
//             ans[i]=digit;
//         }
        
//         sort(ans.begin(),ans.end(),greater<int>());
        
//        string s="";
    
//     for (int i = 0; i < ans.size(); ++i) {
//         s = to_string(ans[i]);
//     }

//       return s;
        
//     }
// int main() {
//     vector<int> nums = {3, 30, 34, 5, 9}; // Example input
//     cout << "Largest Number: " << largestNumber(nums) << endl;
//     return 0;
// }


