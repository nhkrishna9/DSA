class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> prefSum(n);
        prefSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefSum[i] = nums[i] + prefSum[i-1];
        }

        int ans = 0;

        for(int i=0; i<n-1; i++){
            long lsum = prefSum[i];
            long rsum = prefSum[n-1] - prefSum[i];
            if(lsum >= rsum){
                ++ans;
            }
        }

        return ans;
        
    }
};