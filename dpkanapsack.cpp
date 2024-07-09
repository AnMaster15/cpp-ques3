#include<bits/stdc++.h>
using namespace std;


    int solve(int W, int wt[], int val[], int n){
     if(n==0){
                
        if(wt[0] <=W){
            return val[0];
        }
        else{
            return 0;
        }
        
     }
     
     int include=0;
     
     if (wt[n]<=W){
          include = val[n] + solve(W-wt[n],wt,val,n-1);
    
    }
    
     int exclude=0 + solve(W,wt,val,n-1);
    
     int ans=max(include,exclude);
     
     return ans;
    
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return solve(W,wt,val,n-1);
    }



int main() 
{ 
    int profit[] = { 60, 100, 120 }; 
    int weight[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(profit) / sizeof(profit[0]); 
    cout << "maximum profit is : "<< knapSack(W, weight, profit, n); 
    return 0; 
} 


// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article