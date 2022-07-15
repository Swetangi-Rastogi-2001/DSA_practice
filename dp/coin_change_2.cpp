/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1*/




//MEMOIZATION
class Solution {
public:
    
    int f(int index, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(target==0){
            return 1;
        }
        if(index==0){
            return (target%coins[0]==0);
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int nottake= f(index-1, target, coins, dp);
        int take=0;
        if(target>=coins[index]){
            take= f(index, target-coins[index], coins, dp);
        }
        
        return dp[index][target]=nottake+take;
    }
    
    
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
        return f(coins.size()-1, amount, coins, dp); 
    }
};


//DP
class Solution {
public:

    
    
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, 0));
        int n=coins.size();
        
        for(int index=0;index<n;index++){
            dp[index][0]=1;
        }
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                dp[0][target]=1;
            }
        }
        
        for(int index=1;index<n;index++){
            for(int target=0;target<=amount;target++){
                int nottake= dp[index-1][target];
                int take=0;
                if(target>=coins[index]){
                    take= dp[index][target-coins[index]];
                }
                dp[index][target]=nottake+take;
            }
        }
               
        
        return dp[coins.size()-1][ amount]; 
    }
};


//SPACE OPTIMIZATION
class Solution {
public:

    
    
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp(amount+1, 0), temp(amount+1, 0);
        int n=coins.size();
        
        for(int index=0;index<n;index++){
            dp[0]=1;
        }
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0){
                dp[target]=1;
            }
        }
        
        for(int index=1;index<n;index++){
            for(int target=0;target<=amount;target++){
                int nottake= dp[target];
                int take=0;
                if(target>=coins[index]){
                    take= temp[target-coins[index]];
                }
                temp[target]=nottake+take;
            }
            dp=temp;
        }
               
        
        return dp[ amount]; 
    }
};


