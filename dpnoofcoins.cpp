 int solverec(vector<int>& coins, int x){
        if(x==0){
            return 0;
        }
        if(x<0){
            return INT_MAX;
        }
        
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solverec(coins,x-coins[i]);
            if(ans!=INT_MAX){
                mini=min(mini,1+ans);
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int ans=solverec(coins,amount);
        if(ans==INT_MAX)
            return -1;
        
        return ans;
        
    }
^
||
||
done by recursion


//https://leetcode.com/problems/coin-change/