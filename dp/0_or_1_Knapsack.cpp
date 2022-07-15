/*A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.*/



//RECURSION
int f(int index, int W, vector<int> wt, vector<int> val){
    if(index==0){
        if(wt[0]<=W){
            return val[0];
        }
        else{
            return 0;
        }
    }
    
    int nottake= 0+ f(index-1, W, wt, val);
    int take= -1e9;
    if(wt[index]<=W){
        take= val[index]+f(index-1, W-wt[index], wt, val);
    }
    
    return max(nottake, take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    return f(n-1, maxWeight, weight, value);
}


//MEMOIZATION
int f(int index, int W, vector<int> wt, vector<int> val, vector<vector<int>> &dp){
    if(index==0){
        if(wt[0]<=W){
            return val[0];
        }
        else{
            return 0;
        }
    }
    
    if(dp[index][W]!=-1){
        return dp[index][W];
    }
    
    int nottake= 0+ f(index-1, W, wt, val, dp);
    int take= -1e9;
    if(wt[index]<=W){
        take= val[index]+f(index-1, W-wt[index], wt, val, dp);
    }
    
    return dp[index][W]=max(nottake, take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{    vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
    return f(n-1, maxWeight, weight, value, dp);
}


//DP
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{    vector<vector<int>> dp(n, vector<int> (W+1, 0));
 
     for(int i=wt[0];i<=W;i++){
         dp[0][i]=val[0];
     }
 
     for(int index=1;index<n;index++){
         for(int mW= 0; mW<=W; mW++){
                int nottake= 0+ dp[index-1][mW];
                int take= -1e9;
                if(wt[index]<=mW){
                    take= val[index]+dp[index-1][mW-wt[index]];
                }
             dp[index][mW]= max(take, nottake);
         }
     }
 
    return dp[n-1][W];
}


//SPACE OPTIMIZATION - 1
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{    vector<int> dp(W+1, 0), temp(W+1, 0);
 
     for(int i=wt[0];i<=W;i++){
         dp[i]=val[0];
     }
 
     for(int index=1;index<n;index++){
         for(int mW= 0; mW<=W; mW++){
                int nottake= 0+ dp[mW];
                int take= -1e9;
                if(wt[index]<=mW){
                    take= val[index]+dp[mW-wt[index]];
                }
             temp[mW]= max(take, nottake);
         }
         dp=temp;
     }
 
    return dp[W];
}


//SPACE OPTIMIZATION - II
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{    vector<int> dp(W+1, 0);
 
     for(int i=wt[0];i<=W;i++){
         dp[i]=val[0];
     }
 
     for(int index=1;index<n;index++){
         for(int mW= W; mW>=0; mW--){
                int nottake= 0+ dp[mW];
                int take= -1e9;
                if(wt[index]<=mW){
                    take= val[index]+dp[mW-wt[index]];
                }
             dp[mW]= max(take, nottake);
         }
     }
 
    return dp[W];
}
