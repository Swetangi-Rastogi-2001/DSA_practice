
/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/*/


//RECURSION
class Solution {
public:
    
    int f(int index, int buy, int cap, vector<int> &prices){
        if(index==prices.size()||cap==0){
            return 0;
        }
    
        if(buy){
            return max(-prices[index]+f(index+1, 0, cap, prices), 0+ f(index+1, 1, cap, prices));
        }
        else{
            return max(prices[index]+f(index+1, 1, cap-1, prices), f(index+1, 0, cap, prices));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return f(0,1,2,prices);
    }
};


//MEMOIZATION
class Solution {
public:
    
    int f(int index, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(index==prices.size()||cap==0){
            return 0;
        }
        
        if(dp[index][buy][cap]!=-1){
            return dp[index][buy][cap];
        }
    
        if(buy){
            return dp[index][buy][cap]= max(-prices[index]+f(index+1, 0, cap, prices, dp), 0+ f(index+1, 1, cap, prices, dp));
        }
        else{
            return dp[index][buy][cap]= max(prices[index]+f(index+1, 1, cap-1, prices, dp), f(index+1, 0, cap, prices, dp));
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0,1,2,prices, dp);
    }
};



//DP
class Solution {
public:
        
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=1;j++){
                dp[i][j][0]=0;
            }
        }
        
        for(int j=0;j<=1;j++){
            for(int k=0;k<=2;k++){
                dp[n][j][k]=0;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j==1)
                        dp[i][j][k]= max(-prices[i]+dp[i+1][0][k], 0+ dp[i+1][ 1][k]);
                    else
                        dp[i][j][k]= max(prices[i]+dp[i+1][1][k-1], 0+ dp[i+1][0][k]);
                                                
                }
            }
        }
        
        
        return dp[0][1][2];
    }
};

//SPACE OPTIMIZATION
class Solution {
public:
        
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(2, vector<int>(3, 0)), temp(2, vector<int>(3, 0));
        
        
            for(int j=0;j<=1;j++){
                dp[j][0]=0;
            }
        
        
        for(int j=0;j<=1;j++){
            for(int k=0;k<=2;k++){
                dp[j][k]=0;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    if(j==1)
                        temp[j][k]= max(-prices[i]+dp[0][k], 0+ dp[1][k]);
                    else
                        temp[j][k]= max(prices[i]+dp[1][k-1], 0+ dp[0][k]);
                                                
                }
            }
            dp=temp;
        }
        
        
        return dp[1][2];
    }
};
