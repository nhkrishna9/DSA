class Solution {
public:
    void Helper(vector<vector<int>>& ans, vector<int>& nums, int index, vector<int>& subset) {

        ans.push_back(subset);

        for(int i=index;i<nums.size();i++){
            subset.push_back(nums[i]);
            Helper(ans, nums, i+1, subset);
            subset.pop_back();

        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        Helper(ans, nums, 0, subset);
        return ans;
    }
};
