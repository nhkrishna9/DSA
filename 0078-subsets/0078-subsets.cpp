class Solution {
public:
    void Helper(vector<vector<int>>& ans, vector<int>& nums, int index, vector<int> subset) {
        if (index == nums.size()) {
            ans.push_back(subset);
            return;
        }
        // include nums[index]
        subset.push_back(nums[index]);
        Helper(ans, nums, index + 1, subset);
        
        // exclude nums[index]
        subset.pop_back();  // backtrack
        Helper(ans, nums, index + 1, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        Helper(ans, nums, 0, subset);
        return ans;
    }
};
