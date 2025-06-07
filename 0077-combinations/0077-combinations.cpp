class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& curr, int i, int n, int k){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }

        for(int j=i;j<=n;j++){
            curr.push_back(j);
            backtrack(ans, curr, j+1, n, k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr{};
        backtrack(ans, curr, 1, n, k);
        return ans;
    }
};