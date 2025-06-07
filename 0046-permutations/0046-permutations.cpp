class Solution {
public:
    void backtrack(vector<int>& curr, unordered_set<int>& used, vector<vector<int>>& ans, const vector<int>& nums){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(const auto & num: nums){
            if(used.find(num) == used.end()){
                curr.push_back(num);
                used.insert(num);
                backtrack(curr, used, ans, nums);
                curr.pop_back();
                used.erase(num);
            }
            /*
            if(find(curr.begin(), curr.end(), num) == curr.end()){
                curr.push_back(num);
                backtrack(curr, ans, nums);
                curr.pop_back();
            }
            */
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr{};
        unordered_set<int> used{};
        backtrack(curr, used, ans, nums);
        return ans;
    }
};