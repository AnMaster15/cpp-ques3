// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum=0;
//         int maxi=nums[0];

//         for(int i=0;i<nums.size();i++){
//             sum=sum+nums[i];

//             maxi=max(maxi,sum);
//             if (sum<0){
//                 sum=0;
//             }
//         }
//         return maxi;
        
//     }
// };

#include<iostream>
#include<vector>
using namespace std;

 int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=nums[0];

        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];

            maxi=max(maxi,sum);
            if (sum<0){
                sum=0;
            }
        }
        return maxi;
        
    }
int main() {
    
    vector<int> vect = {-7,-11,6,-1,8,-3,1,-1,4,-1,5,7,0};

    int result = maxSubArray(vect);

    cout << "Maximum Sub-array Sum: " << result << endl;

    return 0;
}

// #include<iostream>
// using namespace std;

// int maxCrossingSubArray(int nums[], int low, int mid, int high) {
//     int leftSum =0;
//     int sum = 0;

//     for (int i = mid; i >= low; i--) {
//         sum += nums[i];
//         leftSum = max(leftSum, sum);
//     }

//     int rightSum =0;
//     sum = 0;

//     for (int i = mid + 1; i <= high; i++) {
//         sum += nums[i];
//         rightSum = max(rightSum, sum);
//     }

//     return leftSum + rightSum;
// }

// int maxSubArrayRecursive(int nums[], int low, int high) {
//     if (low == high) {
//         return nums[low];
//     }

//     int mid = (low + high) / 2;

//     int leftMax = maxSubArrayRecursive(nums, low, mid);
//     int rightMax = maxSubArrayRecursive(nums, mid + 1, high);
//     int crossMax = maxCrossingSubArray(nums, low, mid, high);

//     int result = leftMax > rightMax ? leftMax : rightMax;
//     return result > crossMax ? result : crossMax;
// }

// int main() {
//     int arr[] = {-1, -5, 0, 12, 2, -5};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int result = maxSubArrayRecursive(arr, 0, n - 1);

//     cout << "Maximum Sub-array Sum: " << result << endl;

//     return 0;
// }

