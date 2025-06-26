class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minPrefixSum = 0;
        int curr = 0;
        for(int num:nums){
            curr += num;
            minPrefixSum = min(minPrefixSum, curr);
            
        }
        return 1-minPrefixSum;
        
    }
};