
/*https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?leftPanelTab=0*/

int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.
    
    vector<int> dp1(n,1), dp2(n,1);
    int maxi=1;
    for(int index=0;index<n;index++){
        for(int prev=0;prev<index;prev++){
            if(arr[index]>arr[prev]&&dp1[index]<dp1[prev]+1){
                dp1[index]=dp1[prev]+1;
            }
        }
    }
    
    for(int index=n-1;index>=0;index--){
        for(int prev= n-1;prev>index;prev--){
            if(arr[index]>arr[prev]&&dp2[index]<dp2[prev]+1){
                dp2[index]= dp2[prev]+1;
            }
        }
        maxi= max(maxi, dp1[index]+dp2[index]-1);
    }
    
    return maxi;
    
    
} 
