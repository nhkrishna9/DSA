class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0, end=0;
        int ans=0;
        int flip=0;
        int n = nums.size();
        while(end<n){
            if(nums[end] == 0){
                flip++;
            }

            while(flip > k){
                if(nums[start] == 0){
                    flip--;
                }
                start++;

            }
            
            ans = max(ans, end-start+1);
            end++;

        }

        return ans;
        
    }
};