class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = nums[0];
        for(int i=1; i<n; i++){
            ans[i] = ans[i-1] + nums[i];
        }

        return ans;
        
    }
};