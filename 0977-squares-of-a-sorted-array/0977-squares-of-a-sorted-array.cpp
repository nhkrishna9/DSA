class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        vector<int> ans(n);
        int pos = n-1;
        while(left<=right){
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if(leftSquare > rightSquare){
                ans[pos--] = leftSquare;
                left++;
            }
            else{
                ans[pos--] = rightSquare;
                right--;
            }
        }

        return ans;
        
    }
};