/*You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.

Sample Input 1:
1
4
1 2 3 4
Sample Output 1:
0
Explanation For Sample Input 1:
We can partition the given array into {2,3} and {1,4}, as this will give us the minimum possible absolute difference i.e (5-5=0) in this case.*/


int minSubsetSumDifference(vector<int>& nums, int n)
{
    int k=0;
        for(int i=0;i<nums.size();i++){
            k+=nums[i];
        }
        vector<bool> dp(k+1, false);
        dp[0]= true;
        if(nums[0]<=k && nums[0]>=0)
            dp[nums[0]]= true;
        
        vector<bool> temp(k+1, false);
             temp[0]=true;
        
        for(int index=1;index<nums.size();index++){
            for(int target=1;target<=k;target++){
                bool nottake= dp[target];
                bool take=false;
                if(target>=nums[index]){
                    take=dp[target-nums[index]];
                }
                
                temp[target]= take|nottake;
            }
            dp=temp;
        }
        
        int mini=1e9;
        for(int i=0;i<=k/2;i++){
            if(dp[i]){
                int s1= i;
                int s2= k-s1;
                mini= min(mini, abs(s1-s2));
            }
        }
        return mini;
    
}
