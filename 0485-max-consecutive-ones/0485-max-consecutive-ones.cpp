class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, tmp=0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                tmp++;
                ans = max(ans, tmp);
            }
            else{
                tmp = 0;
            }
        }        
        return ans;
    }
};