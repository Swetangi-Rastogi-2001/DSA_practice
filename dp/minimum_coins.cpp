/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1*/





//RECURSION
class Solution {
public:
    
    int f(int index, int target, vector<int> coins){
    
        if(index==0){
        
            if(target%coins[index]==0){
                return target/coins[index];
            }
            return 1e9;
        }
        
        int nottake= f(index-1, target, coins);
        int take= 1e8;
        if(target>= coins[index]){
            take= 1+ f(index, target- coins[index], coins);
        }
        
        return min(take, nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        
       int ans= f(coins.size()-1, amount, coins);

        if(ans>amount){
              return -1;
         }
        return ans;
    }
};

//MEMOIZATION
int f(int index, int target, vector<int> coins, vector<vector<int>> &dp){
    
        if(index==0){
        
            if(target%coins[index]==0){
                return target/coins[index];
            }
            return 1e9;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int nottake= f(index-1, target, coins, dp);
        int take= 1e8;
        if(target>= coins[index]){
            take= 1+ f(index, target- coins[index], coins, dp);
        }
        
        return dp[index][target]=min(take, nottake);
 }
int minimumElements(vector<int> &coins, int amount)
{
    // Write your code here.
    vector<vector<int>> dp(coins.size(), vector<int> (amount+1, -1));
    int ans= f(coins.size()-1, amount, coins, dp);

    if(ans>amount){
              return -1;
     }
     return ans;
}


//DP
int minimumElements(vector<int> &coins, int amount)
{
    // Write your code here.
    vector<vector<int>> dp(coins.size(), vector<int> (amount+1, 1e8));
    
    for(int i=0;i<=amount;i++){
        if(i%coins[0]==0){
            dp[0][i]= i/coins[0];
        }
        else{
            dp[0][i]=1e8;
        }
    }
    
    for(int index=1;index<coins.size();index++){
        for(int target= 0;target<=amount; target++){
       
            int nottake= dp[index-1][target];
            int take= 1e8;
            if(target>= coins[index]){
                take= 1+ dp[index][target- coins[index]];
            }
            dp[index][target]= min(take, nottake);
        }
    }
    
    int ans= dp[coins.size()-1][amount];
    if(ans>=1e8){
              return -1;
     }
     return ans;
}


//SPACE OPTIMIZATION
int minimumElements(vector<int> &coins, int amount)
{
    // Write your code here.
    vector<int> dp(amount+1, 1e8), temp(amount+1, 1e8);
    for(int i=0;i<=amount;i++){
        if(i%coins[0]==0){
            dp[i]= i/coins[0];
        }
        else{
            dp[i]=1e8;
        }
    }
    
    for(int index=1;index<coins.size();index++){
        for(int target= 0;target<=amount; target++){
            int nottake= dp[target];
            int take= 1e8;
            if(target>=coins[index]){
                take= 1+ temp[target- coins[index]];
            }
            temp[target]= min(take, nottake);
        }
       dp=temp;
    }
    
    int ans= dp[amount];
    if(ans>=1e8){
              return -1;
     }
     return ans;
}
