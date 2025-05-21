class Solution {
    void Helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& path) {

        if(nums.size()== path.size()){
            ans.push_back(path);
        }
        

        for(int i=0;i<nums.size();i++){
            if (std::find(path.begin(), path.end(), nums[i]) != path.end()) {
                continue;
            }
            path.push_back(nums[i]);
            Helper(ans, nums, path);
            path.pop_back();

        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        Helper(ans, nums, path);
        return ans;
    }

};
