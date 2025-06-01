class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumToIndex;
        int sum = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Convert 0s to -1s
            sum += (nums[i] == 0) ? -1 : 1;

            if (sum == 0) {
                maxLen = i + 1;
            } else if (sumToIndex.find(sum) != sumToIndex.end()) {
                int temp = i - sumToIndex[sum];
                maxLen = max(maxLen, temp);
            } else {
                sumToIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
