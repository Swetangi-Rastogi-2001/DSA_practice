/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

//RECURSION
class Solution {
public:
    
    int f(int index, vector<int> nums){
        if(index==0){
            return nums[0];
        }
        if(index<0){
            return 0;
        }
        
        int pick= nums[index]+ f(index-2, nums);
        int notpick= 0+f(index-1, nums);
        
        return max(pick, notpick);
    }
    
    int rob(vector<int>& nums) {
        return f(nums.size()-1, nums);
    }
};


//MEMOIZATION
class Solution {
public:
    
    int f(int index, vector<int> nums, vector<int> &dp){
        if(index==0){
            return nums[0];
        }
        if(index<0){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        
        int pick= nums[index]+ f(index-2, nums, dp);
        int notpick= 0+f(index-1, nums, dp);
        
        return dp[index]=max(pick, notpick);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(nums.size()-1, nums, dp);
    }
};


//DP
class Solution {
public:
    
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1)
            pick+=dp[i-2];
            
            int notpick= dp[i-1];
            dp[i]= max(pick, notpick);
        }
        return dp[nums.size()-1];
    }
};

//SPACE OPTIMIZATION
class Solution {
public:
    
    
    int rob(vector<int>& nums) {
        
        int prev=nums[0];
        int prev2=0;
        int curr=0;
        for(int i=1;i<nums.size();i++){
            curr= prev;
            curr= max(curr, prev2+nums[i]);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
