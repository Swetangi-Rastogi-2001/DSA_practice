/*You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.

If N = 4 and tar = 3 and the array elements are [1, 2, 2, 3], then the number of possible ways are:
{1, 2}
{3}
{1, 2}
Hence the output will be 3.*/

//RECURSION
int f(int index, vector<int> &num, int target){
    
    if(target==0){
        return 1;
    }
    if(index==0){
        if(num[index]==target){
            return 1;
        }  
        else{
            return 0;
        }
    }
    
    int nottake= f(index-1, num, target);
    int take=0;
    if(target>=num[index]){
        take= f(index-1, num, target- num[index]);
    }
    
    return take+nottake;
}

int findWays(vector<int> &num, int tar)
{
    return f(num.size()-1,num, tar);
}


//MEMOIZATION
int f(int index, vector<int> &num, int target, vector<vector<int>> &dp){
    
    if(target==0){
        return 1;
    }
    if(index==0){
        if(num[index]==target){
            return 1;
        }  
        else{
            return 0;
        }
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    
    int nottake= f(index-1, num, target, dp);
    int take=0;
    if(target>=num[index]){
        take= f(index-1, num, target- num[index], dp);
    }
    
    return dp[index][target]=take+nottake;
}

int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int> (tar+1, -1));
    return f(num.size()-1,num, tar, dp);
}


//DP
int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int> (tar+1, 0));
    for(int i=0;i<=num.size()-1;i++){
        dp[i][0]=1;
    }
    if(num[0]<=tar){
        dp[0][num[0]]=1;
    }
    
    for(int index=1;index<num.size();index++){
        for(int target= 1;target<=tar;target++){
            int nottake= dp[index-1][target];
            int take=0;
            if(target>=num[index]){
                take= dp[index-1][target- num[index]];
            }
            dp[index][target]= nottake+take;
        }
    }    
    return dp[num.size()-1][tar];
}


//SPACE OPTIMIZATION
int findWays(vector<int> &num, int tar)
{
   vector<int> dp(tar+1, 0);

     dp[0]=1;
    
    if(num[0]<=tar){
        dp[num[0]]=1;
    }
    
    vector<int> temp(tar+1, 0);
    temp[0]=1;
    
    for(int index=1;index<num.size();index++){
        for(int target= 1;target<=tar;target++){
            int nottake= dp[target];
            int take=0;
            if(target>=num[index]){
                take= dp[target- num[index]];
            }
            temp[target]= nottake+take;
        }
        dp=temp;
    }
    
    
    return dp[tar];
}
