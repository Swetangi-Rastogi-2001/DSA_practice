/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/*/


//RECURSION
class Solution {
public:
    
    int f(int index, int buy, vector<int> &prices){
        if(index==prices.size()){
            return 0;
        }
         int profit=0;
        
        if(buy){
            profit= max( -prices[index]+f(index+1, 0, prices), 0+f(index+1, 1, prices));
        }
        else{
            profit= max( prices[index]+f(index+1, 1, prices), 0+f(index+1, 0, prices));
        }
        
        return profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        return f(0, 1, prices);
    }
};



//MEMOIZATION
class Solution {
public:
    
    int f(int index, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(index==prices.size()){
            return 0;
        }
        
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
         int profit=0;
        
        if(buy){
            profit= max( -prices[index]+f(index+1, 0, prices, dp), 0+f(index+1, 1, prices, dp));
        }
        else{
            profit= max( prices[index]+f(index+1, 1, prices, dp), 0+f(index+1, 0, prices, dp));
        }
        
        return dp[index][buy]=profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};



//DP
class Solution {
public:
       
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        dp[n][0]=dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--){
            dp[i][1]= max(-prices[i]+dp[i+1][0], dp[i+1][1]);
            dp[i][0]= max(prices[i]+dp[i+1][1], dp[i+1][0]);
        }
        
        return dp[0][1];
    }
};


//SPACE OPTIMIZED
class Solution {
public:
       
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int> dp(2, 0), temp(2, 0);

        dp[0]=dp[1]=0;
        
        for(int i=n-1;i>=0;i--){
            temp[1]= max(-prices[i]+dp[0], dp[1]);
            temp[0]= max(prices[i]+dp[1], dp[0]);
            dp=temp;
        }
        
        return dp[1];
    }
};
