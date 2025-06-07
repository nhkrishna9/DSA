class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, const vector<int>& nums, int i){
        if(i>nums.size()){
            return;
        }
        ans.push_back(curr);
        for(int j=i; j<nums.size(); j++){
            curr.push_back(nums[j]);
            backtrack(ans, curr, nums, j+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr{};
        backtrack(ans, curr, nums, 0);
        return ans;
    }
};