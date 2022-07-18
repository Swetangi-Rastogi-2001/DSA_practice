
/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/*/

//DP
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy){
                        dp[i][buy][cap]= max(-prices[i]+dp[i+1][0][cap], dp[i+1][1][cap]);
                    }
                    else{
                        dp[i][buy][cap]= max(prices[i]+dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                    
                }
            }
        }
        
        return dp[0][1][k];
    }
};

//4 VARIABLES
//MEMOIZATION
class Solution {
public:
    int f(int index, int transaction, vector<int> &prices, int n, int k, vector<vector<int>> &dp){
        if(index==n||transaction==2*k){
            return 0;
        }
        if( dp[index][transaction]!=-1){
            return  dp[index][transaction];
        }
        
        if(transaction%2==0){
            return dp[index][transaction]=max(-prices[index]+f(index+1, transaction+1, prices, n, k, dp), 0+ f(index+1, transaction, prices, n, k, dp));
        }
        else{
            return  dp[index][transaction]=max(prices[index]+f(index+1, transaction+1, prices, n, k, dp), 0+ f(index+1, transaction, prices, n, k, dp));

        }
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return f(0, 0, prices, prices.size(), k, dp);
    }
};



//DP
class Solution {
public:

    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        for(int index=n-1;index>=0;index--){
            for(int transaction= 2*k-1;transaction>=0;transaction--){
                if(transaction%2==0){
                    dp[index][transaction]=max(-prices[index]+dp[index+1][transaction+1], 0+ dp[index+1][ transaction]);
        }
                else{
                    dp[index][transaction]=max(prices[index]+dp[index+1][transaction+1], 0+ dp[index+1][transaction]);

        }
            }
        }
        return dp[0][ 0];
    }
};


//SPACE OPTIMIZATION
class Solution {
public:

    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(2*k+1, 0), temp(2*k+1, 0);
        for(int index=n-1;index>=0;index--){
            for(int transaction= 2*k-1;transaction>=0;transaction--){
                if(transaction%2==0){
                    temp[transaction]=max(-prices[index]+dp[transaction+1], 0+ dp[ transaction]);
                }
                else{
                    temp[transaction]=max(prices[index]+dp[transaction+1], 0+ dp[transaction]);
                }
            }
            dp=temp;
        }
        return dp[0];
    }
};
