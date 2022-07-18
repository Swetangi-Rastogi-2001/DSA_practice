
/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/*/

//RECURSION
class Solution {
public:
    
    int f(int index, int buy, vector<int> &prices){
        if(index>=prices.size()){
            return 0;
        }
        
        
        if(buy){
            return max(-prices[index]+f(index+1, 0, prices), f(index+1, 1, prices));
        }
        else{
            return  max(prices[index]+f(index+2, 1, prices), f(index+1, 0, prices));
        }
    }
    
    
    int maxProfit(vector<int>& prices) {
        return f(0, 1, prices);
    }
};


//MEMOIZATION
class Solution {
public:
    
    int f(int index, int buy, vector<int> &prices,  vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        
        if(buy){
            return dp[index][buy]=max(-prices[index]+f(index+1, 0, prices, dp), f(index+1, 1, prices, dp));
        }
        else{
            return  dp[index][buy]=max(prices[index]+f(index+2, 1, prices, dp), f(index+1, 0, prices, dp));
        }
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2 ,-1));
        return f(0, 1, prices, dp);
    }
};




//DP
class Solution {
public:    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2 ,0));
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[index][buy]=max(-prices[index]+dp[index+1][0], dp[index+1][1]);
                }
                else{
                    dp[index][buy]=max(prices[index]+dp[index+2][1], dp[index+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }
};


//6 variable
class Solution {
public:    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(2 ,0), front2(2, 0), front1(2, 0);
        
        for(int index=n-1;index>=0;index--){
            
                dp[1]=max(-prices[index]+front1[0], front1[1]);
                
                dp[0]=max(prices[index]+front2[1], front1[0]);
            
                front2=front1;
                front1=dp;
            
        }
        
        return dp[1];
    }
};

