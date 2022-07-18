


//RECURSION

class Solution {
public:
    
    int f(int index, int buy, vector<int> &prices, int fee){
        if(index==prices.size()){
            return 0;
        }
        
        if(buy){
            return max(-prices[index]+f(index+1, 0, prices, fee), f(index+1, 1, prices, fee));
        }
        else{
            return max(prices[index]+f(index+1, 1, prices, fee)-fee, f(index+1, 0, prices, fee));
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        return f(0, 1, prices, fee);
    }
};



//MEMOIZATION
class Solution {
public:
    
    int f(int index, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp){
        if(index==prices.size()){
            return 0;
        }
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        
        if(buy){
            return dp[index][buy]=max(-prices[index]+f(index+1, 0, prices, fee, dp), f(index+1, 1, prices, fee, dp));
        }
        else{
            return dp[index][buy]=max(prices[index]+f(index+1, 1, prices, fee, dp)-fee, f(index+1, 0, prices, fee, dp));
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, fee, dp);
    }
};


//DP
class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        
        for(int index=n-1;index>=0;index--){
            dp[index][1]= max(-prices[index]+dp[index+1][0], dp[index+1][1]);
            dp[index][0]= max(prices[index]+dp[index+1][1]-fee, dp[index+1][0]);
        }
        
        return dp[0][1];
    }
};



//SPACE OPTIMIZATION
class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> dp(2, 0), temp(2, 0);
        
        for(int index=n-1;index>=0;index--){
            temp[1]= max(-prices[index]+dp[0], dp[1]);
            temp[0]= max(prices[index]+dp[1]-fee, dp[0]);
            dp=temp;
        }
        
        return dp[1];
    }
};

