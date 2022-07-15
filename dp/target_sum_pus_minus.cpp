//MEMOIZATION

class Solution {
public:
    
    int f(int index, int target, vector<int>nums, vector<vector<int>> &dp){
        
        if(index==0){
            if(target==0&&nums[index]==0){
                return 2;
            }
            if(target==0||nums[0]==target)
                return 1;
            
            return 0;
        }
        
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        int nottake= f(index-1, target, nums, dp);
        int take=0;
        if(target>=nums[index])
            take = f(index-1, target - nums[index], nums, dp);
        
        return dp[index][target]=take+nottake;
    }
      
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int  d= sum-target;
        
        if(d<0||d%2!=0){
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int> (d/2 +1, -1));
        return f(nums.size()-1, d/2 , nums, dp);
    }
};



//DP
class Solution {
public:
    
    int f(int target, vector<int>nums, vector<vector<int>> &dp){
        
        
        if(nums[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
         
        if(nums[0]<=target&&nums[0]!=0){
            dp[0][nums[0]]=1;
        }
        
        for(int index=1;index<nums.size();index++){
            for(int t= 0;t<=target;t++){
                int nottake= dp[index-1][t];
                int take=0;
                if(t>=nums[index])
                    take = dp[index-1][t - nums[index]];
                
                dp[index][t]= nottake+take;
            }
        }
        
        
        
        return dp[nums.size()-1][target];
    }
      
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int  d= sum-target;
        
        if(d<0||d%2!=0){
            return 0;
        }
        vector<vector<int>> dp(nums.size(), vector<int> (d/2 +1, 0));
        return f(d/2 , nums, dp);
    }
};
