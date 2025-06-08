class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> ans;
        unordered_map<int, int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i]) != hash.end()){
                return {hash[target-nums[i]], i};
            }
            else{
                hash[nums[i]] = i;
            }
            /*
            for(int j=i+1; j<nums.size();j++){
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
            */
        }
        return {};
    }
};