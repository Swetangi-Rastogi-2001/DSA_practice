void helper(vector<int> num, int index, int n, int sum, vector<int> &ans){
    if(index==n){
        ans.push_back(sum);
        return;
    }
    helper(num, index+1, n, sum+num[index], ans);
    helper(num, index+1, n, sum, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    helper(num, 0, num.size(), 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
