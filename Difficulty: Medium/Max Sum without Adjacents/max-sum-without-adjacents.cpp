// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==0) return 0;
        if(n==1) return arr[0];
        //if(n==2) return arr[1];

        vector<int> ans(n);
        ans[0] = arr[0];
        ans[1] = max(arr[0], arr[1]);
        
        for(int i=2; i<n; i++){
            ans[i] = max(arr[i]+ans[i-2], ans[i-1]);
        }
        return ans[n-1];
        
    }
};