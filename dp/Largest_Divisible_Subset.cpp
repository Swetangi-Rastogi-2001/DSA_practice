/*https://leetcode.com/problems/largest-divisible-subset/*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n,1), hash(n,0);
        sort(nums.begin(), nums.end());
        int maxi=1;
        int lastindex=0;
        for(int index=0;index<n;index++){
            hash[index]=index;
            for(int prev=0;prev<index;prev++){
                if(nums[index]%nums[prev]==0 && dp[prev]+1>dp[index]){
                    dp[index]=dp[prev]+1;
                    hash[index]= prev;
                }
            }
            if(maxi<dp[index]){
                maxi=dp[index];
                lastindex=index;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        
        return ans;
        
    }
};
