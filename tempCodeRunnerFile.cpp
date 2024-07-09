#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


    string largestNumber(vector<int>& nums) {
        
       
        vector<int>ans;
        
        int size=nums.size();
       
        for(int i=0;i<size;i++){
            int digit = nums[i]%10;
            nums[i] /= 10;
            ans[i]=digit;
        }
        
        sort(ans.begin(),ans.end(),greater<int>());
        
       string s="";
    
    for (int i = 0; i < ans.size(); ++i) {
        s = to_string(ans[i]);
    }

      return s;
        
    }
int main() {
    vector<int> nums = {3, 30, 34, 5, 9}; // Example input
    cout << "Largest Number: " << largestNumber(nums) << endl;
    return 0;
}


