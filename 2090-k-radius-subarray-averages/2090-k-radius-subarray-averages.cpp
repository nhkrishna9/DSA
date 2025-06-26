class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2*k + 1;
        vector<int> ans(n, -1);

        if(windowSize>n){
            return ans;
        }

        vector<long long> lsum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            lsum[i + 1] = lsum[i] + nums[i];
        }
        
        for(int i=k; i<(n-k); i++){
            int left = i-k;
            int right = i+k;
            long long subArraySum = lsum[right+1] - lsum[left];
            int avg = subArraySum / windowSize;
            ans[i] = avg;
        }

        return ans;
    }
};