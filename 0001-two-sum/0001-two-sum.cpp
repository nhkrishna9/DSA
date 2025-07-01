class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans{};
        unordered_map<int, int> lookup;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int rem = target - nums[i];
            if(lookup.contains(rem)){
                return {i, lookup[rem]};
            }
            else{
                lookup[nums[i]] = i;
            }
        }

        return ans;

    }
};