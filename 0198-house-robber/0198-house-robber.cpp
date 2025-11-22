class Solution {
public:
    int rob(vector<int>& nums) {
        int numHouses = nums.size();
        if(numHouses ==0){
            return 0;
        }
        if(numHouses == 1){
            return nums[0];
        }

        vector<int> maxMoneyRobbed(numHouses);
        maxMoneyRobbed[0] = nums[0];
        maxMoneyRobbed[1] = max(nums[0], nums[1]);

        for(int i=2; i<numHouses; i++){
            maxMoneyRobbed[i] = max(maxMoneyRobbed[i-1], maxMoneyRobbed[i-2]+nums[i]);
        }
        
        return maxMoneyRobbed[numHouses-1];
    }
};