class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1; // To handle subarrays that start from index 0
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k];
            }
            prefixSumFreq[sum]++;
        }
        return count;
    }
};
