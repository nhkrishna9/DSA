class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> seen;
        int ans=0;
        for(int num:nums){
            if(seen.find(num) != seen.end()){ // More optimal
            //if(seen.count(num)){ // Less optimal
                ans = ans ^ num;
            }
            else{
                seen.insert(num);;
            }
        }
        return ans;

        /*
        int n = nums.size();
        vector<int> repeatedEleIndices;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] == nums[j]){
                    repeatedEleIndices.push_back(i);
                    break;
                }
            }
        }
        int ans =0;
        for(int i=0;i<repeatedEleIndices.size();i++){
            ans = ans ^ nums[repeatedEleIndices[i]];
        }
        return ans;
        */

        
    }
};