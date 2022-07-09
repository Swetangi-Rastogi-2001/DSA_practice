class Solution {
public:
    void helper(vector<int> nums, int index, int n, vector<int> temp, vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int i=index;i<n;i++){
            if(i!=index&&nums[i]==nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            helper(nums, i+1, n, temp , ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(nums, 0, nums.size(), temp, ans );
        return ans;
    }
};
