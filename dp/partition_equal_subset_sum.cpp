/*Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].*/

class Solution {
public:
    
    bool f(int n, int k, vector<int> arr){
        
        vector<bool> dp(k+1, false );
        
        dp[0]=true;
        if(arr[0]<=k){
            dp[arr[0]]=true;
        }
        
        for( int index=1; index<n;index++){
            vector<bool> temp(k+1, false);
            temp[0]=true;
            for(int target=1;target<=k;target++){
                int nottake= dp[target];
                int take=false;
                if(arr[index]<target){
                    take= dp[target- arr[index]];
                }
                temp[target]= take|nottake;
            }
            dp=temp;
        }
        return dp[k];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        if(sum%2!=0){
            return false;
        }
        
        return f(nums.size(), sum/2, nums);
    }
};
