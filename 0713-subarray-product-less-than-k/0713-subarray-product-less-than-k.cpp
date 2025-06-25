class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<1 || k<=1){
            return 0;
        }
        int left = 0, curr = 1, ans=0;
        for(int right=0; right<n; right++){
            curr *= nums[right];
            while(curr >= k){
                curr /= nums[left];
                left++;
            }
            ans += right-left+1;
        }

        return ans;
    }
};