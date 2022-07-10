/*The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"*/


class Solution {
public:
    string getPermutation(int n, int k) {
         int fact=1;
        vector<int> num;
        for(int i=1;i<n;i++){
            fact=fact*i;
            num.push_back(i);
        }
        num.push_back(n);
        string ans="";
        k=k-1;
        while(true){
            ans= ans+ to_string(num[k/fact]);
            num.erase(num.begin()+(k/fact));
            
            if(num.size()==0){
                break;
            }
            
            k=k%fact;
            fact=fact/num.size();
        }
        return ans;
    }
};
