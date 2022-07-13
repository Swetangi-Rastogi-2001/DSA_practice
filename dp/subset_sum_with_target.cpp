/*You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.*/


//RECURSION
bool f(int index, int target, vector<int> &arr){
    if(target==0){
        return true;
    }
    if(index==0){
        return (target==arr[0]);
    }
    
    bool nottake= f(index-1, target, arr);
    bool take= false;
    if(target>=arr[index]){
        take= f(index-1, target-arr[index], arr);
    }
    return nottake|take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    return f(n-1, k, arr);
}

//MEMOIZATION
bool f(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target==0){
        return 1;
    }
    if(index==0){
        return (target==arr[0]);
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    
    int nottake= f(index-1, target, arr, dp);
    int take= 0;
    if(target>=arr[index]){
        take= f(index-1, target-arr[index], arr, dp);
    }
    return dp[index][target]= nottake or take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    return f(n-1, k, arr, dp);
}

//DP
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool> (k+1, false));
    for(int i=0;i<n;i++){
        dp[i][0]= true;
    }
    
    dp[0][arr[0]]=true;
   
    for(int index=1;index<n;index++){
        for(int target=1;target<=k;target++){
            bool nottake= dp[index-1][target];
            bool take= false;
            if(target>=arr[index]){
                take= dp[index-1][target-arr[index]];
            }
            dp[index][target]= take|nottake;
        }
    }
    
    return dp[n-1][k];
}

//SPACE OPTIMIZATION
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> dp(k+1, false);
    dp[0]=true;
    dp[arr[0]]=true;
   
    for(int index=1;index<n;index++){
        vector<bool> temp(k+1,false);
        temp[0]=true;
        for(int target=1;target<=k;target++){
            bool nottake= dp[target];
            bool take= false;
            if(target>=arr[index]){
                take= dp[target-arr[index]];
            }
            temp[target]= take|nottake;
        }
        dp=temp;
    }
    
    return dp[k];
}
