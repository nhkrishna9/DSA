class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            bool leftSmaller = (mid == 0) || (nums[mid - 1] < nums[mid]);
            bool rightSmaller = (mid == n - 1) || (nums[mid] > nums[mid + 1]);

            if(leftSmaller && rightSmaller){
                return mid;
            }
            else{
                if(mid>0 && nums[mid-1]>nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return -1;
        
    }
};